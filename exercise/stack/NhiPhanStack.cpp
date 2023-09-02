#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack<int> NhiPhan;
    cout << "enter n: "; cin >> n;
    while (n != 0) {
        NhiPhan.push(n % 2);
        n /= 2;
    }
    while (!NhiPhan.empty()) {
        cout << NhiPhan.top() << " ";
        NhiPhan.pop();
    }
}