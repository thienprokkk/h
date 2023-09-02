/*cho xau a[] gom cac chu cai in hoa [A, B,...Z]
people define value of string equal to plus
binh phuong so lan xuat hien cua 1 ki tu trong xau
hay tim gia tri nho nhat cua xau sau khi
loai bo K ki tu*/
#include <iostream>
#include <map>
#include <cstdlib>
#include <queue>
#include <ctime>
#include <string>
using namespace std;
// A: 65, Z: 90
void inputAndOutputString(string &upperCases, map<char, int> &repetitionsCount, int numberOfUpperCase) {
    srand(time(nullptr));
    for (int i = 0; i < numberOfUpperCase; i++) {
        upperCases.push_back(char(rand() % 26 + 65)); // random A -> Z
        repetitionsCount[upperCases[i]]++;
        cout << upperCases[i] << " ";
    }
    cout << endl;
    cout << "KEY\t" << "times" << endl;
    for (pair<char, int> x : repetitionsCount) {
        cout << x.first << "\t" << x.second << endl;
    }
}

long long valueString(map<char, int> repetitionsCount, int numberOfErase) {
    priority_queue<int> saveRepetitions;
    long long value = 0;

    for (pair<char, int> x : repetitionsCount) saveRepetitions.push(x.second);
    while (numberOfErase--) {
        int x = saveRepetitions.top();
        saveRepetitions.pop();
        --x;
        saveRepetitions.push(x);
    }
    if (saveRepetitions.top() < 1) return 0; // special case : all number equal to 0 or < 0
    while (!saveRepetitions.empty()) {
        value += (long long) saveRepetitions.top() * saveRepetitions.top();
        saveRepetitions.pop();
    }
    return value;
}

int main() {
    string upperCases;
    map<char, int> repetitionsCount;
    int numberOfUpperCase;
    int numberOfErase;
    cout << "enter number of upperCases = "; cin >> numberOfUpperCase;

    inputAndOutputString(upperCases, repetitionsCount, numberOfUpperCase);
    cout << "enter number of erase = "; cin >> numberOfErase;
    cout << "the minium value of string = " << valueString(repetitionsCount, numberOfErase);
}