#include "User.h"



int checkid(vector<Guest> DB, string id) {
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].getID() == id) {
			return 1;
		}
	}
	return 2;
}

bool is_digit(string rn) {
	return atoi(rn.c_str()) != 0 || rn.compare("0") == 0;
}

int checkrn(string rn) {
	if (rn.size() != 13|| (!is_digit(rn)))
		return 1;
}

Guest join(vector<Guest> DB)
{
	string na, id, pw, rn, ad;
	cout << "-----------Join-----------" << endl;
	cout << "Input Name : ";
	cin >> na;
	cout << "Input Id : ";
	cin >> id;
	int cid=checkid(DB,id);
	while (cid == 1) {
		cout << "Id is already existed.\n";
		cout << "Input Id again : ";
		cin >> id;
		cid = checkid(DB, id);
	}
	cout << "input Password : ";
	cin >> pw;
	cout << "Input Resident Registration Number(Except '-'): ";
	cin >> rn;
	int crn = checkrn(rn);
	while (crn == 1) {
		cout << "It's an abnormal formation.\n";
		cout << "Input Password again : ";
		cin >> rn;
		crn = checkrn(rn);
	}
	cout << "Input Address : ";
	cin >> ad;
	cout << "Join Complete." << endl;
	Guest g(id, pw, na, rn, ad);
	return g;
}
