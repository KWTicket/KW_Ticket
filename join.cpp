#include "User.h"
#include <vector>

Guest join()
{
	string na, id, pw, rn, ad;
	cout << "-----------ȸ������-----------" << endl;
	cout << "�̸��� �Է����ּ���: ";
	cin >> na;
	cout << "���̵� �Է����ּ���: ";
	cin >> id;
	cout << "��й�ȣ�� �Է����ּ���: ";
	cin >> pw;
	cout << "�ֹι�ȣ�� �Է����ּ���: ";
	cin >> rn;
	cout << "�ּҸ� �Է����ּ���: ";
	cin >> ad;
	cout << "������ �Ϸ�Ǿ����ϴ�.";
	Guest g(id, pw, na, rn, ad);
	return g;
}
int main() {
	vector<Guest> guest;
	guest.push_back(join());
}