#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 1 = 1
    // 2 = 10
        // 4 = 100
            // 8 = 1000
            // 9 = 1001
        // 5 = 101
            // 10 = 1010
            // 11 = 1011
    // 3 = 11
        // 6 = 110
            // 12 = 1100
            // 13 = 1101
        // 7 = 111
            // 14 = 1110
            // 15 = 1111
vector<string> res;

void init() {
    queue<string> qu;
    res.push_back("1");
    qu.push("1");
    while (res.size() < 10000) {
        string top = qu.front();
        res.push_back(top + "0");
        res.push_back(top + "1");
        qu.pop();
        qu.push(top + "0");
        qu.push(top + "1");
    }
}

int main() {
    init();
    int n;
    cout << "enter n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << res.at(i) << " ";
    }
}