#include "Thread_functions_hotkey.h"


void Hotkey::Hotkey_driver() {
	int hotkey_id_1 = 1;
	int hotkey_id_2 = 2;
	int first_hotkey_1_key = 0x0008; // Left "Windows 
	int first_hotkey_2_key = 0x61; // numeric '1'
	int second_hotkey_1_key = 0x0008;
	int second_hotkey_2_key = 0x62; // numeric '2'
	RegisterHotKey(
		NULL,
		hotkey_id_1,
		first_hotkey_1_key | MOD_NOREPEAT,
		first_hotkey_2_key);
	RegisterHotKey(
		NULL,
		hotkey_id_2,
		second_hotkey_1_key | MOD_NOREPEAT,
		second_hotkey_2_key);
	MSG msg = { 0 };
	if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE) != 0) { // "if" is for function to complete and return after a message
		switch (msg.message) {
		case WM_HOTKEY:
			if (msg.wParam == hotkey_id_1)
			{
				//printf("1 Pressed\n");
				command_flag.switch_speed_1 = true;
				command_flag_global_needs_update = true;

			}
			else if (msg.wParam == hotkey_id_2)
			{
				//printf("2 Pressed\n");
				command_flag.switch_speed_2 = true;
				command_flag_global_needs_update = true;
			}
			break;
		default:
			break;
		}
		if (_exit_program == true) {
			return;
		}
	}
	return;
}

void Hotkey::Flag_update_local_to_global() { // must be mutex'ed
	_command_flag.switch_speed_1 = command_flag.switch_speed_1;
	command_flag.switch_speed_1 = false; // probably not needed as we reset local flags afterwards
	_command_flag.switch_speed_2 = command_flag.switch_speed_2;
	command_flag.switch_speed_2 = false; // probably not needed as we reset local flags afterwards
	return;
}

void Hotkey::Flag_reset_local() {
	memset(&command_flag, false, sizeof(command_flag));
	return;
}