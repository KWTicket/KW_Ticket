#include "User.h"
#include <windows.h>

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
	if (rn.size() != 13 || (!is_digit(rn)))
		return 1;
}

Guest join(vector<Guest> DB)
{
	string na, id, pw, rn, ad;
	system("cls");
	cout << "" << endl;
	cout << "[ Join ] ============================================" << endl;
	cout << "∥                                                  ∥" << endl;
	cout << "∥    ★ Please enter the correct information ★    ∥" << endl;
	cout << "∥                                                  ∥" << endl;
	cout << "∥     ★ When you withdraw from membership, ★     ∥" << endl;
	cout << "∥     ★ the information will be discarded ★      ∥" << endl;
	cout << "∥                                                  ∥" << endl;
	cout << "=====================================================" << endl;
	cout << "" << endl;

	cout << "   Name : ";
	cin >> na;
	cout << "   ID : ";
	cin >> id;
	int cid = checkid(DB, id);
	while (cid == 1) {
		cout << "" << endl;
		cout << "   !!!! ID is already existed !!!!\n ";
		cout << "   Please input another ID :-(" << endl;
		cout << "" << endl;
		cout << "   ID : ";
		cin >> id;
		cid = checkid(DB, id);
	}
	cout << "   Password : ";
	cin >> pw;
	cout << "   Resident Registration Number(Except '-') : ";
	cin >> rn;
	int crn = checkrn(rn);
	while (crn == 1) {
		cout << "" << endl;
		cout << "   !!!! It's an abnormal formation !!!!\n";
		cout << "   Please input Resident Registration Number again :-(" << endl;
		cout << "" << endl;
		cout << "   Resident Registration Number(Except '-') : ";
		cin >> rn;
		crn = checkrn(rn);
	}
	cout << "   Address : ";
	cin >> ad;
	cout << "" << endl;
	cout << "" << endl;
	cout << "              ♡ Congratulations !! ♡" << endl;
	cout << "     ♡ Your membership has been completed ♡" << endl;
	cout << "♡ Have a comfortable and happy trip with KW-TICKET ♡" << endl;
	cout << "" << endl;
	Guest g(id, pw, na, rn, ad);
	Sleep(3000);
	system("cls");
	return g;
}
