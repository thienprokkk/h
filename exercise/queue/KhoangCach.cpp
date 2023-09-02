/*viet chuong trinh tinh so buoc can di tu vi tri A den vi tri B
ma tran gom cac so nhi phan 0 va 1
cac o 1 la cac o duoc di, chi duoc di cac o chung canh
in ra so buoc di
neu khong den duoc dich in ra -1*/
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

int dx[4] = {-1, 0, 0, +1};
int dy[4] = {0, -1, +1, 0};

int binaryMatrix[1005][1005];
int steps[1005][1005];
int row, column;

pair<int, int> A, B;

void input();
void output();
int findStep();

int main() {
    input();
    output();
    cout << "enter position of A: "; cin >> A.first >> A.second;
    cout << "enter position of B: "; cin >> B.first >> B.second;
    cout << "the number of steps are " << findStep();
}

void input() {
    cout << "enter row, column respectively: "; cin >> row >> column;
    for (int i = 0; i <= column; i++) binaryMatrix[0][i] = i;
    for (int i = 1; i <= row; i++) binaryMatrix[i][0] = i;
    srand(time(NULL));
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= column; j++) binaryMatrix[i][j] = rand() % 2;
    }
}

void output() {
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= column; j++) cout << binaryMatrix[i][j] << " ";
        cout << endl;
    }
}

int findStep() {
    queue<pair<int, int>> savePosition;

    savePosition.push({A.first, A.second});
    // array steps = 0 so not declare steps[A][A] = 0
    while (savePosition.empty() == false) {
        pair<int, int> top = savePosition.front();
        int indexRow = top.first;
        int indexColumn = top.second;

        savePosition.pop();
        // browse through 4 direction
        for (int k = 0; k < 4; k++) {
            int updateRow = indexRow + dx[k];
            int updateColumn = indexColumn + dy[k];

            if (binaryMatrix[updateRow][updateColumn] == 1 && (updateRow >= 0 && updateRow <= row) && (updateColumn >= 0 && updateColumn <= column)) {
                binaryMatrix[updateRow][updateColumn] = 0;
                if (updateRow == B.first && updateColumn == B.second) return steps[indexRow][indexColumn] + 1; // return step
                // update step and position
                savePosition.push({updateRow, updateColumn});
                steps[updateRow][updateColumn] = steps[indexRow][indexColumn] + 1;
            }
        }
    }
    return -1; // no way
}