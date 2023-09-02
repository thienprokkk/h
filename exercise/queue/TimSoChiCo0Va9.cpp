#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
// tim cac so chi co chua 2 chu so 9 va 0 chia het cho cac so tu 1 den N, N <= 100;
using ll = long long;

vector<ll> saveDigit;
ll arr[101];

void filterDigit(int numberOfArr) {
    queue<string> digit;
    digit.push("9");
    saveDigit.push_back(9);
    while (true) {
        string top = digit.front();
        digit.pop();
        if (top.length() == 12) break;
        digit.push(top + "0");
        digit.push(top + "9");
        saveDigit.push_back(stoll(top + "0"));
        saveDigit.push_back(stoll(top + "9"));
    }
    for (int i = 1; i <= numberOfArr; i++) {
        for (ll x : saveDigit) {
            if (x % i == 0) {
                arr[i] = x;
                break;
            }
        }
    }
}

int main() {
    int numberOfArr;
    cout << "Enter numberOfArr = "; cin >> numberOfArr;

    filterDigit(numberOfArr);
    for (int i = 1; i <= numberOfArr; i++) {
        cout << i << "\t" << arr[i] << endl;
    }
}