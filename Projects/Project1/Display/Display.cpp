///////////////////////////////////////////////////////////////////////
// Display.cpp - class used to display html in browser               //
// ver 1.0                                                           //
// Wentian Bai, CSE687 - Object Oriented Design, Spring 2019         //
///////////////////////////////////////////////////////////////////////

#include "Display.h"

#ifdef TEST_DISPLAY
int main()
{
	Display player;
	//player.setBrowser("c:/Program Files (x86)/Google/Chrome/Application/chrome.exe");
	player.setBrowser("C:\\Program Files\\Mozilla Firefox\\firefox.exe");
	for (int i = 0; i < 2; i++) {
		player.showHtml("C:\\Users\\wbai1\\OneDrive\\Desktop\\CSE687\\Projects\\Project1\\TestFiles\\test.html");
	}
	return 0;
}
#endif // TEST_DISPLAY
