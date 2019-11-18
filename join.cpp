#include "User.h"
#include <vector>


int checkid(vector<Guest> DB, string id) {
	for (int i = 0; i < DB.size(); i++) {
		if (DB[i].getID() == id) {
			return 1;
		}
	}
	return 2;
}

Guest join(vector<Guest> DB)
  
Guest join()
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
	cout << "주민번호를 입력해주세요: ";
	cin >> rn;
	cout << "주소를 입력해주세요: ";
	cin >> ad;
	cout << "가입이 완료되었습니다." << endl;
	Guest g(id, pw, na, rn, ad);
	return g;
}