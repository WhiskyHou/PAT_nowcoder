#include<iostream>
#include<list>

using namespace std;

int main() {
	unsigned int a, b, d;
	cin >> a >> b >> d;

	a = a + b;
	list<short> result;
	while (a != 0) {
		result.push_front((short)(a % d));
		a = a / d;
	}

	for (list<short>::iterator p = result.begin(); p != result.end(); p++) {
		cout << *p;
	}

	return 0;
}