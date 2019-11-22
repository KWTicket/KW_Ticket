#include "Airplane.h"

using namespace std;

Guest join(vector<Guest> DB);
Guest login(vector<Guest> DB);
Airplane addAirplane();
Flight addFlight(Airplane air);
void Show_Airplane_Status(vector <Airplane> Check_air);
void Show_Flight_Status(vector <Flight> Check_flight);
string cur_date();
int cur_hour();
int com_date(Flight DB);

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
						if (Airplane_DB.empty()) {
							cout << "Airplane Empty!" << endl;
							continue;
						}
						Show_Airplane_Status(Airplane_DB);
						cout << "Choose Airplane that you want to Add Flight : ";
						cin >> k;
						Flight_DB.push_back(addFlight(Airplane_DB[k - 1]));
					}
					else if (b == 3) {
						if (Flight_DB.empty()) {
							cout << "Flight Empty!" << endl;
							continue;
						}
						Show_Flight_Status(Flight_DB);
						int airNum;
						cout << "Choose Flight that you want to Check Seats : ";
						cin >> airNum;
						Flight_DB[airNum-1].viewSit();
						char command;
						while (1) {
							cout << "If you want to check seats, input 'c', or if you want to quit, input 'q' : ";
							cin >> command;
							if (command == 'c') {
								int c, r;
								cout << "Input row and column : ";
								cin >> r >> c;
								if (Flight_DB[airNum - 1].sit[r - 1][c - 1].getPass() != 0) {
									Flight_DB[airNum - 1].sit[r - 1][c - 1].test();
								}
								else
									cout << "Empty Sit!" << endl;
							}
							if (command == 'q')
								break;
						}
					}
					else if (b == 4) {
						cout << "Good Bye, Admin!" << endl;
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
						if (Flight_DB.empty()) {
							cout << "Flight Empty!" << endl;
							continue;
						}
						Show_Flight_Status(Flight_DB);
						cout << "Choose Airplane that you want to Use : ";
						cin >> k;
						int a = com_date(Flight_DB[k - 1]);
						if (a == 0) {
							char s1[20];
							strcpy_s(s1, sizeof(s1), Flight_DB[k - 1].getDt().c_str());
							char* dd = NULL;
							char* ptr = strtok_s(s1, ":", &dd);
							if ((atoi(ptr) - cur_hour() >= (1 - cur_hour())) && (atoi(ptr) - cur_hour() <= 1)) {
								cout << "reservation no! hour error!\n";
								break;
							}
							else
								Flight_DB[k - 1].reservation(pass);
						}
						else if (a == 1) {
							cout << "date error! you can't reserve this flight\n";
							break;
						}
						else {
							Flight_DB[k - 1].reservation(pass);
						}
					}
					if (c == 3) {
						if (Flight_DB.empty()) {
							cout << "Flight Empty!" << endl;
							continue;
						}
						cout << pass.getName() << "'s information : " << endl;
						for (int i = 0; i < Flight_DB.size(); i++) {
							Flight_DB[i].checkReserve(pass);
						}
					}
					if (c == 4) {
						int k = 0, row = 0, col = 0;
						if (Flight_DB.empty()) {
							cout << "Flight Empty!" << endl;
							continue;
						}
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
					if (c == 5) {
						cout << "Good Bye," << User.getName() << '!' << endl;
						break;
					}
				}
			}
		}
		else if (a == 3) {
			cout << "Finish Program!" << endl;
			return 0;
		}
	}
}
