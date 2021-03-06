#pragma once
///////////////////////////////////////////////////////////////////////
// Executive.h - class used to execute all operations in project1    //
// ver 1.0                                                           //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019         //
///////////////////////////////////////////////////////////////////////
/*
*  Package Operations:
*  -------------------
*  This package provides a class, Executive, class used to execute all 
*  operations in project1.
*  Currently, it can implements function of finding all target files,
*  converting file into html file, displaying, and html file in target
*  browser.
*
*
*  Required Files:
*  ---------------
*  Executive.h Executive.cpp
*  Convert.h						 // Convert class
*  Display.h						 // Display class
*  DirExplorerN.h					 // DirExplorerN class
*  StringUtilities.h                 // Title function
*  CodeUtilities.h                   // ProcessCmdLine class
*
*  Maintenance History:
*  --------------------
*  ver 1.0 : 31 Jan 2019
*  - first release
*/

#include <string>
#include "../Convert/Convert.h"
#include "../Display/Display.h"
#include "../DirExplorer-Naive/DirExplorerN.h"
#include "../Utilities/StringUtilities/StringUtilities.h"
#include "../Utilities/CodeUtilities/CodeUtilities.h"

using namespace Utilities;
using namespace FileSystem;

class Executive
{
public:
	Executive() {};
	Executive(int argc, char* argv[]);
	~Executive() {};

	// function for Project1 that convert .cpp and .h files into .html files
	// and display them on browser
	int findFiles(int argc, char* argv[]);
	void convertFiles(std::string save_path);
	void displayHtml(std::string save_path);

private:
	Convert conv;
	Display display;
	std::vector<std::string> filePaths;
	std::vector<std::string> fileNames;
};

// Executive constructor
Executive::Executive(int argc, char* argv[]) {
	int status = findFiles(argc, argv);
	if (status == 1) {
		std::cout << std::endl << "Press key to exist";
		getchar();
		exit(EXIT_FAILURE);
	}
}

// using DirExploreN to find all target files with their paths
int Executive::findFiles(int argc, char* argv[]) {
	if (argc < 4) {
		std::cout << "\n";
		std::cout << "error: miss arguments from command line\n\n";
		return 1;
	}
	display.setBrowser(argv[1]);

	ProcessCmdLine pcl(argc, argv);
	if (pcl.parseError())
	{
		pcl.usage();
		std::cout << "\n";
		std::cout << "error: cannot parse arguments from command line\n\n";
		return 1;
	}

	DirExplorerN de(pcl.path());
	for (auto patt : pcl.patterns())
	{
		de.addPattern(patt);
	}

	if (pcl.hasOption('s'))
	{
		de.recurse();
	}

	de.search();
	de.showStats();

	filePaths = de.getFilePath();
	fileNames = de.getFileName();

	if (filePaths.size() < 1 || fileNames.size() < 1) {
		std::cout << "\n";
		std::cout << "error: cannot find any files\n\n";
		return 1;
	}

	return 0;
}

// convert all .cpp and .h file into .html file 
// and store them in convertedPages folder
void Executive::convertFiles(std::string save_path) {
	for (size_t i = 0; i < filePaths.size(); i++) {
		conv.convert2html(filePaths[i], save_path);
	}
}


// Display all .html files
void Executive::displayHtml(std::string save_path) {
	std::string fpath = FileSystem::Path::getFullFileSpec(save_path);
	for (std::string file : fileNames) {
		std::string htmlFile = fpath + file + ".html";
		display.showHtml(htmlFile);
	}
}
