#include "Airplane.h"
#include "User.h"
#include <vector>

Airplane addAirplane() {
	string a, b;
	int c, d;

	cout << "Input airplane name : ";
	cin >> a;

	cout << "Input company name : ";
	cin >> b;

	cout << "Input airplane's row : ";
	cin >> c;

	cout << "Input airplane's column : ";
	cin >> d;

	Airplane airplane(a, b, c, d);
	airplane.test();
	cout << "Complete!!" << endl;
	return airplane;
}

Flight addFlight(Airplane air) {
	string e, f, g, h, i;

	cout << "Input your departure place : ";
	cin >> e;

	cout << "Input your arrival place : ";
	cin >> f;

	cout << "Input your departure day : ";
	cin >> g;

	cout << "Input your departure time : ";
	cin >> h;

	cout << "Input your arrival time : ";
	cin >> i;

	Flight flight(air, e, f, g, h, i);
	flight.test();
	flight.viewSit();
	cout << "Complete!!" << endl;
	return flight;
}