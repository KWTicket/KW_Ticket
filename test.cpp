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
		cout << "WELCOME! \n\n 1. ȸ������   2. �α���   3. ������" << endl;
		cin >> a;
		if (a == 1)
			Guest_DB.push_back(join());
		else if (a == 2) {
			User = login(Guest_DB);
			if (User.getName() == "admin") {
				while (1) {
					cout << "1. ����� �߰�   2. ������ �߰�   3. ������" << endl;
					cin >> b;
					if (b == 1)
						Airplane_DB.push_back(addAirplane());
					else if (b == 2) {
						int k = 0;
						Show_Airplane_Status(Airplane_DB);
						cout << "�߰��Ϸ��� �������� ����⸦ �����ϼ��� : ";
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
					cout << "1. ���� ���   2. ����   3. ���� Ȯ��   4. ���� ���	5. ������" << endl;
					cin >> c;
					if (c == 1) {
						int passNum;
						cout << "���� ��ȣ�� �Է��ϼ��� : ";
						cin >> passNum;	
						pass = Passenger(User, passNum);
					}
					if (c == 2) {
						int k = 0, row = 0, col = 0;						
						Show_Flight_Status(Flight_DB);
						cout << "�̿��Ϸ��� �װ��⸦ �����ϼ��� : ";
						cin >> k;
						cout << "�¼��� �����ϼ���" << endl;
						Flight_DB[k - 1].viewSit();
						cout << "�� : ";
						cin >> row;
						cout << "�� : ";
						cin >> col;
						cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
						Flight_DB[k - 1].reservation(row, col, pass);
						Flight_DB[k - 1].viewSit();
					}
					if (c == 3) {
						for (int i = 0; i < Flight_DB.size(); i++) {
							Flight_DB[i].checkReserve(pass);
					}
						if (c == 4) {
							int k = 0, row = 0, col = 0;
							Show_Flight_Status(Flight_DB);
							cout << "�̿��Ϸ��� �װ��⸦ �����ϼ��� : ";
							cin >> k;
							cout << "������ �¼��� �����ϼ���" << endl;
							Flight_DB[k - 1].viewSit();
							cout << "�� : ";
							cin >> row;
							cout << "�� : ";
							cin >> col;
							cout << "��Ұ� �Ϸ�Ǿ����ϴ�!" << endl;
							Flight_DB[k - 1].cancelReserve(row, col, pass);
							Flight_DB[k - 1].viewSit();
						}
					if (c == 5)
						break;
				}
			}
		}
		else if (a == 3)
			return 0;
	}
}