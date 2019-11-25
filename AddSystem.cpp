#include "Airplane.h"
#include "User.h"
#include <vector>
#include <windows.h>

Airplane addAirplane() {
	system("cls");
	string a, b;
	int c, d;
	cout << "" << endl;
	cout << "   Airplane name : ";
	cin >> a;

	cout << "   Company name : ";
	cin >> b;

	cout << "   Airplane's row : ";
	cin >> c;

	cout << "   Airplane's column : ";
	cin >> d;

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

	cout << "   Input Airplane's departure day : "
	cin >> g;

	cout << "   Input Airplane's departure time : ";
	cin >> h;

	cout << "   Input Airplane's arrival time : ";
	cin >> i;

	Flight flight(air, e, f, g, h, i);
	flight.test();
	flight.viewSit();
	cout << "   ☆ Flights are added successfully ☆" << endl;
	Sleep(4000);
	return flight;
}

void Show_Airplane_Status(vector <Airplane> Check_air) {
	for (int a = 0; a < Check_air.size(); a++) {
		cout << a + 1 << "Airplane name : " << Check_air[a].getAp() << endl;
		cout << "  Company : " << Check_air[a].getCom() << endl;
		cout << "  Size : row " << Check_air[a].getRow() << "   column " << Check_air[a].getCol() << endl;
	}
}
void Show_Flight_Status(vector <Flight> Check_flight) {
	for (int a = 0; a < Check_flight.size(); a++) {
		cout << a + 1 << "Airplane name : " << Check_flight[a].getAir().getAp() << endl;
		cout << "  Company : " << Check_flight[a].getAir().getCom() << endl;
		cout << "  Size : row " << Check_flight[a].getAir().getRow() << "   column " << Check_flight[a].getAir().getCol() << endl;
		cout << "  departure airport : " << Check_flight[a].getDep() << endl;
		cout << "  arrival airport : " << Check_flight[a].getArr() << endl;
		cout << "  departure date : " << Check_flight[a].getDay() << endl;
		cout << "  departure time : " << Check_flight[a].getDt() << endl;
		cout << "  arrival time : " << Check_flight[a].getAt() << endl;
	}
}
