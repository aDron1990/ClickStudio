#include "Clicker.h"
#include "main.h"

void Clicker::click_loop_()
{
	while (run)
	{
		if (do_clicks_ && clock() - lastClick >= 1000 / clickRate_)
		{
			lastClick = clock();
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
};

Clicker::Clicker(int cps) : clickRate_(std::move(cps))
{
	clickThread_ = std::thread(&Clicker::click_loop_, this);
	clickThread_.detach();
}

void Clicker::setCPS(int cps)
{
	clickRate_ = std::move(cps);
}

void Clicker::operator=(bool newState)
{
	do_clicks_ = newState;
}

Clicker::operator bool()
{
	return do_clicks_;
}