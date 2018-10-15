#include<iostream>

using namespace std;

int main() {
	int count = 0;
	cin >> count;
	
	char (*data)[2] = new char[count][2];
	for (int i = 0; i < count; i++) {
		cin >> data[i][0] >> data[i][1];
	}

	int aWinCount[3] = { 0 };
	int bWinCount[3] = { 0 };
	int pingju = 0;
	for (int i = 0; i < count; i++) {
		if (data[i][0] == data[i][1])pingju++;
		else {
			if (data[i][0] == 'C') {
				if (data[i][1] == 'J')aWinCount[1]++;
				else bWinCount[0]++;
			}
			else if (data[i][0] == 'J') {
				if (data[i][1] == 'B')aWinCount[2]++;
				else bWinCount[1]++;
			}
			else if (data[i][0] == 'B') {
				if (data[i][1] == 'C')aWinCount[0]++;
				else bWinCount[2]++;
			}
		}
	}
	char dic[3] = { 'B', 'C' ,'J' };
	int x = 0, y = 0;
	int aSum = 0, bSum = 0;
	for (int i = 0; i < 3; ++i) {
		if (aWinCount[i] > aWinCount[x]) x = i;
		if (bWinCount[i] > bWinCount[y]) y = i;
		aSum += aWinCount[i];
		bSum += bWinCount[i];
	}
	cout << aSum << " " << pingju << " " << bSum << endl;
	cout << bSum << " " << pingju << " " << aSum << endl;
	cout << dic[x] << " " << dic[y];

	return 0;
}