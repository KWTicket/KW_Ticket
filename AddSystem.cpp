﻿#include "Airplane.h"
#include "User.h"
#include <vector>
#include <windows.h>
#include <iomanip>

Airplane addAirplane() {
	system("cls");
	string a, b;
	int c = 0, d = 0;
	cout << "" << endl;
	cout << "   [[  Please fill out the flight information.  ]]" << endl;
	cout << "" << endl;
	cout << "   Airplane name : ";
	cin >> a;

	cout << "   Company name : ";
	cin >> b;

	
	while (c == 0){
		cout << "   Airplane's row(Only Number) : ";
		cin >> c;
	if (!cin) {
		cout << "   Error : Please input number!" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

	while (d == 0) {
		cout << "   Airplane's column(Only Number) : ";
		cin >> d;
		if (!cin) {
			cout << "   Error : Please input number!" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
	}
	Airplane airplane(a, b, c, d);
	airplane.test();
	cout << "" << endl;
	cout << "   Operation completed." << endl;
	Sleep(2000);
	return airplane;
}

Flight addFlight(Airplane air) {
	system("cls");
	string e, f, g, h, i;

	cout << "" << endl;
	cout << "[ Departure ] ======================================================" << endl;
	cout << "∥                                                                ∥" << endl;
	cout << "∥       Choose airplane's departure place.                       ∥" << endl;
	cout << "∥                                                                ∥" << endl;
	cout << "∥ - INCHEON       - GIMPO   - JEJU     - HANEDA      - NARITA    ∥\n";
	cout << "∥ - KANSAI        - TAIPEI  - BEIJING  - SHANGHAI    - GUANGZHOU ∥\n";
	cout << "∥ - HONGKONG      - MACAU   - DANANG   - CEBU        - BORACAY   ∥\n";
	cout << "∥ - KOTAKINABALU  - LA      - MIAMI    - WASHINGTON  - TORONTO   ∥\n";
	cout << "∥ - VANCOUVER     - LONDON  - PARIS    - BERLIN      - WEIN      ∥\n";
	cout << "∥ - BUDAPEST      - PRAHA                                        ∥\n";
	cout << "∥                                                                ∥" << endl;
	cout << "====================================================================" << endl;
	cout << "" << endl;
	cout << "   >> ";
	cin >> e;

	cout << "" << endl;
	cout << "[ Arrival ] ========================================================" << endl;
	cout << "∥                                                                ∥" << endl;
	cout << "∥       Choose airplane's arrival place.                         ∥" << endl;
	cout << "∥                                                                ∥" << endl;
	cout << "∥ - INCHEON       - GIMPO   - JEJU     - HANEDA      - NARITA    ∥\n";
	cout << "∥ - KANSAI        - TAIPEI  - BEIJING  - SHANGHAI    - GUANGZHOU ∥\n";
	cout << "∥ - HONGKONG      - MACAU   - DANANG   - CEBU        - BORACAY   ∥\n";
	cout << "∥ - KOTAKINABALU  - LA      - MIAMI    - WASHINGTON  - TORONTO   ∥\n";
	cout << "∥ - VANCOUVER     - LONDON  - PARIS    - BERLIN      - WEIN      ∥\n";
	cout << "∥ - BUDAPEST      - PRAHA                                        ∥\n";
	cout << "∥                                                                ∥" << endl;
	cout << "====================================================================" << endl;
	cout << "" << endl;
	cout << "   >> ";
	cin >> f;
	cout << "" << endl;

	cout << "   Input Airplane's departure day(Ex. 20191208) : ";
	cin >> g;

	cout << "   Input Airplane's departure time(Ex. 21:00) : ";
	cin >> h;

	cout << "   Input Airplane's arrival time(Ex. 23:00) : ";
	cin >> i;

	Flight flight(air, e, f, g, h, i);
	system("cls");
	flight.test();
	flight.viewSit();
	cout << "" << endl;
	cout << "   ☆ Flights are added successfully ☆" << endl;
	Sleep(3000);
	return flight;
}

void Show_Airplane_Status(vector <Airplane> Check_air) {
	cout << "" << endl;
	cout << " [[  List of planes  ]]" << endl;
	for (int a = 0; a < Check_air.size(); a++) {
		cout << "" << endl;
		cout << " (" << a + 1 << ")" << " Airplane name : " << Check_air[a].getAp() << endl;
		cout << "     Company : " << Check_air[a].getCom() << endl;
		cout << "     Size : row " << Check_air[a].getRow() << "   column " << Check_air[a].getCol() << endl;
		cout << "" << endl;
		cout << "" << endl;
	}
}

	void Show_Flight_Status(vector <Flight> Check_flight) {
		cout << "" << endl;
		cout << " [[  List of flight plans  ]]" << endl;
		cout << "" << endl;
		cout << "     Airplane name     Company     Departure airport     Arrival airport     Departure date     Departure time     Arrival time" << endl;
		for (int a = 0; a < Check_flight.size(); a++) {
			cout << "" << endl;
			cout << " (" << a + 1 << ") ";
			cout << setw(13) << Check_flight[a].getAir().getAp();
			cout << setw(12) << Check_flight[a].getAir().getCom();
			cout << setw(22) << Check_flight[a].getDep();
			cout << setw(20) << Check_flight[a].getArr();
			cout << setw(19) << Check_flight[a].getDay();
			cout << setw(19) << Check_flight[a].getDt();
			cout << setw(17) << Check_flight[a].getAt();
			cout << "" << endl;
		}
	}
