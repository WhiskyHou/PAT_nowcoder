#include<iostream>
#include<iomanip>

using namespace std;

class Mooncake {
public:
	int m = 0;
	int p = 0;
	float pPreM = 0;
};

int main() {
	int number = 0, need_sum = 0;
	float make_sum = 0.0f;
	cin >> number >> need_sum;

	Mooncake* (*mc) = new Mooncake*[number];
	for (int i = 0; i < number; ++i) {
		mc[i] = new Mooncake();
		cin >> mc[i]->m;
	}
	for (int i = 0; i < number; ++i) {
		cin >> mc[i]->p;
		mc[i]->pPreM = (float)mc[i]->p / mc[i]->m;
	}

	for (int i = 0; i < number - 1; ++i) {
		for (int k = 0; k < number - i - 1; ++k) {
			if (mc[k]->pPreM < mc[k + 1]->pPreM) {
				auto temp = mc[k];
				mc[k] = mc[k + 1];
				mc[k + 1] = temp;
			}
		}
	}

	for (int  i = 0; i < number; i++) {
		if (need_sum >= mc[i]->m) {
			make_sum += mc[i]->p;
			need_sum -= mc[i]->m;
		}
		else {
			make_sum += mc[i]->pPreM * need_sum;
			need_sum = 0;
		}

		if (need_sum == 0) break;
	}

	cout << setiosflags(ios::fixed) << setprecision(2) << make_sum;

	return 0;
}