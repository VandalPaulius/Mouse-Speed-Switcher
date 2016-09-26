#include "Standart_includes.h"

bool _started_program = false;
bool _exit_program = false;
bool _speed_switch_info_flag_updated = false;
bool _command_flag_updated = false;

_Speed_switch _speed_switch = {
	10, // int speed_1
	20, // int speed_2
	"speed_1", // string speed_1_name
	"speed_2" // string speed_2_name
};

_Command_flag _command_flag = {
	false, // bool exit
	false, // bool help
	false, // bool speed_info_updated
	false, // bool switch_speed_1
	false, // bool switch_speed_2
	false // bool info_speed
};

