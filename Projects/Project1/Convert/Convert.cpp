/////////////////////////////////////////////////////////////////////
// Convert.cpp - Convert input file into html file                 //
// ver 1.0                                                         //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////

#include "Convert.h"

int main() 
{
	Convert conv;
	conv.convert2html("../TestFiles/Proj1Helper.h", "../convertedPages/");
}