#include "Airplane.h"

using namespace std;

Guest join(vector<Guest> DB);
Guest login(vector<Guest> DB);
Airplane addAirplane();
Flight addFlight(Airplane air);
void Show_Airplane_Status(vector <Airplane> Check_air);
void Show_Flight_Status(vector <Flight> Check_flight);

int main() {

	vector<Airplane> Airplane_DB;
	vector<Flight> Flight_DB;
	vector<Guest> Guest_DB;
	Guest Admin("admin", "1q2w3e4r!", "admin", "admin", "admin");
	Guest_DB.push_back(Admin);
	Guest User;
	Passenger pass;

	int a = 0, b = 0, c = 0;
	while (1) {
		cout << "WELCOME! \n\n 1. Join   2. Login   3. Exit \n";
		cin >> a;
		if (a == 1)
			Guest_DB.push_back(join(Guest_DB));
		else if (a == 2) {
			User = login(Guest_DB);
			if (User.getName() == "admin") {
				while (1) {
					cout << "1. Add Airplane   2. Add Flight   3. Check Seats	4. Exit\n";
					cin >> b;
					if (b == 1)
						Airplane_DB.push_back(addAirplane());
					else if (b == 2) {
						int k = 0;
						Show_Airplane_Status(Airplane_DB);
						cout << "Choose Airplane that you want to Add Flight : ";
						cin >> k;
						Flight_DB.push_back(addFlight(Airplane_DB[k - 1]));
					}
					else if (b == 3) {
						Show_Flight_Status(Flight_DB);
						int airNum;
						cout << "Choose Airplane that you want to Check Seats : ";
						cin >> airNum;
						Flight_DB[airNum-1].viewSit();
						int c, r;
						cout << "Input row and column : ";
						cin >> r >> c;
						if (Flight_DB[airNum - 1].sit[r-1][c-1].getPass() != 0) {
							Flight_DB[airNum - 1].sit[r-1][c-1].test();
						}
						else
							cout << "Empty Sit!" << endl;
					}
					else if (b == 4) {
						Show_Flight_Status(Flight_DB);
						break;
					}
				}
			}
			else if (User.getName() != "admin") {
				while (1) {
					cout << "1. Register PassortNumber   2. Reservation   3. Check Reservation   4. Cancel Reservation	5. Exit\n";
					cin >> c;
					if (c == 1) {
						int passNum;
						cout << "Input Passport Number : ";
						cin >> passNum;
						pass = Passenger(User, passNum);
					}
					else if (c == 2) {
						int k = 0;
						Show_Flight_Status(Flight_DB);
						cout << "Choose Airplane that you want to Use : ";
						cin >> k;
						//시간 비교//
						time_t now = time(NULL);
						struct tm date;
						localtime_s(&date, &now);
						string d1 = to_string(date.tm_year + 1900);
						string d2 = to_string(date.tm_mon + 1);
						string d3 = to_string(date.tm_mday);
						string da = d1 + d2 + d3;
						int hour = date.tm_hour;
						if (Flight_DB[k - 1].getDay() == da) {
							char s1[20];
							strcpy_s(s1, sizeof(s1), Flight_DB[k - 1].getAt().c_str());
							char* dd = NULL;
							char* ptr = strtok_s(s1, ":",&dd);
							if ((atoi(ptr)-hour >= (1-hour)) && (atoi(ptr) - hour <= 1)) {
								cout << "reservation no! hour error!\n";
								break;
							}
							else 
								Flight_DB[k - 1].reservation(pass);
						}
						else if (Flight_DB[k - 1].getDay() != da) {
							cout << "date error! you can't reserve this flight\n";
							break;
						}
					}
					if (c == 3) {
						for (int i = 0; i < Flight_DB.size(); i++) {
							Flight_DB[i].checkReserve(pass);
						}
					}
					if (c == 4) {
						int k = 0, row = 0, col = 0;
						Show_Flight_Status(Flight_DB);
						cout << "Choose Airplane that you want to Use : ";
						cin >> k;
						cout << "Choose Seat that you want to Cancel.\n";
						Flight_DB[k - 1].viewSit();
						cout << "Row : ";
						cin >> row;
						cout << "Column : ";
						cin >> col;
						cout << "Cancelation Complete!" << endl;
						Flight_DB[k - 1].cancelReserve(User, row, col, pass);
						Flight_DB[k - 1].viewSit();
					}
					if (c == 5)
						break;
				}
			}
		}
		else if (a == 3) {
			cout << "Finish Program!" << endl;
			return 0;
		}
	}
}
