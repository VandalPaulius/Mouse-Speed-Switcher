#include "Standart_plus_functions.h"

int Constrain(int value_to_constrain, int min_value, int max_value) {
	if (value_to_constrain <= min_value) value_to_constrain = min_value;
	if (value_to_constrain >= max_value) value_to_constrain = max_value;
	return value_to_constrain;
}