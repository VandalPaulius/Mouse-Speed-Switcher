#ifndef MOUSE_SPEED_H
#define MOUSE_SPEED_H

#include "Standart_includes.h"

class Mouse_speed {
	// -------- VARIABLES -------- 
	private:
		int Previous_mouse_speed = 0;
	// -------- FUNCTIONS -------- 
	public:
		
		bool Get_current_mouse_speed();
		void Set_mouse_speed(int);
};

#endif // MOUSE_SPEED_sH