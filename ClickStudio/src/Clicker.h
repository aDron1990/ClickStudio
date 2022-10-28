#pragma once

#include <Windows.h>
#include <thread>
#include <iostream>
#include <ctime>
#include <mutex>

class Clicker
{
private:

	std::thread clickThread_;
	unsigned long lastClick = 0;
	unsigned int clickRate_;
	bool do_clicks_ = false;

	void click_loop_();

public:

	Clicker(int cps = 10);
	
	void setCPS(int cps);
	void operator=(bool newState);
	operator bool();
};