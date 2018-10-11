#include<iostream>

using namespace std;

class ABandC {

private:
	static ABandC* instance;
	int group_count = 0;
	long long** group = nullptr;
	bool* result = nullptr;

public:
	ABandC() {

	}

	~ABandC() {
		delete this->result;
		delete this->group;
	}

	static ABandC* getInstance() {
		if (!ABandC::instance) {
			ABandC::instance = new ABandC();
		}
		return ABandC::instance;
	}
	
	void inputGroupCount() {
		cin >> this->group_count;
		this->group = new long long*[this->group_count];
		this->result = new bool[this->group_count];
	}

	void inputEveryGroupInfo() {
		int a, b, c = 0;
		for (int i = 0; i < this->group_count; ++i) {
			cin >> a >> b >> c;
			this->group[i] = new long long[3];
			this->group[i][0] = a;
			this->group[i][1] = b;
			this->group[i][2] = c;
		}
	}

	void check() {
		for (int i = 0; i < this->group_count; ++i) {
			this->result[i] = (this->group[i][0] + this->group[i][1]) > this->group[i][2];
		}
	}

	void showResult() {
		for (int i = 0; i < this->group_count; ++i) {
			cout << "Case #" << i + 1 << ": " << (this->result[i] ? "true" : "false") << endl;
		}
	}
	
};

ABandC* ABandC::instance = nullptr;

int main() {

	ABandC* abc = ABandC::getInstance();

	abc->inputGroupCount();
	abc->inputEveryGroupInfo();
	abc->check();
	abc->showResult();

	return 0;
}