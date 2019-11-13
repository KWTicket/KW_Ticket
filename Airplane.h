#pragma once
#include "User.h"

class Airplane {
private:
	string apName;
	string comName;
	int row;
	int col;
public:
	Airplane(){}
	Airplane(string apName, string comName, int row, int col) {
		this->apName = apName;
		this->comName = comName;
		this->row = row;
		this->col = col;

	}
	string getAp() {
		return apName;
	}
	string getCom() {
		return comName;
	}
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
	void test() {
		cout << '\n' << "airplane name : " << apName << '\n' <<
				"company name : " << comName << '\n' <<
				"row : " << row << '\n' <<
				"column : " << col << endl;
	}
};


class Flight{
private:
	Airplane ap;
	string departure;
	string arrival;
	string day;
	string depTime;
	string arrTime;	
public:
	Passenger** sit;
	Flight(){}
	Flight(Airplane ap, string dep, string arr, string day, string dt, string at) {
		this->ap = ap;
		this->departure = dep;
		this->arrival = arr;
		this->day = day;
		this->depTime = dt;
		this->arrTime = at;

		sit = new Passenger*[getAir().getRow()];			// 2����
		for (int i = 0; i < getAir().getRow(); i++) {		// �����迭
			sit[i] = new Passenger[getAir().getCol()];	// ������
		}
	}

	Airplane getAir() {
		return ap;
	}

	string getDep() {
		return departure;
	}
	string getArr() {
		return arrival;
	}
	string getDay() {
		return day;
	}
	string getDt() {
		return depTime;
	}
	string getAt() {
		return arrTime;
	}
	void test() {
		ap.test();
		cout << "departure : " << departure << '\n' <<
				"arrival : " << arrival << '\n' <<
				"day : " << day << '\n' <<
				"depTime : " << depTime << '\n' <<
				"arrTime : " << arrTime << endl;
	}
	void viewSit(){
		for (int i = 0; i < ap.getRow(); i++) {
			for (int j = 0; j < ap.getCol(); j++) {
				if (sit[i][j].getPass() == 0)
					cout << "[��]";
				else cout << "[��]";
			}
			cout << endl;
		}
	}

	void reservation(Passenger passenger) {

		int row = 0, col = 0;

		cout << "�¼��� �����ϼ���" << endl;
		viewSit();
		cout << "�� : ";
		cin >> row;
		cout << "�� : ";
		cin >> col;

		if (sit[row - 1][col - 1].getPass() != 0)
			cout << "�̹� ���õ� �¼��Դϴ�." << endl;
		else {
			for (int i = 0; i < ap.getRow(); i++) {
				for (int j = 0; j < ap.getCol(); j++) {
					if (sit[i][j].getPass() == passenger.getPass()) {
						cout << "�̹� �� ����⿡ ���� �Ǿ� �ֽ��ϴ�." << endl;
						cout << "�ٽ� ���� �Ͻ÷��� ���� ������ ������ּ���." << endl;
						return;
					}
				}
			}
			sit[row - 1][col - 1] = passenger;
			cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
			viewSit();
		}		
	}
	void checkReserve(Passenger passenger) {
		cout << passenger.getName() << "���� ���� �����Դϴ�." << endl;
		for (int i = 0; i < ap.getRow(); i++) {
			for (int j = 0; j < ap.getCol(); j++) {
				if (sit[i][j].getPass() == passenger.getPass()) {
					test(); // ���� ����� ��� ������ ���� �޶��� �����Դϴ�.
				}
			}
		}
	}
};