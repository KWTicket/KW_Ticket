#include "Airplane.h"
#include "User.h"
#include <vector>

Airplane addAirplane() {
	string a, b, c, d;

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

	return airplane;
}

void addAirWay(Airplane air) {
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

	Flight airway(air, e, f, g, h, i);
	airway.test();
	airway.viewSit();
}

int main(void) {
	int i = 0;
	vector<Airplane> airSet;
	Airplane airplane = addAirplane();
	airset.push_back(airplane);
	for (i = 0; i < airSet.size(); i++) {
		cout << i << " : " << airSet[i] << endl;
	}
	cout << "Choose airplane that you want to take : ";
	cin >> i;

	addAirWay(airSet[i]);
}