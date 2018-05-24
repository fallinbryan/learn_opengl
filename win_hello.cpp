#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glfw3.h>


/*
hInstance - is a handle to your applications instance, where an instance 
can be considered to be a single run of your application. The instance 
is used by windows as a reference to your application for event handling,
message processing, and various other duties.
hPrevInstance - is always NULL. 
lpCmdLine - is a pointer string that is used to hold any command-line
arguments that may have been specified when the application began.  
For example, if the user opened the Run application and typed myapp.exe
myparameter 1, then lpCmdLine would be myparameter 1.
nShowCMD - is the parameter that determines how your application's window
will be displayed once it begins executing.
*/



int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)  {
	
	MessageBox(NULL, "\tHello World!", "Windows App", MB_OK);
	return 0;
}

/*

Message Handler Loop
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

hwnd - Only important if you have several windows of the same class open
at one time. This is used to determine which window hwnd pointed to before 
deciding on an action.
message - The actual message identifier that WndProc will be handling.
wParam and lParam - Extensions of the message parameter. Used to give 
more information and point to specifics that message cannot convey on its own.


*/