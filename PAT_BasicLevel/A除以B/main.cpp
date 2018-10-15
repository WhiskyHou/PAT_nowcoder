//
//  main.cpp
//  cppTest
//
//  Created by Yi Hou on 2018/10/15.
//  Copyright © 2018 Yi Hou. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    char* input = new char[1002];
    cin.getline(input, 1002);
    
    int cound_a = 0;
    for (int i = 0; input[i] != ' '; ++i) {
        cound_a++;
    }
    int b = input[cound_a + 1] - '0';
    
    int size_fragment = 8;
    int count_fragment = cound_a / size_fragment + 1;
    int count_first_fragment = cound_a % size_fragment;
    int yushu = 0;
    string* outlist = new string[count_fragment];
    
    // first fragment
    char* first_fragment = new char[count_first_fragment];
    for (int i = 0; i < count_first_fragment; ++i) {
        first_fragment[i] = input[i];
    }
    string temp = first_fragment;
    int number = stoi(temp);
    outlist[0] = to_string(number / b);
    yushu = number % b;
    
    // other fragments
    for (int i = 0; i < count_fragment - 1; ++i) {
        char* fragment = new char[size_fragment + 1];
        fragment[0] = yushu + '0';
        for (int k = 1; k < size_fragment + 1; ++k) {
            fragment[k] = input[i * size_fragment + count_first_fragment + k - 1];
        }
        string temp = fragment;
        int number = stoi(temp);
        string result = to_string(number / b);
        for (int j = result.length(); j < size_fragment; ++j) {
            result = "0" + result;
        }
        outlist[i+1] = result;
        yushu = number % b;
    }
    
    for (int i = 0; i < count_fragment; ++i) {
        cout << outlist[i];
    }
    cout << " " << yushu;
    
    return 0;
}
