#pragma once

#include "Clicker.h"
#include "GUI.h"

static Clicker clicker;
GUI* gui;
static bool run = true;

LRESULT CALLBACK KeyHoookProc(int code, WPARAM wp, LPARAM lp);

int main();