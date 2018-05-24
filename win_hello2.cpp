// g++ <fname>.cpp -o <fname>.exe -lgdi32


// Trim Win Fat
#define WIN32_LEAN_AND_MEAN

#pragma comment(linker, "/subsystem:windows")

#include "stdafx.h"
#include <windows.h>



// Event handler
LRESULT CALLBACK WndProc(HWND window_handle, UINT message, WPARAM wParam, LPARAM lParam) {
	
	PAINTSTRUCT paintStruct;
	HDC device_context;	// Device context
	char hello_string[] = "Hello, World";  //diplay text
	
	//the event processor
	switch(message) {
		
		// window is being created
		case WM_CREATE:
			return 0;
			break;
			
		// window is closing
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
			break;
			
		// window is being painted / updated
		case WM_PAINT:
			device_context = BeginPaint(window_handle, &paintStruct);
				SetTextColor(device_context, COLORREF(0x00FF0000));
				TextOut(device_context, 150, 150, hello_string, sizeof(hello_string)-1);
			EndPaint(window_handle, &paintStruct);
			return 0;
			break;
			
		default:
			break;
	}
	return (DefWindowProc(window_handle, message, wParam, lParam ));
	
}

// MAIN
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	WNDCLASSEX winClass;
	HWND window_handle;
	MSG	message;
	bool isDone;
	
	/****************************************************************
	****		          WINDOWS CLASS SET UP                   *******
	*****************************************************************/
	
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.style = CS_HREDRAW | CS_VREDRAW;
	winClass.lpfnWndProc = WndProc;					// long pointer to function windows process - points to event handler function
	winClass.cbClsExtra = NULL;
	winClass.cbWndExtra = NULL;
	winClass.hInstance = hInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winClass.lpszMenuName = NULL;
	winClass.lpszClassName = "MyClass";
	winClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	
	
	/****************************************************************
	****		          WINDOWS CLASS Registration             *******
	*****************************************************************/
	
	if (!RegisterClassEx(&winClass)) {  //register the winClass 
		return 0;		// if it fails, bail
	}
	
	
	/****************************************************************
	****		          WINDOWS CREATION                       *******
	*****************************************************************/
	
	window_handle = CreateWindowEx(
						NULL,			//extended style
						"MyClass",		//class name
						"A Win App",	//application Name
						WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU,  // window style
						100, 100,		// x,y  window coords
						400, 400,		// width, height
						NULL,			// handle to parent window
						NULL,			// handle to menu
						hInstance,		// application instance id
						NULL			// extra parameters
					);
	
	if(!window_handle) {
		return 0;  //failed to create the window
	}
	
	isDone = false;
	
	
	/****************************************************************
	****		          MESSAGE LOOP                           *******
	*****************************************************************/
	
	while(!isDone) {
		
		PeekMessage(&message, NULL, NULL, NULL, PM_REMOVE);
		
		if( message.message == WM_QUIT) {
			isDone = true;
		} else {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		
	}
	return message.wParam;
}
