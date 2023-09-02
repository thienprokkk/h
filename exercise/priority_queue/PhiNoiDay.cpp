/*cho N soi day co do dai khac duoc luu trong mang arr[]
noi N soi day thanh 1 sao cho chi phi noi day la nho nhat
biet chi phi noi day bang tong cua 2 soi day a[i] va a[j]
in ra so tien toi thieu do*/
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
// wire : day dien
long long costConnectWire(int wires[], int numberOfWire) {
    long long cost = 0;
    priority_queue<int, vector<int>, greater<int>> saveCost;
    int firstWire, secondWire;

    for (int i = 0; i < numberOfWire; i++) saveCost.push(wires[i]);
    while (saveCost.size() > 1) {
        firstWire = saveCost.top();
        saveCost.pop();
        secondWire = saveCost.top();
        saveCost.pop();
        cost += (long long) (firstWire + secondWire);
        saveCost.push(firstWire + secondWire); // update cost
        // cout << firstWire << " + " << secondWire << " = " << firstWire + secondWire << endl;
    }
    return cost;
}

void inputAndOutputWire(int wires[], int numberOfWire) {
    srand(time(nullptr));
    for (int i = 0; i < numberOfWire; i++) {
        wires[i] = rand() % 21;
        cout << wires[i] << " ";
    }
    cout << "\n";
}

int main() {
    int numberOfWire;
    cout << "enter numberOfWire = "; cin >> numberOfWire;
    int wires[numberOfWire];

    inputAndOutputWire(wires, numberOfWire);
    cout << "The minium cost to connect all wires = " << costConnectWire(wires, numberOfWire);
}