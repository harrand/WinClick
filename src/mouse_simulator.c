#include <windows.h>
#include "mouse_simulator.h"

void simulate_mouse_down(unsigned int x, unsigned int y, mouse_button button)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dx = x * (65536.0f / GetSystemMetrics(SM_CXSCREEN));
	input.mi.dy = y * (65536.0f / GetSystemMetrics(SM_CYSCREEN));
	switch(button)
	{
		case LEFT_BUTTON:
			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			break;
		case RIGHT_BUTTON:
			input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			break;
	}
	SendInput(1, &input, sizeof(input));
}

void simulate_mouse_up(unsigned int x, unsigned int y, mouse_button button)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.dx = x * (65536.0f / GetSystemMetrics(SM_CXSCREEN));
	input.mi.dy = y * (65536.0f / GetSystemMetrics(SM_CYSCREEN));
	switch(button)
	{
		case LEFT_BUTTON:
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			break;
		case RIGHT_BUTTON:
			input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			break;
	}
	SendInput(1, &input, sizeof(input));
}