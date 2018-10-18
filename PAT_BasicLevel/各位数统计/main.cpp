#include<iostream>

using namespace std;

int main() {
	char input[1001];
	cin.getline(input, 1001);

	int count[10] = { 0 };
	for (int i = 0; input[i] != '\0'; ++i) {
		count[input[i] - '0']++;
	}
	for (int i = 0; i < 10; ++i) {
		if (count[i] != 0) {
			cout << i << ":" << count[i] << endl;
		}
	}

	return 0;
}