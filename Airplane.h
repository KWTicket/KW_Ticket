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
		for (int i = 0; i < col; i++) {		// 동적배열
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
		cout << apName << '\n' << comName << '\n' << row << '\n' << col << endl;
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
		cout << departure << '\n' << arrival << '\n' << day << '\n' << depTime << '\n' << arrTime;
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
	void testest(Passenger p) {
		ap.sit[3][3] = p;
	}
};