#pragma once
#include "User.h"

class Airplane {
private:
	string apName;
	string comName;
	int row;
	int col;
public:
	Passenger** sit;
	Airplane(){}
	Airplane(string apName, string comName, int row, int col) {
		this->apName = apName;
		this->comName = comName;
		this->row = row;
		this->col = col;
		
		sit = new Passenger*[row];			// 2차원
		for (int i = 0; i < row; i++) {		// 동적배열
			sit[i] = new Passenger[col];	// 생성문
		}

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
	Flight(){}
	Flight(Airplane ap, string dep, string arr, string day, string dt, string at) {
		this->ap = ap;
		this->departure = dep;
		this->arrival = arr;
		this->day = day;
		this->depTime = dt;
		this->arrTime = at;
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
				if (ap.sit[i][j].getPass() == 0)
					cout << "[□]";
				else cout << "[■]";
			}
			cout << endl;
		}
	}
	void reservation(int row, int col, Passenger passenger) {
		ap.sit[row - 1][col - 1] = passenger;
	}

	void checkReserve(Passenger passenger) {
		cout << passenger.getName() << "님의 예약 정보입니다." << endl;
		for (int i = 0; i < ap.getRow(); i++) {
			for (int j = 0; j < ap.getCol(); j++) {
				if (ap.sit[i][j].getPass() == passenger.getPass()) {
					cout << "  Departure place : " << departure << endl;
					cout << "  Arrival place : " << arrival << endl;
					cout << "  Departure date " << day << endl;
					cout << "  Departure time : " << depTime << endl;
					cout << "  Arrival time : " << arrTime << endl;
					cout << "  row : " << ap.getRow() << "   column " << ap.getCol() << endl;
				}
			}
		}
	}

	void cancelReserve(int row, int col, Passenger passenger) {
		cout << passenger.getName() << "님의 예약을 취소합니다." << endl;
		ap.sit[row - 1][col - 1].getPass() == NULL;
	}
};