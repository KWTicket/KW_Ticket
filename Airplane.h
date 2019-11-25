#pragma once
#include "User.h"

class Airplane {
private:
	string apName;
	string comName;
	int row;
	int col;
public:
	Airplane() {}
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
		cout << "" << endl;
		cout << "=========================================" << endl;
		cout << "" << endl;
		cout << "  !! Please check plane information !!  " << endl;
		cout << '\n' << "   airplane name : " << apName << '\n' <<
			"   company name : " << comName << '\n' <<
			"   row : " << row << '\n' <<
			"   column : " << col << endl;
		cout << "" << endl;
		cout << "=========================================" << endl;
	}
};


class Flight {
private:
	Airplane ap;
	string departure;
	string arrival;
	string day;
	string depTime;
	string arrTime;
public:
	Passenger** sit;
	Flight() {}
	Flight(Airplane ap, string dep, string arr, string day, string dt, string at) {
		this->ap = ap;
		this->departure = dep;
		this->arrival = arr;
		this->day = day;
		this->depTime = dt;
		this->arrTime = at;

		sit = new Passenger *[getAir().getRow()];			// 2차원
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
		cout << "" << endl;
		cout << "   departure : " << departure << '\n' <<
			"   arrival : " << arrival << '\n' <<
			"   day : " << day << '\n' <<
			"   depTime : " << depTime << '\n' <<
			"   arrTime : " << arrTime << endl;
		cout << "" << endl;
	}
	void viewSit() {
		for (int i = 0; i < ap.getRow(); i++) {
			cout << "   ";
			for (int j = 0; j < ap.getCol(); j++) {
				if (sit[i][j].getPass() == 0)
					cout << "[X]";
				else cout << "[O]";
			}
			cout << endl;
		}
	}

	void reservation(Passenger passenger) {

		if (passenger.getPass() == 0) {
			cout << "You should input passport number first." << endl;
			return;
		}

		int row = 0, col = 0;

		cout << "Choose Seat\n";
		viewSit();
		cout << "Row : ";
		cin >> row;
		cout << "Column : ";
		cin >> col;

		if (sit[row - 1][col - 1].getPass() != 0)
			cout << "This seat is already selected." << endl;
		else {
			for (int i = 0; i < ap.getRow(); i++) {
				for (int j = 0; j < ap.getCol(); j++) {
					if (sit[i][j].getPass() == passenger.getPass()) {
						cout << "You already made a reservation on this airplane." << endl;
						cout << "If you want to book again, please cancel a reservation that you already made." << endl;
						return;
					}
				}
			}
			sit[row - 1][col - 1] = passenger;
			cout << "Reservation Complete." << endl;
			viewSit();
		}
	}
	void checkReserve(Passenger passenger) {
		for (int i = 0; i < ap.getRow(); i++) {
			for (int j = 0; j < ap.getCol(); j++) {
				if (sit[i][j].getPass() == passenger.getPass()) {
					cout << "  Departure place : " << departure << endl;
					cout << "  Arrival place : " << arrival << endl;
					cout << "  Departure date " << day << endl;
					cout << "  Departure time : " << depTime << endl;
					cout << "  Arrival time : " << arrTime << endl;
					for (int p = 0; p < ap.getRow(); p++) {
						for (int q = 0; q < ap.getCol(); q++) {
							if (sit[p][q].getPass() == passenger.getPass())
								cout << "  row : " << p + 1 << "   column : " << q + 1 << "\n\n";
						}
					}
				}
			}
		}
	}

	void cancelReserve(Passenger passenger) {
		int i, j;
		cout << passenger.getName() << "'s reservation Canceling ..." << endl;
		for (i = 0; i < ap.getRow(); i++) {
			for (j = 0; j < ap.getCol(); j++) {
				if (passenger.getID() == sit[i][j].getID()) {
					Guest temp("", "", "", "", "");
					Passenger tem(temp, 0);
					sit[i][j] = tem;
				}
			}
		}
		cout << "Cancel Complete" << endl;
	}
};
