#include "GUI.h"
#include "main.h"

#include <string>
#include <sstream>

LRESULT CALLBACK WndProc(HWND window, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC dc = BeginPaint(window, &ps);
		HBRUSH brush = CreateSolidBrush(0xffffff);
		FillRect(dc, &ps.rcPaint, brush);
		DeleteObject(brush);
		EndPaint(window, &ps);
	}
	return 0;

	case WM_CLOSE:
	{
		((GUI*)GetWindowLongPtr(window, GWLP_USERDATA))->hide();
	}
	return 0;
	case WM_COMMAND:
		switch (wp)
		{
		case 0:
			std::stringstream ss;
			char buf[8];
			GetWindowText(gui->cpsEdit_, buf, 7);
			ss << buf;
			int cps;
			ss >> cps;
			clicker.setCPS(cps);
			return 0;
		}


	};
	return DefWindowProc(window, msg, wp, lp);
}

void GUI::registerClass_()
{
	static bool r = false;
	if (!r)
	{
		wcex_.cbSize = sizeof(wcex_);
		wcex_.lpfnWndProc = WndProc;
		wcex_.lpszClassName = "ClickStudioWindow";
		wcex_.hInstance = GetModuleHandle(0);
		
		if (!RegisterClassEx(&wcex_)) std::terminate();
		r = true;
	}
}

GUI::GUI()
{
	registerClass_();

	window_ = CreateWindowEx(0, wcex_.lpszClassName, "ClickStudio", WS_OVERLAPPEDWINDOW, 200, 200, 500, 500, 0, 0, wcex_.hInstance, 0);
	if (window_ == 0) std::terminate();
	SetWindowLongPtr(window_, GWLP_USERDATA, (LONG_PTR)this);

	cpsEdit_ = CreateWindow("edit", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 0, 0, 100, 20, window_, 0, wcex_.hInstance, 0);
	setButton_ = CreateWindow("button", "set", WS_BORDER | WS_CHILD | WS_VISIBLE, 0, 21, 100, 20, window_, 0, wcex_.hInstance, 0);
}

GUI::~GUI()
{
	DestroyWindow(window_);
	UnregisterClass(wcex_.lpszClassName, wcex_.hInstance);
}

void GUI::show()
{
	ShowWindow(window_, SW_SHOWNORMAL);
	showMode_ = true;
}

void GUI::hide()
{
	ShowWindow(window_, SW_HIDE);
	showMode_ = false;
}

void GUI::swapShowMode()
{
	showMode_ = !showMode_;
	showMode_ ? show() : hide();
}