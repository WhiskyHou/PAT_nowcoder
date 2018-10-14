#include<iostream>

using namespace std;

int main() {
	char* input = new char[26];
	cin.getline(input, 26);

	int count_a[10] = { 0 };
	int da = 0;
	int count_b[10] = { 0 };
	int db = 0;

	int current_state = 0;

	for (char* p = input; *p != '\0'; p++) {
		if (*p == ' ') {
			current_state++;
			continue;
		}

		switch (current_state) {
		case 0:
			count_a[*p - '0']++;
			break;
		case 1:
			da = *p - '0';
			break;
		case 2:
			count_b[*p - '0']++;
			break;
		case 3:
			db = *p - '0';
			break;
		}
	}

	int pa = 0, pb = 0;

	for (int i = 0, j = 1; i < count_a[da]; ++i, j *= 10) {
		pa += da * j;
	}
	for (int i = 0, j = 1; i < count_b[db]; ++i, j *= 10) {
		pb += db * j;
	}

	cout << pa + pb;

	return 0;
}