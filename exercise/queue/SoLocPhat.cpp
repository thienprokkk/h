#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// tim cac so loc phat co it hon N chu so
// N <= 15
// so loc phat la cac so chi co 2 chu so la 6 va 8
// liet ke theo thu tu giam dan
using ll = long long;

vector<string> soLocPhats;

void filterSoLocPhat() {
    queue<string> digit;

    digit.push("6");
    digit.push("8");
    soLocPhats.push_back("6");
    soLocPhats.push_back("8");
    while (true) {
        string top = digit.front();
        digit.pop();
        if (top.length() == 15) break;
        soLocPhats.push_back(top + "6");
        soLocPhats.push_back(top + "8");
        digit.push(top + "6");
        digit.push(top + "8");
    }
}

int main(void) {
    int numberOfCase;
    int lengthOfNumber;

    filterSoLocPhat();
    reverse(soLocPhats.begin(), soLocPhats.end());
    cout << "enter numberOfCase = "; cin >> numberOfCase;
    while (numberOfCase--) {
        cout << "enter lengthOfNumber = "; cin >> lengthOfNumber;
        for (string x : soLocPhats) {
            if (x.length() > lengthOfNumber) continue;
            else if (x.length() == lengthOfNumber) {
                cout << x + " ";
                continue;
            }
            else break; // stop if length == lengthOfNumber - 1
        }
        cout << endl;
    }
}