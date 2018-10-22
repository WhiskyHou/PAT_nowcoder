#include <iostream>
#include <list>

using namespace std;

int main() {
    char input[20];
    cin.getline(input, 20);

    int current = 0;
    bool v1 = true;
    bool v2 = true;
    list<short> number;
    list<short> zhishu;
    for (int i = 0; i < 20; i++) {
        switch (current) {
            case 0:
                v1 = (input[i] == '+');
                current++;
                break;
            case 1:
                if (input[i] != '.' && input[i] != 'E') {
                    number.push_back(input[i] - '0');
                } else if (input[i] == 'E') {
                    current++;
                }
                break;
            case 2:
                v2 = (input[i] == '+');
                current++;
                break;
            case 3:
                if (input[i] != '\0') {
                    zhishu.push_front(input[i] - '0');
                } else
                    current++;
                break;
            case 4:
                break;
        }
    }

    cout << (v1 ? "" : "-");
    short zhishu_num = 0;
    short i = 1;
    for (list<short>::iterator p = zhishu.begin(); p != zhishu.end(); p++) {
        zhishu_num += i * (*p);
        i *= 10;
    }
    for (int i = 0; i < zhishu_num; ++i) {
        if (v2) {
            if (zhishu_num > number.size() - 1) number.push_back(0);
        } else {
            number.push_front(0);
        }
    }
    i = 1;
    for (list<short>::iterator p = number.begin(); p != number.end(); p++) {
        cout << *p;
        if ((!v2 && i == 1) ||
            (v2 && i == zhishu_num + 1 && zhishu_num < number.size() - 1))
            cout << '.';
        i++;
    }

    return 0;
}