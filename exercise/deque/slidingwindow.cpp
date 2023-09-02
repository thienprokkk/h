#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;
/*cho day so nguyen N phan tu 
trong moi cua so co kich thuoc k
tim phan phan tu phan lon nhat va in ra phan tu do*/
void slidingWindowMaximum(int arr[], int numberOfArr, int windowSize) {
    deque<int> sieveNumber;

    for (int i = 0; i < windowSize; i++) {
        while (!sieveNumber.empty() && arr[i] >= arr[sieveNumber.back()]) {
            sieveNumber.pop_back();
        }
        sieveNumber.push_back(i);
    }
    cout << arr[sieveNumber.front()] << " ";
    for (int i = windowSize; i < numberOfArr; i++) {
        if (sieveNumber.front() <= i - windowSize) {
            sieveNumber.pop_front();
        }
        while (!sieveNumber.empty() && arr[i] >= arr[sieveNumber.back()]) {
            sieveNumber.pop_back();
        }
        sieveNumber.push_back(i);
        cout << arr[sieveNumber.front()] << " ";
    }
}

void inputAndOutput(int arr[], int numberOfArr) {
    srand(time(NULL));
    for (int i = 0; i < numberOfArr; i++) {
        arr[i] = rand() % 21;
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numberOfArr;
    cout << "enter numberOfArr = "; cin >> numberOfArr;
    int arr[numberOfArr];
    int windowSize;

    cout << "enter windowSize = "; cin >> windowSize;
    inputAndOutput(arr, numberOfArr);
    slidingWindowMaximum(arr, numberOfArr, windowSize);
}