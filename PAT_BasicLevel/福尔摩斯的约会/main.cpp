#include<iostream>
#include<string>

using namespace std;

static string weekdays[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {
	char data[4][61];
	cin.getline(data[0], 61);
	cin.getline(data[1], 61);
	cin.getline(data[2], 61);
	cin.getline(data[3], 61);

	int weekday = -1;
	int hour = -1;
	int hour_check = 0;
	for (int i = 0; i < 61; ++i) {
		if (data[0][i] == data[1][i] && data[0][i] >= 'A' && data[0][i] <= 'Z') {
			if (weekday == -1) { 
				weekday = data[0][i] - 'A';
				hour_check++;
				continue;
			}
		}
		if (data[0][i] == data[1][i]) {
			if (hour_check == 1) {
				if (data[0][i] >= 'A' && data[0][i] <= 'N') hour = data[0][i] - 'A' + 10;
				else hour = data[0][i] - '0';
				break;
			}
		}
	}
	int min = -1;
	for (int j = 0; j < 61; ++j) {
		if (data[2][j] == data[3][j] && ((data[2][j] >= 'A' && data[2][j] <= 'Z') || (data[2][j] >= 'a' && data[2][j] <= 'z'))) {
			min = j;
			break;
		}
	}

	cout << weekdays[weekday] << " ";
	(hour < 10) ? (cout << "0" << hour << ":") : (cout << hour << ":");
	(min < 10) ? (cout << "0" << min) : (cout << min);

	return 0;
}