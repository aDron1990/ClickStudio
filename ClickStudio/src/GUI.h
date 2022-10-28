#pragma once

#include <Windows.h>
#include <thread>
#include <iostream>
#include <ctime>
#include <mutex>

class GUI
{
	friend LRESULT CALLBACK WndProc(HWND window, UINT msg, WPARAM wp, LPARAM lp);

private:

	HWND window_;

	HWND setButton_;
	HWND cpsEdit_;

	WNDCLASSEX wcex_ = { 0 };
	bool showMode_ = false;

	void registerClass_();

public:

	GUI();
	~GUI();

	void hide();
	void show();
	void swapShowMode();
};