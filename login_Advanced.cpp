#pragma once
#include "User.h"

Guest login(vector<Guest> DB) {

	string a, b;

	while (1) {
		cout << "Input your ID : ";
		cin >> a;
		b = "";

		for (int i = 0; i < DB.size(); i++) {

			if (DB[i].getID() == a) {
				while (1) {
					cout << "Input you Password : ";
					cin >> b;

					if (DB[i].getPW() == b) {
						cout << "Hello," << DB[i].getName() << "!" << endl;
						return DB[i];
					}

					else if (b == "q") {
						break;
					}

					else {
						cout << "*** Please enter your password correctly. ***" << endl;
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

				Guest Null(a,b,c,d,e);
				return Null;
			}
			if (b == "q")
				break;
		}
		if (b == "q")
			continue;

		cout << "*** Please enter your ID correctly. ***" << endl;
		cout << endl;
	}
}
