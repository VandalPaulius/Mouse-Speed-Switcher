#include "Mouse_speed.h"

bool Mouse_speed::Get_current_mouse_speed() {
	bool query_result = false;
	int mouse_speed = 0, *mouse_speed_address = &mouse_speed;
	bool x;
	x = SystemParametersInfo(SPI_GETMOUSESPEED, 0, mouse_speed_address, 0);
	/*cout << "\n\nPrevious Mouse Speed was : " << mouse_speed;
	cout << "\nSystemParametersInfo return status for SPI_GETMOUSESPEED : " << x;*/
	return query_result;
}

void Mouse_speed::Set_mouse_speed(int mouse_speed) {
	SystemParametersInfo(SPI_SETMOUSESPEED,
		0,
		(LPVOID)mouse_speed,
		SPIF_UPDATEINIFILE ||
		SPIF_SENDCHANGE ||
		SPIF_SENDWININICHANGE);
	return;
}