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
{
	string na, id, pw, rn, ad;
	cout << "-----------ȸ������-----------" << endl;
	cout << "�̸��� �Է����ּ���: ";
	cin >> na;
	cout << "���̵� �Է����ּ���: ";
	cin >> id;
	int cid=checkid(DB,id);
	while (cid == 1) {
		cout << "�̹� �����ϴ� ���̵��Դϴ�.\n";
		cout << "���̵� �ٽ� �Է����ּ���: ";
		cin >> id;
		cid = checkid(DB, id);
	}
	cout << "��й�ȣ�� �Է����ּ���: ";
	cin >> pw;
	cout << "�ֹι�ȣ�� �Է����ּ���: ";
	cin >> rn;
	cout << "�ּҸ� �Է����ּ���: ";
	cin >> ad;
	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	Guest g(id, pw, na, rn, ad);
	return g;
}