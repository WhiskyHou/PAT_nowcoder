#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	const int cLK_TCK = 100;
	int c1, c2;
	cin >> c1 >> c2;

	int h, m, s;
	s = (c2 - c1) / cLK_TCK;
	(((c2 - c1) % cLK_TCK) < 50) ? s : s++;
	h = s / 3600;
	s = s % 3600;
	m = s / 60;
	s = s % 60;

	cout << setfill('0') << setw(2) << h << ":"
		<< setfill('0') << setw(2) << m << ":"
		<< setfill('0') << setw(2) << s;

	return 0;
}