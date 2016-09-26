#ifndef THREAD_FUNCTIONS_USER_INPUT_H
#define THREAD_FUNCTIONS_USER_INPUT_H

#include "Standart_includes.h"



class User_input {
	// -------- VARIABLES --------
	public:
		bool speed_switch_info_need_update = false;
		bool command_flag_global_needs_update = false;

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
		void Speed_switch_update_global_to_local();
		void Speed_switch_update_local_to_global();
		void Flag_update_local_to_global();
		void Flag_reset_local();
		void Set_speed_1();
		void Set_speed_2();
		void Set_name_speed_1();
		void Set_name_speed_2();
		void User_input_driver();
};

#endif // THREAD_FUNCTIONS_USER_INPUT_H