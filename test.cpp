#include "Airplane.h"
#include <windows.h>

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
	vector<Flight> Search_Flight_DB;
	vector<Guest> Guest_DB;
	Guest Admin("admin", "1q2w3e4r!", "admin", "admin", "admin");
	Guest_DB.push_back(Admin);
	Guest User;
	Passenger pass;

	int a = 0, b = 0, c = 0;
	while (1) {
		for (int i = 0; i < Flight_DB.size(); i++) {
			int cn;
			cn = com_date(Flight_DB[i]);
			if (cn == 1) {
				Flight_DB.erase(Flight_DB.begin() + i);
			}
		}
		system("cls");
		cout << "" << endl;
		cout << " ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
		cout << " ☆ *       *         *   *         *     *      * ☆" << endl;
		cout << " ☆  *    *     *      *      *       *     *     *☆" << endl;
		cout << " ☆*   *   *  !! WELCOME TO KW-TICKET !!  *   *   *☆" << endl;
		cout << " ☆*  *     *        *       *    *    *   *     * ☆" << endl;
		cout << " ☆*     *   *     *         *      *       *     *☆" << endl;
		cout << " ☆  *   *      *     *   *      *     *   *      *☆" << endl;
		cout << " ☆ *  * ⓒ 2019. KW-TICKET All rights reserved. * ☆" << endl;
		cout << " ☆*   *    *       *       *      *       *     * ☆" << endl;
		cout << " ☆      *       *     *        *        *         ☆" << endl;
		cout << " ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
		cout << "" << endl;
		cout << "   1. Join" << endl;
		cout << "   2. Login" << endl;
		cout << "   3. Exit" << endl;
		cout << "" << endl;
		cout << "   >> ";

		cin >> a;
		if (a == 1)
			Guest_DB.push_back(join(Guest_DB));
		else if (a == 2) {
			User = login(Guest_DB);
			if (User.getName() == "admin") {
				while (1) {
					system("cls");
					cout << "" << endl;
					cout << " [ Mode :: Administrator ]" << endl;
					cout << "" << endl;
					cout << "   1. Add Airplane\n   2. Add Flight\n   3. Check Seats\n   4. Exit\n";
					cout << "" << endl;
					cout << "   >> ";
					cin >> b;
					if (b == 1)
						Airplane_DB.push_back(addAirplane());
					else if (b == 2) {
						int k = 0;
						if (Airplane_DB.empty()) {
							cout << "" << endl;
							cout << "   !!!! There's no plane !!!!\n ";
							cout << "   Please add the plane :-(" << endl;
							Sleep(2000);
							continue;
						}
						system("cls");
						Show_Airplane_Status(Airplane_DB);
						cout << " Choose Airplane that you want to Add Flight : ";
						cin >> k;
						Flight_DB.push_back(addFlight(Airplane_DB[k - 1]));
					}
					else if (b == 3) {
						if (Flight_DB.empty()) {
							cout << "" << endl;
							cout << "   !!!! There's no flight plan !!!!\n ";
							cout << "   Please add the flight plan :-(" << endl;
							continue;
						}
						system("cls");
						Show_Flight_Status(Flight_DB);
						cout << "" << endl;
						int airNum;
						cout << "   Choose Flight that you want to Check Seats : ";
						cin >> airNum;
						cout << "" << endl;
						Flight_DB[airNum - 1].viewSit();
						char command;
						while (1) {
							cout << "" << endl;
							cout << "   If you want to check seats, input 'c', or if you want to quit, input 'q' : ";
							cin >> command;
							if (command == 'c') {
								int c, r;
								cout << "" << endl;
								cout << "   Please input row : ";
								cin >> r;
								cout << "   Please input column : ";
								cin >> c;
								cout << "" << endl;
								if (Flight_DB[airNum - 1].sit[r - 1][c - 1].getPass() != 0) {
									Flight_DB[airNum - 1].sit[r - 1][c - 1].test();
								}
								else {
									cout << "" << endl;
									cout << "   !!!! This seat is empty !!!!\n ";
									cout << "   Please select again. :-(" << endl;
									cout << "" << endl;
								}
							}
							if (command == 'q')
								break;
						}
					}
					else if (b == 4) {
						cout << "" << endl;
						cout << "   Good Bye, Admin!" << endl;
						cout << "" << endl;
						Sleep(3000);
						break;
					}
				}
			}
			else if (User.getName() == "Null")
				continue;

			else if (User.getName() != "admin") {
				while (1) {
					system("cls");
					cout << "" << endl;
					cout << "[ Member ] ==================================================================" << endl;
					cout << "∥                                                                          ∥" << endl;
					cout << "∥    ★ Event ★                                                           ∥" << endl;
					cout << "∥     Flights to Cebu from Incheon are 20% off.                            ∥" << endl;
					cout << "∥                                                                          ∥" << endl;
					cout << "∥     ★ Notice ★                                                         ∥" << endl;
					cout << "∥     The flight from Incheon to Melbourne was temporarily suspended.      ∥" << endl;
					cout << "∥                                                                          ∥" << endl;
					cout << "∥     For more information, call 02-XXXX-XXXX.                             ∥" << endl;
					cout << "∥     It's available 24 hours a day.                                       ∥" << endl;
					cout << "∥                                                                          ∥" << endl;
					cout << "=============================================================================" << endl;
					cout << "" << endl;
					cout << "   1. Register PassortNumber\n   2. Reservation\n   3. Check Reservation\n   4. Cancel Reservation\n   5. Exit\n";
					cout << "" << endl;
					cout << "   >> ";
					cin >> c;
					if (c == 1) {
						system("cls");
						int passNum;
						cout << "" << endl;
						cout << "[ Register Passport Number ] ========================" << endl;
						cout << "∥                                                  ∥" << endl;
						cout << "∥    ★ Please enter the correct number ★         ∥" << endl;
						cout << "∥                                                  ∥" << endl;
						cout << "∥     ★ When you withdraw from membership, ★     ∥" << endl;
						cout << "∥     ★ the information will be discarded ★      ∥" << endl;
						cout << "∥                                                  ∥" << endl;
						cout << "=====================================================" << endl;
						cout << "" << endl;
						cout << "   Passport Number : ";
						cin >> passNum;
						pass = Passenger(User, passNum);
					}
					else if (c == 2) {
						system("cls");
						string dep, arr;
						int k = 0;
						cout << "[ Reservation ] ====================================================" << endl;
						cout << "∥                                                                ∥" << endl;
						cout << "∥       Choose your departure place.                             ∥" << endl;
						cout << "∥                                                                ∥" << endl;
						cout << "∥ - INCHEON       - GIMPO   - JEJU     - HANEDA      - NARITA    ∥\n";
						cout << "∥ - KANSAI        - TAIPEI  - BEIJING  - SHANGHAI    - GUANGZHOU ∥\n";
						cout << "∥ - HONGKONG      - MACAU   - DANANG   - CEBU        - BORACAY   ∥\n";
						cout << "∥ - KOTAKINABALU  - LA      - MIAMI    - WASHINGTON  - TORONTO   ∥\n";
						cout << "∥ - VANCOUVER     - LONDON  - PARIS    - BERLIN      - WEIN      ∥\n";
						cout << "∥ - BUDAPEST      - PRAHA                                        ∥\n";
						cout << "∥                                                                ∥" << endl;
						cout << "====================================================================" << endl;
						cout << "" << endl;
						cout << "   Departure : ";
						cin >> dep;
						cout << "" << endl;
						cout << "" << endl;
						cout << "[ Reservation ] ====================================================" << endl;
						cout << "∥                                                                ∥" << endl;
						cout << "∥       Choose your arrival place.                               ∥" << endl;
						cout << "∥                                                                ∥" << endl;
						cout << "∥ - INCHEON       - GIMPO   - JEJU     - HANEDA      - NARITA    ∥\n";
						cout << "∥ - KANSAI        - TAIPEI  - BEIJING  - SHANGHAI    - GUANGZHOU ∥\n";
						cout << "∥ - HONGKONG      - MACAU   - DANANG   - CEBU        - BORACAY   ∥\n";
						cout << "∥ - KOTAKINABALU  - LA      - MIAMI    - WASHINGTON  - TORONTO   ∥\n";
						cout << "∥ - VANCOUVER     - LONDON  - PARIS    - BERLIN      - WEIN      ∥\n";
						cout << "∥ - BUDAPEST      - PRAHA                                        ∥\n";
						cout << "∥                                                                ∥" << endl;
						cout << "====================================================================" << endl;
						cout << "" << endl;
						cout << "   Arrival : ";
						cin >> arr;
						for (int i = 0; i < Flight_DB.size(); i++) {
							if (Flight_DB[i].getDep() == dep && Flight_DB[i].getArr() == arr)
								Search_Flight_DB.push_back(Flight_DB[i]);
						}
						if (Search_Flight_DB.empty()) {
							system("cls");
							cout << "" << endl;
							cout << "   !!!! There are no flights !!!!\n";
							cout << "   Sorry. Please search for another flight. :-(" << endl;
							Sleep(2000);
							continue;
						}
						system("cls");
						Show_Flight_Status(Search_Flight_DB);

						cout << "" << endl;
						cout << "   Please select a flight to board : ";
						cin >> k;

						int d = com_date(Search_Flight_DB[k - 1]);
						if (d == 0) {
							Search_Flight_DB[k - 1].reservation(pass);
						}
						else if (d == 1) {
							system("cls");
							cout << "" << endl;
							cout << "   !!!! You cannot book a flight on that date !!!!\n";
							cout << "   Sorry. Please select a different date. :-(" << endl;
							Sleep(2000);
							continue;
						}
						else {
							Search_Flight_DB[k - 1].reservation(pass);
						}
						Search_Flight_DB.clear();
					}
					if (c == 3) {
						if (Flight_DB.empty()) {
							system("cls");
							cout << "" << endl;
							cout << "   !!!! There is no flight you have reserved !!!!\n";
							cout << "   Sorry. Please make a reservation first. :-(" << endl;
							Sleep(2000);
							continue;
						}
						cout << "" << endl;
						cout << "   " <<pass.getName() << "'s flight plan : " << endl;
						for (int i = 0; i < Flight_DB.size(); i++) {
							Flight_DB[i].checkReserve(pass);
						}
					}
					if (c == 4) {
						int i = 0, k = 0, row = 0, col = 0;
						for (i = 0; i < Flight_DB.size(); i++) {
							for (row = 0; row < Flight_DB[i].getAir().getRow(); row++) {
								for (col = 0; col < Flight_DB[i].getAir().getCol(); col++) {
									if (Flight_DB[i].sit[row][col].getID() == pass.getID())
										Search_Flight_DB.push_back(Flight_DB[i]);
								}
							}
							Search_Flight_DB[i].checkReserve(pass);
						}
						if (Search_Flight_DB.empty()) {
							cout << "   No reserve data!" << endl;
							continue;
						}

						cout << "" << endl;
						cout << "   Choose Airplane that you want to cancel : " << endl;
						cout << "" << endl;
						cin >> k;
						Search_Flight_DB[k - 1].cancelReserve(pass);
						Search_Flight_DB[k - 1].viewSit();
						Search_Flight_DB.clear();
					}
					if (c == 5) {
						cout << "" << endl;
						cout << "   Good Bye," << User.getName() << '!' << endl;
						cout << "" << endl;
						break;
					}
				}
			}
		}
		else if (a == 3) {
			system("cls");
			cout << "" << endl;
			cout << " ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
			cout << " ☆ *       *         *   *         *     *      * ☆" << endl;
			cout << " ☆  *    *     *      *      *       *     *     *☆" << endl;
			cout << " ☆*   *   *     * !!! GOODBYE !!! *   *    * *   *☆" << endl;
			cout << " ☆*  *     *        *       *    *    *   *     * ☆" << endl;
			cout << " ☆*     *   *     *         *      *       *     *☆" << endl;
			cout << " ☆  *   *      *     *   *      *     *   *      *☆" << endl;
			cout << " ☆ *  * ⓒ 2019. KW-TICKET All rights reserved. * ☆" << endl;
			cout << " ☆*   *    *       *       *      *       *     * ☆" << endl;
			cout << " ☆      *       *     *        *        *         ☆" << endl;
			cout << " ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
			cout << "" << endl;
			Sleep(2000);
			return 0;
		}
	}
}
