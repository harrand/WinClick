typedef enum {
	LEFT_BUTTON,
	RIGHT_BUTTON,
} mouse_button;

void simulate_mouse_down(unsigned int x, unsigned int y, mouse_button button);
void simulate_mouse_up(unsigned int x, unsigned int y, mouse_button button);
