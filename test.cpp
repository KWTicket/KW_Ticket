#include "Airplane.h"

Guest join();
Guest login(vector<Guest> DB);
Airplane addAirplane();
Flight addFlight(Airplane air);
void Show_Airplane_Status(vector <Airplane> Check_air);

int main() {

	vector<Airplane> Airplane_DB;
	vector<Flight> Flight_DB;
	vector<Guest> Guest_DB;
	Guest Admin("admin", "1q2w3e4r!", "admin", "admin", "admin");
	Guest_DB.push_back(Admin);
	Guest User;

	int a, b;
	while (1) {
		cout << "WELCOME! \n\n 1. SIGN UP 2. SIGN IN 3. EXIT" << endl;
		cin >> a;
		if (a == 1)
			Guest_DB.push_back(join());
		else if (a == 2)
			User = login(Guest_DB);
		if (User.getName() == "admin") {
			while (1) {
				cout << "1. 비행기 추가, 2. 비행편 추가 3.나가기" << endl;
				cin >> b;
				if (b == 1)
					Airplane_DB.push_back(addAirplane());
				else if (b == 2) {
					int k = 0;
					Show_Airplane_Status(Airplane_DB);
					cout << "Choose airplane that you want to add : ";
					cin >> k;
					Flight_DB.push_back(addFlight(Airplane_DB[k - 1]));
				}
				else if (b == 3)
					break;
				}

			}
		}
	}