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

		sit = new Passenger*[getAir().getRow()];			// 2차원
		for (int i = 0; i < getAir().getRow(); i++) {		// 동적배열
			sit[i] = new Passenger[getAir().getCol()];	// 생성문
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
					cout << "[□]";
				else cout << "[■]";
			}
			cout << endl;
		}
	}

	void reservation(Passenger passenger) {

		int row = 0, col = 0;

		cout << "좌석을 선택하세요" << endl;
		viewSit();
		cout << "행 : ";
		cin >> row;
		cout << "열 : ";
		cin >> col;

		if (sit[row - 1][col - 1].getPass() != 0)
			cout << "이미 선택된 좌석입니다." << endl;
		else {
			for (int i = 0; i < ap.getRow(); i++) {
				for (int j = 0; j < ap.getCol(); j++) {
					if (sit[i][j].getPass() == passenger.getPass()) {
						cout << "이미 이 비행기에 예약 되어 있습니다." << endl;
						cout << "다시 예약 하시려면 기존 예약을 취소해주세요." << endl;
						return;
					}
				}
			}
			sit[row - 1][col - 1] = passenger;
			cout << "예약이 완료되었습니다." << endl;
			viewSit();
		}		
	}
	void checkReserve(Passenger passenger) {
		cout << passenger.getName() << "님의 예약 정보입니다." << endl;
		for (int i = 0; i < ap.getRow(); i++) {
			for (int j = 0; j < ap.getCol(); j++) {
				if (sit[i][j].getPass() == passenger.getPass()) {
					test(); // 저희가 출력을 어떻게 할지에 따라서 달라질 예정입니다.
				}
			}
		}
	}
};