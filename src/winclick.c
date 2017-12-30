#include "mouse_simulator.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi
#include <limits.h>

#define MINIMUM_ARGUMENTS 3
#define MAXIMUM_ARGUMENTS 

/**
* Expected run parameters:
* winclick.exe <"left"|"right"> <clicks_per_second> [maximum_clicks] [xpos] [ypos]
* Thus valid number of params = 1 + (2->5) = 3->6
*/
int main(int argc, char** argv)
{
	if(argc < MINIMUM_ARGUMENTS || argc > MAXIMUM_ARGUMENTS)
	{
		fprintf(stderr, "Error: Invalid number of arguments (%d). Expected between %d and %d", argc, MINIMUM_ARGUMENTS, MAXIMUM_ARGUMENTS);
		return -1;
	}
	const char* mouse_button_type = argv[1];
	mouse_button button;
	if(strcmp(mouse_button_type, "left") == 0)
		button = LEFT_BUTTON;
	else if(strcmp(mouse_button_type, "right") == 0)
		button = RIGHT_BUTTON;
	else
	{
		fprintf(stderr, "Invalid mouse button argument %s, should be \"left\" or \"right\"", mouse_button_type);
	}
	int clicks_per_second = atoi(argv[2]);
	int maximum_clicks = INT_MAX;
	if(argc >= 4) // does contain [maximum_clicks]
	{
		maximum_clicks = atoi(argv[3]);
	}
	int xpos = 0, ypos = 0;
	if(argc >= 6)
	{
		xpos = atoi(argv[4]);
		ypos = atoi(argv[5]);
	}
	else
	{
		POINT mouse_position;
		BOOL result = GetCursorPos(&mouse_position);
		if(result)
		{
			xpos = mouse_position.x;
			ypos = mouse_position.y;
		}
		else
			fprintf(stderr, "Failed to get cursor position. Defaulting to [0,0].");
	}
	
	// Successfully retrieved all input data. Now simulate the clicks.
	unsigned int click_counter;
	for(click_counter = 0; click_counter < maximum_clicks; click_counter++)
	{
		double delay = 1 / (clicks_per_second * 1000.0f);
		simulate_mouse_down(xpos, ypos, button);
		Sleep(delay / 2.0f);
		simulate_mouse_up(xpos, ypos, button);
		Sleep(delay / 2.0f);
		printf("Click!\n");
	}
	return 0;
}