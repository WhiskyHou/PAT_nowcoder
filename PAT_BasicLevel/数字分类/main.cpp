#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {
	int count = 0;
	cin >> count;
	int* data = new int[count];
	
	for (int i = 0; i < count; ++i) {
		cin >> data[i];
	}
	

	int result1 = 0;

	int result2 = 0;
	bool isAdd = true;
	int count2 = 0;

	int result3 = 0;

	int sum4 = 0;
	int count4 = 0;

	int max5 = 0;

	for (int i = 0; i < count; ++i) {
		// for 1
		if (data[i] % 10 == 0) {
			result1 += data[i];
		}

		// for 2
		if (data[i] % 5 == 1) {
			result2 += isAdd ? data[i] : -data[i];
			isAdd = !isAdd;
			count2++;
		}

		// for 3
		if (data[i] % 5 == 2) {
			result3++;
		}

		// for 4
		if (data[i] % 5 == 3) {
			sum4 += data[i];
			count4++;
		}

		// for 5
		if (data[i] % 5 == 4) {
			max5 = (data[i] > max5) ? data[i] : max5;
		}
	}

	double result4 = ((double)sum4 / count4);

	cout << ((result1 == 0) ? "N" : to_string(result1)) << " "
		<< ((count2 == 0) ? "N" : to_string(result2)) << " "
		<< ((result3 == 0) ? "N" : to_string(result3)) << " ";
	if (count4 == 0) cout << "N" << " ";
	    else cout << fixed << setprecision(1) << result4 << " ";
	cout << ((max5 == 0) ? "N" : to_string(max5));
	
	return 0;
}