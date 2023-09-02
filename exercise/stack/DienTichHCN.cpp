#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "enter n: "; cin >> n;
    int e[n], S = INT16_MIN, height, i = 0;
    stack<int> shape;
    for (int &x : e) {
        cin >> x;
    }
    while (i < n) {
        if (shape.empty() == true || e[i] >= e[shape.top()]) {
            shape.push(i);
            i++; // chi ra chi so truoc hinh do
        }
        else {
            height = shape.top(); // luu chi so cua hinh muon tinh S
            shape.pop(); // xoa chi so de xuat hien chi so hinh phia sau
            if (shape.empty() == true) {
                S = max(S, e[height] * i); // chieu rong = i
            }
            else {
                S = max(S, e[height] * (i - shape.top() - 1)); // chieu rong = chi so - chi so hinh phia sau - 1
            }
        }
    } // ket thuc khi den phan tu cuoi cung i = n
    while (shape.empty() == false) {
        height = shape.top();
        shape.pop();
        if (shape.empty() == true) {
            S = max(S, e[height] * n); // TH: first element <= all elements
        }
        else {
            S = max(S, e[height] * (n - shape.top() - 1)); // TH: lenght chay den vi tri cuoi cung
        }
    }
    cout << "Max S = " << S << endl;
}