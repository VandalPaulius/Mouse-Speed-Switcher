#include "Thread_functions_user_input.h"

void User_input::Speed_switch_update_global_to_local() {
	speed_switch.speed_1 = _speed_switch.speed_1;
	speed_switch.speed_2 = _speed_switch.speed_2;
	speed_switch.speed_1_name = _speed_switch.speed_1_name;
	speed_switch.speed_2_name = _speed_switch.speed_2_name;
	return;
}

void User_input::Speed_switch_update_local_to_global() {
	_speed_switch.speed_1 = speed_switch.speed_1;
	_speed_switch.speed_2 = speed_switch.speed_2;
	_speed_switch.speed_1_name = speed_switch.speed_1_name;
	_speed_switch.speed_2_name = speed_switch.speed_2_name;
	return;
}

void User_input::Flag_update_local_to_global() { // must be mutex'ed
	_command_flag.exit = command_flag.exit;
	_command_flag.help = command_flag.help;
	_command_flag.speed_info_updated = command_flag.speed_info_updated;
	_command_flag.switch_speed_1 = command_flag.switch_speed_1;
	command_flag.switch_speed_1 = false; // probably not needed as we reset local flags afterwards
	_command_flag.switch_speed_2 = command_flag.switch_speed_2;
	command_flag.switch_speed_2 = false; // probably not needed as we reset local flags afterwards
	_command_flag.info_speed = command_flag.info_speed;
	return;
}

void User_input::Flag_reset_local() {
	memset(&command_flag, false, sizeof(command_flag));
	return;
}

void User_input::Set_speed_1() {
	cout << "Please input desired 1st mouse speed.\nFrom 0 to 20." << endl;
	cin >> speed_switch.speed_1;
	//speed_switch.speed_1 = Constrain(speed_switch.speed_1, 0, 20);
	cout << "Speed1 set to: " << speed_switch.speed_1 << endl;
	command_flag.speed_info_updated = true;
	speed_switch_info_need_update = true;
return;
}

void User_input::Set_speed_2() {
	cout << "Please input desired 2nd mouse speed.\nFrom 0 to 20." << endl;
	cin >> speed_switch.speed_2;
	//speed_switch.speed_2 = Standart_plus_functions::Constrain(speed_switch.speed_2, 0, 20);
	cout << "Speed2 set to: " << speed_switch.speed_2 << endl;
	command_flag.speed_info_updated = true;
	speed_switch_info_need_update = true;
	return;
}

void User_input::Set_name_speed_1() {
	cout << "Please input 1st mouse speed name:" << endl;
	cin >> speed_switch.speed_1_name;
	cout << "Speed1 name set." << endl;
	command_flag.speed_info_updated = true;
	speed_switch_info_need_update = true;
	return;
}

void User_input::Set_name_speed_2() {
	cout << "Please input 2nd mouse speed name:" << endl;
	cin >> speed_switch.speed_2_name;
	cout << "Speed2 name set." << endl;
	command_flag.speed_info_updated = true;
	speed_switch_info_need_update = true;
	return;
}

void User_input::User_input_driver() {
	string user_input;
	cin >> user_input;
	if (user_input == "exit") { command_flag.exit = true; command_flag_global_needs_update = true; }
	if (user_input == "help") { command_flag.help = true; command_flag_global_needs_update = true; }
	if (user_input == "set_speed1") { Set_speed_1(); command_flag_global_needs_update = true; }
	if (user_input == "set_speed2") { Set_speed_2(); command_flag_global_needs_update = true; }
	if (user_input == "set_speed1_name") { Set_name_speed_1(); command_flag_global_needs_update = true; }
	if (user_input == "set_speed2_name") { Set_name_speed_2(); command_flag_global_needs_update = true; }
	if (user_input == "speed1") { command_flag.switch_speed_1 = true; command_flag_global_needs_update = true; }
	if (user_input == "speed2") { command_flag.switch_speed_2 = true; command_flag_global_needs_update = true; }
	if (user_input == "speed_info") { command_flag.info_speed = true; command_flag_global_needs_update = true; }
	user_input = ""; // user_input variable reset
	return;
}