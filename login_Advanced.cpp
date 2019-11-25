#pragma once
#include "User.h"
#include <windows.h>

Guest login(vector<Guest> DB) {
	system("cls");
	string a, b;
	cout << "" << endl;

	while (1) {
		cout << "[ Login ] ============================================" << endl;
		cout << "∥                                                  ∥" << endl;
		cout << "∥    ★ Please enter the correct information ★    ∥" << endl;
		cout << "∥                                                  ∥" << endl;
		cout << "∥ ★ If you want to go previous stage, press q. ★ ∥" << endl;
		cout << "∥                                                  ∥" << endl;
		cout << "=====================================================" << endl;
		cout << "" << endl;
		cout << "   ID : ";
		cin >> a;
		b = "";

		for (int i = 0; i < DB.size(); i++) {

			if (DB[i].getID() == a) {
				while (1) {
					cout << "   Password : ";
					cin >> b;

					if (DB[i].getPW() == b) {
						cout << "" << endl;
						cout << "===============================================" << endl;
						cout << "∥             Hello, " << DB[i].getName() << " > 0<!            ∥" << endl;
						cout << "∥♡  Have a nice trip with KW-TICKET :-)  ♡∥" << endl;
						cout << "===============================================" << endl;
						cout << "" << endl;
						Sleep(2000);
						return DB[i];
					}

					else if (b == "q") {
						cout << "" << endl;
						system("cls");
						break;
					}

					else { //패스워드 정확하게
						cout << "" << endl;
						cout << "   !!!! The Password is not correct !!!!\n ";
						cout << "   Please input the correct Password :-(" << endl;
						continue;
					}
				}
			}

			else if (a == "q") {
				string a = "";
				string b = "";
				string c = "Null";
				string d = "";
				string e = "";
				Guest Null(a, b, c, d, e);
				system("cls");
				return Null;
			}
			if (b == "q")
				break;
		}
		if (b == "q") {
			cout << "" << endl;
			continue;
		}

		cout << "" << endl;
		cout << "   !!!! The ID is not valid !!!!\n ";
		cout << "   Please input a valid ID :-(" << endl;
		cout << endl;
	}
}
