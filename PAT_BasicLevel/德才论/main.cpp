#include<iostream>
#include<vector>

using namespace std;

class Student {
public:
	int id = 0;
	int d_score = 0;
	int c_score = 0;

	Student(int id, int d, int c) :id(id), d_score(d), c_score(c) {}
};

void sort(vector<Student*>& list) {
	if (list.size() == 0) return;
	for (int i = 0; i < list.size() - 1; ++i) {
		for (int j = 0; j < list.size() - 1 - i; ++j) {
			if ((list[j]->d_score + list[j]->c_score) < (list[j + 1]->d_score + list[j + 1]->c_score)) {
				Student* temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			else if ((list[j]->d_score + list[j]->c_score) == (list[j + 1]->d_score + list[j + 1]->c_score)) {
				if (list[j]->d_score > list[j + 1]->d_score) continue;
				else if ((list[j]->d_score == list[j + 1]->d_score) && (list[j]->id < list[j + 1]->id)) continue;

				Student* temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void print(vector<Student*>& list) {
	for (vector<Student*>::iterator p = list.begin(); p != list.end(); p++) {
		cout << (*p)->id << " " << (*p)->d_score << " " << (*p)->c_score << endl;
	}
}

int main() {
	int number = 0;
	int min_score = 0;
	int good_line = 0;
	cin >> number >> min_score >> good_line;

	Student** students = new Student*[number];
	for (int i = 0; i < number; ++i) {
		int id, d, c;
		cin >> id >> d >> c;
		students[i] = new Student(id, d, c);
	}

	int out_count = 0;
	vector<Student*> DandC;
	vector<Student*> DwinC;
	vector<Student*> CwinD;
	vector<Student*> DoutC;
	for (int i = 0; i < number; ++i) {
		if (students[i]->d_score < min_score || students[i]->c_score < min_score) {
			out_count++;
			continue;
		}

		if (students[i]->d_score >= good_line) {
			if (students[i]->c_score >= good_line) {
				DandC.push_back(students[i]);
			}
			else {
				DwinC.push_back(students[i]);
			}
		}
		else {
			if (students[i]->d_score >= students[i]->c_score) {
				DoutC.push_back(students[i]);
			}
			else {
				CwinD.push_back(students[i]);
			}
		}
	}

	sort(DandC);
	sort(DwinC);
	sort(DoutC);
	sort(CwinD);

	cout << number - out_count << endl;
	print(DandC);
	print(DwinC);
	print(DoutC);
	print(CwinD);

	return 0;
}