#ifndef THREAD_FUNCTIONS_HOTKEY_H
#define THREAD_FUNCTIONS_HOTKEY_H

#include "Standart_includes.h"



class Hotkey {
	// -------- VARIABLES --------
	public:
		bool command_flag_global_needs_update = false;
	private:
		struct Command_flag {
			bool switch_speed_1 = false;
			bool switch_speed_2 = false;
		};
		Command_flag command_flag;

	// -------- FUNCTIONS --------
	public:
		void Hotkey_driver();
		void Flag_update_local_to_global();
		void Flag_reset_local();
};

#endif // THREAD_FUNCTIONS_HOTKEY_H