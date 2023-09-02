#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
// cho 2 so S va T , S, T < 10000
// co 2 thao tac:
// a: S - 1
// b : S * 2
// hay in ra so luong thao tac toi thieu de S == T
/*dung hang doi kieu pair de luu gia tri s va thao tac
thao tac 2 TH xay ra
tao set de loai bo cac so trung nhau
chia dk de luu thao tac
neu s == t return thao tac*/
int findOperation(int S, int T) {
    queue<pair<int, int>> saveOperation;
    set<int> filterNumber;
    
    filterNumber.insert(S);
    saveOperation.push({S, 0});
    while (!saveOperation.empty()) {
        pair<int, int> top = saveOperation.front();
        saveOperation.pop();
        if (top.first == T) return top.second;
        if (top.first * 2 == T || top.first - 1 == T) return top.second + 1;
        if (filterNumber.find(top.first * 2) == filterNumber.end() && top.first < T) {
            saveOperation.push({top.first * 2, top.second + 1});
            filterNumber.insert(top.first * 2);
        }
        if (filterNumber.find(top.first - 1) == filterNumber.end() && top.first > 1) {
            saveOperation.push({top.first - 1, top.second + 1});
            filterNumber.insert(top.first - 1);
        }
    }
    return -1;
}

int main() {
    int S, T;

    cout << "Enter S, T respectively: "; cin >> S >> T;
    assert(S >= 0); assert(T >= 0);
    cout << "Minium number of operations is " << findOperation(S, T);
}