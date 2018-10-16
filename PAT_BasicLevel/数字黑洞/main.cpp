#include<iostream>

using namespace std;

// 忘了这样直接返回局部指针会不会出什么问题了，后面得查查
char* changeToFour(int value) {
	char* result = new char[4];
	for (int i = 3, j = 1; i >= 0; --i, j *= 10) {
		result[i] = (value / j % 10) + '0';
	}
	return result;
}

int changeToDown(char* value) {
	int result = 0;
	for (int i = 0, j = 1; i < 4; ++i, j *= 10) {
		for (int  k = 0; k < 4 - i - 1; ++k) {
			if (value[k] < value[k + 1]) {
				char temp = value[k];
				value[k] = value[k + 1];
				value[k + 1] = temp;
			}
		}
		result += j * (value[3 - i] - '0');
	}
	return result;
}

int changeToUp(char* value) {
	int result = 0;
	for (int i = 0, j = 1; i < 4; ++i, j *= 10) {
		for (int k = 0; k < 4 - i - 1; ++k) {
			if (value[k] > value[k + 1]) {
				char temp = value[k];
				value[k] = value[k + 1];
				value[k + 1] = temp;
			}
		}
		result += j * (value[3 - i] - '0');
	}
	return result;
}

void outPut(int down, int up, int result) {
	for (int i = 0; i < 4; ++i) {
		cout << changeToFour(down)[i];
	}
	cout << " - ";
	for (int i = 0; i < 4; ++i) {
		cout << changeToFour(up)[i];
	}
	cout << " = ";
	for (int i = 0; i < 4; ++i) {
		cout << changeToFour(result)[i];
	}
	cout << endl;
}

int main() {
	int input = 0;
	cin >> input;

	char* array = changeToFour(input);

	if (changeToDown(array) == changeToUp(array)) {
		outPut(changeToDown(array), changeToUp(array), 0);
	}
	else {
		int a = 0, b = 0;
		int result = input;
		while (true) {
			a = changeToDown(changeToFour(result));
			b = changeToUp(changeToFour(result));
			result = a - b;
			outPut(a, b, result);
			if (result == 6174) break;
		}
	}

	return 0;
}