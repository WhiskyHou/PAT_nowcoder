#include<iostream>
#include<stack>
#include<string>

using namespace std;

string addWhiteSpace(string str, int maxLength, int n) {
	for (int i = 0; i < ((maxLength - (2 * n - 1)) / 2); i++) {
		str = " " + str;
	}
	return str;
}

string buildString(string ch, int n) {
	string str = ch;
	for (int i = 1; i < n; i++) {
		str = str + ch + ch;
	}
	return str;
}

int main() {
	int num;
	string ch;
	cin >> num >> ch;

	int n = 0, yu = 0;
	for (int i = 1; ; i++) {
		if (i * i * 2 - 1 > num) {
			break;
		}
		else {
			n = i;
			yu = num - (i * i * 2 - 1);
		}
	}

	int maxLength = 2 * n - 1;
	stack<string> sta;
	for (int i = n; i > 0; i--) {
		string str = addWhiteSpace(buildString(ch, i), maxLength, i);
		sta.push(str);
		cout << str << endl;
	}
	sta.pop();
	while (!sta.empty()) {
		string str = sta.top();
		sta.pop();
		cout << str << endl;
	}
	
	cout << yu;

	return 0;
}
