#include "Thread_functions_main.h"

// -------- FUNCTIONS --------
// -------- MAIN LOGIC --------
void Main::Startup_routine() {
	if (_started_program == false) {
		cout << "Mouse Speed Switcher by Vandal Paulius" << endl;
		cout << "Type 'help' for more info" << endl;
		_started_program = true;
	}
	return;
}

void Main::Datafile_save() {
	ofstream file;//("data");
	file.open("data", ios::out | ios::trunc);
	if (file.is_open()) {
		file << "speed_1" << endl;
		file << speed_switch.speed_1 << endl;
		file << "speed_1_name" << endl;
		file << speed_switch.speed_1_name << endl;

		file << "speed_2" << endl;
		file << speed_switch.speed_2 << endl;
		file << "speed_2_name" << endl;
		file << speed_switch.speed_2_name << endl;
		file.close();
	}
	else {
		cout << "ERROR! Could not save data to file." << endl;
	}
	return;
}

void Main::Datafile_read() {
	string data_from_file;
	ifstream file("data");
	if (file.is_open()) {
		int variable_selector = 0;
		bool read_done = false;
		//bool read_success = false;
		while (getline(file, data_from_file)) {
			if (variable_selector > 0) {
				// _speed_1 
				if (variable_selector == 1) {
					speed_switch.speed_1 = stoi(data_from_file);
					variable_selector = 0;
				}
				// _speed_1_name
				if (variable_selector == 2) {
					speed_switch.speed_1_name = data_from_file;
					variable_selector = 0;
				}
				// _speed_2
				if (variable_selector == 3) {
					speed_switch.speed_2 = stoi(data_from_file);
					variable_selector = 0;
				}
				// _speed_2_name 
				if (variable_selector == 4) {
					speed_switch.speed_2_name = data_from_file;
					variable_selector = 0;
					read_done = true;
					//read_success = false;
					break;
				}
			}
			else {
				if (data_from_file == "speed_1") variable_selector = 1;
				if (data_from_file == "speed_1_name") variable_selector = 2;
				if (data_from_file == "speed_2") variable_selector = 3;
				if (data_from_file == "speed_2_name") variable_selector = 4;
			}
		}
		if (read_done == false) {
			cout << "ERROR! Data read failed!" << endl;
		}
	}
	else {
		cout << "ERROR! Could not open datafile." << endl;
	}
	file.close();
	return;
}

void Main::Speed_switch_update_global_to_local() {
	speed_switch.speed_1 = _speed_switch.speed_1;
	speed_switch.speed_2 = _speed_switch.speed_2;
	speed_switch.speed_1_name = _speed_switch.speed_1_name;
	speed_switch.speed_2_name = _speed_switch.speed_2_name;
	return;
}

void Main::Speed_switch_update_local_to_global() {
	_speed_switch.speed_1 = speed_switch.speed_1;
	_speed_switch.speed_2 = speed_switch.speed_2;
	_speed_switch.speed_1_name = speed_switch.speed_1_name;
	_speed_switch.speed_2_name = speed_switch.speed_2_name;
	return;
}

void Main::Flag_update_global_to_local() {
	command_flag.exit = _command_flag.exit;
	command_flag.help = _command_flag.help;
	command_flag.speed_info_updated = _command_flag.speed_info_updated;
	command_flag.switch_speed_1 = _command_flag.switch_speed_1;
	command_flag.switch_speed_2 = _command_flag.switch_speed_2;
	command_flag.info_speed = _command_flag.info_speed;
	return;
}

void Main::Flag_reset_global() {
	memset(&_command_flag, false, sizeof(_command_flag));
	return;
}

void Main::Flag_reset_local() {
	memset(&command_flag, false, sizeof(command_flag));
	return;
}

void Main::Main_driver() {
	if (command_flag.exit == true) Exit();
	if (command_flag.help == true) Help();
	if (command_flag.speed_info_updated == true) Datafile_save(); // save all mouse speed info data to datafile
	if (command_flag.switch_speed_1 == true) Switch_speed_1();
	if (command_flag.switch_speed_2 == true) Switch_speed_2();
	if (command_flag.info_speed == true) Speed_info();
	return;
}

void Main::Exit() {
	_exit_program = true;
	return;
}

// -------- MOUSE SPEED CONTROL FUNCTIONS --------
void Main::Help() {
	printf("\nMouse Speed Switcher Help:\n");
	printf("ATENTION! When writing input no whitespaces are allowed.\n Instead use '_' or '-'\n");
	/* All console function list */
	printf("\nAvailable function list : \n");
	printf("type 'help' - to get available function list\n");
	printf("type 'exit' - to exit application\n");
	printf("type 'set_speed1' - to set 1st mouse speed\n");
	printf("type 'set_speed2' - to set 2nd mouse speed\n");
	printf("type 'set_speed1_name' - to set 1st mouse speed name\n");
	printf("type 'set_speed2_name' - to set 2nd mouse speed name\n");
	printf("type 'speed1' - to activate 1st mouse speed\n");
	printf("type 'speed2' - to activate 2nd mouse speed\n");
	printf("type 'speed_info' - to get current speed settings\n");
	printf("\n");
}

void Main::Switch_speed_1() {
	Mouse_speed mouse_speed;
	mouse_speed.Set_mouse_speed(speed_switch.speed_1);
	if (speed_switch.speed_1_name == "speed_1") {
		cout << "Mouse speed_1 enabled: " << speed_switch.speed_1 << endl;
	}
	else {
		cout << speed_switch.speed_1_name << " (speed_1) enabled: " << speed_switch.speed_1 << endl;
	}
	return;
}

void Main::Switch_speed_2() {
	Mouse_speed mouse_speed;
	mouse_speed.Set_mouse_speed(speed_switch.speed_2);
	if (speed_switch.speed_2_name == "speed_2") {
		cout << "Mouse speed_2 enabled: " << speed_switch.speed_2 << endl;
	}
	else {
		cout << speed_switch.speed_2_name << " (speed_2) enabled: " << speed_switch.speed_2 << endl;
	}
	return;
}

void Main::Speed_info() {
	cout << "\nSpeed info:\n";
	if (speed_switch.speed_1_name == "speed_1") {
		cout << speed_switch.speed_1_name << ": " << speed_switch.speed_1 << endl;
	}
	else {
		cout << speed_switch.speed_1_name << " (speed_1): " << speed_switch.speed_1 << endl;
	}
	if (speed_switch.speed_2_name == "speed_2") {
		cout << speed_switch.speed_2_name << ": " << speed_switch.speed_2 << endl;
	}
	else {
		cout << speed_switch.speed_2_name << " (speed_2): " << speed_switch.speed_2 << endl;
	}
	return;
}