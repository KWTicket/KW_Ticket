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

void Show_Airplane_Status(vector <Airplane> Check_air){
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
