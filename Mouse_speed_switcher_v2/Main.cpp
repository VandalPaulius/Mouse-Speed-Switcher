//Mouse Speed Switcher v2
#include "Standart_includes.h"
std::mutex mtx;
Standart_plus_functions std_p;
#include "Thread_functions_main.h"
#include "Thread_functions_user_input.h"
#include "Thread_functions_hotkey.h"

// -------- THREAD FUNCTION DECLARATIONS --------
void User_input_thread_2();
void Hotkey_thread_3();

// -------- MAIN --------
void main() {
	Main main;
	main.Startup_routine();
	main.Datafile_read();
	main.Speed_switch_update_local_to_global();
	//main.Speed_switch_update_global_to_local();
	// thread creation ALWAYS goes after main data initialization
	thread thread1(User_input_thread_2);
	thread thread2(Hotkey_thread_3);
	while (_exit_program == false) {
		// main program logic {start}
		mtx.lock();
		if (_speed_switch_info_flag_updated == true) {
			main.Speed_switch_update_global_to_local();
			_speed_switch_info_flag_updated = false;
		}
		mtx.unlock();
		if (_command_flag_updated == true) {
			mtx.lock();
			main.Flag_update_global_to_local();
			main.Flag_reset_global();
			_command_flag_updated = false;
			mtx.unlock();
		}
		// all other program behaviour here
		main.Main_driver();
		main.Flag_reset_local();
		// main program logic {end}
		Sleep(100); // program active time interval (no need to run all the time)
	}
	cout << "Exiting Mouse Speed Switcher." << endl;
	thread1.join();
	thread2.join();
	main.Datafile_save();
	Sleep(100); // shows an exit message
	/*getchar();
	getchar();*/
	return;
}

// -------- THREAD FUNCTION DEFINITIONS --------
void User_input_thread_2() {
	User_input user_input;
	user_input.Speed_switch_update_global_to_local();
	while (_exit_program == false) {
		// main thread logic {start}
		user_input.User_input_driver();
		if (user_input.speed_switch_info_need_update == true) {
			mtx.lock();
			user_input.Speed_switch_update_local_to_global();
			_speed_switch_info_flag_updated = true;
			user_input.speed_switch_info_need_update = false;
			mtx.unlock();
		}
		if (user_input.command_flag_global_needs_update == true) {
			mtx.lock();
			user_input.Flag_update_local_to_global();
			user_input.Flag_reset_local();
			_command_flag_updated = true;
			user_input.command_flag_global_needs_update = false;
			mtx.unlock();
			//cout << "updating command_flag" << endl;
		}
		Sleep(100); // without this sleep thread does not exit. WHY?
		// somewhy this thread needs to run a bit of time to exit. NEEDS RESEARCH
		// main thread logic {end}
	}
	return;
}

void Hotkey_thread_3() {
	Hotkey hotkey;
	while (_exit_program == false) {
		// main thread logic {start}
		hotkey.Hotkey_driver(); // somewhy it never goes out of it
		if (hotkey.command_flag_global_needs_update == true) {
			mtx.lock();
			hotkey.Flag_update_local_to_global();
			hotkey.Flag_reset_local();
			_command_flag_updated = true;
			hotkey.command_flag_global_needs_update = false;
			mtx.unlock();
		}
		Sleep(100);
		// main thread logic {end}
	}
	return;
}