#ifndef THREAD_FUNCTIONS_MAIN_H
#define THREAD_FUNCTIONS_MAIN_H

#include "Standart_includes.h"
#include "Mouse_speed.h"

class Main {
	// -------- VARIABLES --------
	private:
		struct Speed_switch {
			int speed_1 = 10;
			int speed_2 = 10;
			string speed_1_name = "speed_1";
			string speed_2_name = "speed_2";
		};
		Speed_switch speed_switch;

		struct Command_flag {
			bool exit = false;
			bool help = false;
			bool speed_info_updated = false;
			bool switch_speed_1 = false;
			bool switch_speed_2 = false;
			bool info_speed = false;
		};
		Command_flag command_flag;

	// -------- FUNCTIONS --------
	public:
		// Main logic functions

		void Startup_routine();
		void Datafile_read();
		void Datafile_save();
		void Speed_switch_update_global_to_local();
		void Speed_switch_update_local_to_global();
		void Flag_update_global_to_local();
		void Flag_reset_global();
		void Flag_reset_local();
		void Main_driver();
	private:
		void Exit();
		// Mouse speed control functions
		void Help();
		void Switch_speed_1();
		void Switch_speed_2();
		void Speed_info();
};

#endif // THREAD_FUNCTIONS_MAIN_H

//Set_mouse_speed