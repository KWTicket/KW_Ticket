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
	cout << "-----------회원가입-----------" << endl;
	cout << "이름을 입력해주세요: ";
	cin >> na;
	cout << "아이디를 입력해주세요: ";
	cin >> id;
	int cid=checkid(DB,id);
	while (cid == 1) {
		cout << "이미 존재하는 아이디입니다.\n";
		cout << "아이디를 다시 입력해주세요: ";
		cin >> id;
		cid = checkid(DB, id);
	}
	cout << "비밀번호를 입력해주세요: ";
	cin >> pw;
	cout << "주민등록번호를 입력해주세요(-제외): ";
	cin >> rn;
	int crn = checkrn(rn);
	while (crn == 1) {
		cout << "올바르지 않은 형식입니다.\n";
		cout << "다시 입력해주세요: ";
		cin >> rn;
		crn = checkrn(rn);
	}
	cout << "주소를 입력해주세요: ";
	cin >> ad;
	cout << "가입이 완료되었습니다." << endl;
	Guest g(id, pw, na, rn, ad);
	return g;
}