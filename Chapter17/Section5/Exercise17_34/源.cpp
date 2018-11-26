#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout << "boolalpha_noboolalpha" << endl;
	cout << true << " " << false << endl;
	cout << boolalpha << true << " " << false << endl;
	cout << noboolalpha << endl;

	cout << "showbase_noshowbase\\uppercase_nouppercase" << endl;
	cout << showbase << uppercase << endl;
	cout << oct << 10 << " " << 15 << endl;
	cout << hex << 10 << " " << 15 << endl;
	cout << dec << 10 << " " << 15 << endl;
	cout << noshowbase << nouppercase << endl;

	cout << "showpoint_noshowpoint" << endl;
	cout << 10.0 << endl;
	cout << showpoint << 10.0 << endl;
	cout << noshowpoint << endl;

	cout << "showpos_noshowpos" << endl;
	cout << 8 << endl;
	cout << showpos << 8 << endl;
	cout << noshowpos << endl;

	cout << "setw_left_right_internal_setfill" << endl;
	cout << setfill('#');
	cout << setw(12) << -15 << "end" << endl;
	cout << left << setw(12) << -15 << "end" << endl;
	cout << internal << setw(12) << -15 << "end" << endl;
	cout << right << setw(12) << -15 << "end" << endl;
	cout << setfill(' ') << endl;

	cout << "skipws_noskipws" << endl;
	char c;
	cin >> noskipws;
	while (cin >> c)
	{
		cout << c;
	}
	cin >> skipws;

	system("pause");
	return 0;
}