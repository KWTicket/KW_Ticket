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
	cout << "�ֹε�Ϲ�ȣ�� �Է����ּ���(-����): ";
	cin >> rn;
	int crn = checkrn(rn);
	while (crn == 1) {
		cout << "�ùٸ��� ���� �����Դϴ�.\n";
		cout << "�ٽ� �Է����ּ���: ";
		cin >> rn;
		crn = checkrn(rn);
	}
	cout << "�ּҸ� �Է����ּ���: ";
	cin >> ad;
	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	Guest g(id, pw, na, rn, ad);
	return g;
}