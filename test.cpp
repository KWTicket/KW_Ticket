#include "Airplane.h"

Guest join();
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

	int a=0, b=0, c=0;
	while (1) {
		cout << "WELCOME! \n\n 1. 회원가입   2. 로그인   3. 나가기" << endl;
		cin >> a;
		if (a == 1)
			Guest_DB.push_back(join());
		else if (a == 2) {
			User = login(Guest_DB);
			if (User.getName() == "admin") {
				while (1) {
					cout << "1. 비행기 추가   2. 비행편 추가   3. 나가기" << endl;
					cin >> b;
					if (b == 1)
						Airplane_DB.push_back(addAirplane());
					else if (b == 2) {
						int k = 0;
						Show_Airplane_Status(Airplane_DB);
						cout << "추가하려는 비행편의 비행기를 선택하세요 : ";
						cin >> k;
						Flight_DB.push_back(addFlight(Airplane_DB[k - 1]));
					}
					else if (b == 3) {
						Show_Flight_Status(Flight_DB);
						break;
					}
				}
			}
			else if (User.getName() != "admin") {
				while (1) {
					cout << "1. 여권 등록   2. 예약   3. 예약 확인   4. 나가기" << endl;
					cin >> c;
					if (c == 1) {
						int passNum;
						cout << "여권 번호를 입력하세요 : ";
						cin >> passNum;	
						pass = Passenger(User, passNum);
					}
					else if (c == 2) {
						int k = 0;
						Show_Flight_Status(Flight_DB);
						cout << "이용하려는 항공기를 선택하세요 : ";
						cin >> k;
						Flight_DB[k - 1].reservation(pass);
					}
					else if (c == 3) {
						for (int i = 0; i < Flight_DB.size(); i++) {
							Flight_DB[i].checkReserve(pass);
						}
					}
					if (c == 4)
						break;
				}
			}
		}
		else if (a == 3)
			return 0;
	}
}