#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "Standart_includes.h"

extern bool _started_program;
extern bool _exit_program;
extern bool _speed_switch_info_flag_updated;
extern bool _command_flag_updated;

typedef struct {
	int speed_1;
	int speed_2;
	string speed_1_name;
	string speed_2_name;
} _Speed_switch;
extern _Speed_switch _speed_switch;

typedef struct {
	bool exit;
	bool help;
	/*bool speed_1 = false;
	bool speed_2 = false;
	bool name_speed_1 = false;
	bool name_speed_2 = false;*/
	bool speed_info_updated;
	bool switch_speed_1;
	bool switch_speed_2;
	bool info_speed;
} _Command_flag;
extern _Command_flag _command_flag;

#endif