#include <stdio.h>
#include <ctime>
#include <string>
#include "Airplane.h"

using namespace std;

string cur_date() {
	time_t now = time(NULL);
	struct tm date;
	localtime_s(&date, &now);
	string d1 = to_string(date.tm_year + 1900);
	string d2 = to_string(date.tm_mon + 1);
	string d3 = to_string(date.tm_mday);
	string cur_date = d1 + d2 + d3;
	return cur_date;
}

int cur_hour() {
	time_t now = time(NULL);
	struct tm date;
	localtime_s(&date, &now);
	int cur_hour = date.tm_hour;
	return cur_hour;
}

int com_date(Flight DB) {
	int cur_y = atoi(cur_date().substr(0, 3).c_str());
	int cur_m = atoi(cur_date().substr(4, 5).c_str());
	int cur_d = atoi(cur_date().substr(6, 7).c_str());
	int com_y = atoi(DB.getDay().substr(0, 3).c_str());
	int com_m = atoi(DB.getDay().substr(4, 5).c_str());
	int com_d = atoi(DB.getDay().substr(6, 7).c_str());
	if (cur_y > com_y) {
		return 1/*예약 X, 지난 거*/;
	}
	else if (cur_y < com_y) {
		return 2/*예약 O, 아직 안 지난거,무조건 되는거*/;
	}
	else if (cur_y == com_y) { //월, 날짜 비교
		if (cur_m > com_m) {
			return 1/*예약 X, 지난 거*/;
		}
		else if (cur_m < com_y) {
			return 2/*예약 O, 아직 안 지난거,무조건 되는거*/;
		}
		else if (cur_m == com_m) {//날짜 비교
			if (cur_d > com_d) {
				return 1/*예약 X, 지난 거*/;
			}
			else if (cur_d < com_d) {
				return 2/*예약 O, 아직 안 지난거,무조건 되는거*/;
			}
			else if (cur_d == cur_d) {
				return 0;//날짜 현재날짜랑 동일
			}
		}
	}
}