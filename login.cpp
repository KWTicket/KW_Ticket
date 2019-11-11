#pragma once
#include "User.h"

Guest login(vector<Guest> DB) {

	string a, b;

	cout << "Input your ID : ";
	cin >> a;
	cout << "Input you Password : ";
	cin >> b;

	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].getID() == a) {
			if (DB[i].getPW() == b) {
				cout << "Hello," << DB[i].getName() << "!" << endl;
				return DB[i];
			}
		}
	}
	return DB[0];

}