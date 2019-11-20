#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Guest {
private:
	string ID;
	string PW;
	string name;
	string regNum;
	string address;

public:
	Guest(){
		ID = " ";
		PW = " ";
		name = " ";
		regNum = " ";
		address = " ";
	}
	Guest(string id, string pw, string name, string regnum, string address) {
		this->ID = id;
		this->PW = pw;
		this->name = name;
		this->regNum = regnum;
		this->address = address;
	}
	string getID() {
		return ID;
	}
	string getPW() {
		return PW;
	}
	string getName() {
		return name;
	}
	string getReg() {
		return regNum;
	}
	string getAdd() {
		return address;
	}
	void test() {
		cout << "ID : " << ID << '\n' <<
				"PW : " << PW << '\n' <<
				"name : " << name << '\n' <<
				"register number : " << regNum << '\n' <<
				"address : " << address << endl;
	}
};

class Passenger : public Guest {
private:
	int passNum;
public:
	Passenger(){
		passNum = 0;
	}
	Passenger(Guest g, int passNum) : Guest(g.getID(), g.getPW(), g.getName(), g.getReg(),g.getAdd()) {
		this->passNum = passNum;
	}
	int getPass() {
		return passNum;
	}
	void test() {
		Guest::test();
		cout << "passport number : " << passNum << endl;
	}
};
