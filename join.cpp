#include "User.h"
#include <vector>

Guest join()
{
	string na, id, pw, rn, ad;
	cout << "-----------회원가입-----------" << endl;
	cout << "이름을 입력해주세요: ";
	cin >> na;
	cout << "아이디를 입력해주세요: ";
	cin >> id;
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