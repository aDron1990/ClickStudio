#include "main.h"
#include "Clicker.h"
#include "GUI.h"

#include <memory>

LRESULT CALLBACK KeyHoookProc(int code, WPARAM wp, LPARAM lp)
{
	if (code >= 0)
	{
		if (wp == WM_KEYUP)
		{
			KBDLLHOOKSTRUCT* k = (KBDLLHOOKSTRUCT*)lp;
			if (k->vkCode == 'Q' && GetKeyState(VK_RCONTROL)) run = false;
			if (k->vkCode == 'E' && GetKeyState(VK_RCONTROL)) clicker = !clicker;
			if (k->vkCode == 'H' && GetKeyState(VK_RCONTROL)) gui->swapShowMode();
		}
	}
	return CallNextHookEx(0, code, wp, lp);
}

int main()
{
#if 1
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
	HHOOK keyhook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyHoookProc, 0, 0);

	gui = new GUI;
	gui->show();

	MSG msg = { 0 };
	while (run)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}


	}

	delete gui;
	MessageBox(0, "ClickStudio завершил свою работу", "Уведомление", MB_OK);
	return 0;
}