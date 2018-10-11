#include<iostream>
 
using namespace std;
 
void output(int value) {
    static int index = 0;
    index++; 
    (index % 10 == 0) ? (cout << " " << value << endl) : ((index % 10 == 1) ? (cout << value) : (cout << " " << value));
}
 
void createArray(int* data, int n) {
    int index = 1;
    for (int i = 2; ; ++i) {
        bool isSushu = true;
        for (int k = 1; k < index; ++k) {
            if (i%data[k] == 0) {
                isSushu = false;
                break;
            }
        }
 
        if (isSushu) data[index++] = i;
         
        if (index >= n) break;
    }
}
 
int main() {
    int m = 1;
    int n = 1;
    cin >> m >> n;
 
    int* data = new int[n+1];
    for (int i = 0; i < n; ++i) {
        data[i] = 0;
    }
    createArray(data, n+1);
 
    for (int i = m; i < n+1; ++i) {
        output(data[i]);
    }
 
    return 0;
}