#include "Airplane.h"

int main() {
	int asdf;
	string a, b, c, d, e;
	string g, h, i, j, k, l, m;
	int f,n,o;
	cout << "Input ID : ";
	cin >> a;
	cout << "Input PW : ";
	cin >> b;
	cout << "Input your name : ";
	cin >> c;
	cout << "Input your register number : ";
	cin >> d;
	cout << "Input your address : ";
	cin >> e;
	Guest aa(a,b,c,d,e);

	cout << "\n -----Passenger Input-----" << endl;
	cout << "Input your passport number : ";
	cin >> f;
	Passenger bb(aa,f);

	aa.test();
	cout << endl;
	bb.test();
	cout << "Input airplane name : ";
	cin >> g;

	cout << "Input company name : ";
	cin >> h;
	cout << "Input airplane's row : ";
	cin >> n;
	cout << "Input airplane's column : ";
	cin >> o;
	Airplane cc(g, h, n, o);

	cout << "Input your departure place : ";
	cin >> i;
	cout << "Input your arrival place : ";
	cin >> j;
	cout << "Input your departure day : ";
	cin >> k;
	cout << "Input your departure time : ";
	cin >> l;
	cout << "Input your arrival time : ";
	cin >> m;
	Flight dd(cc, i, j, k, l, m);

	Guest asd("a", "b", "c", "d", "e");
	Passenger zxcv(asd, 1234);
	cc.test();
	cout << endl;
	dd.test();
	cout << endl;
	dd.testest(zxcv);
	dd.viewSit();
	cin >> asdf;
}