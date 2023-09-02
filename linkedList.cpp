#include <iostream>
using namespace std;
// 1.createNode
// 2.size
// 3.empty
// 4.insert
// 5.push_back
// 6.push_front
// 7.erase
// 8.pop_back
// 9.pop_front
// 10.printList
// sortList

struct Node {
    int data;
    Node *next;
};

typedef Node *node;

node createNode(int x) {
    node newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

bool empty(node headNode) {
    return headNode == nullptr;
}

int size(node headNode) {
    int nodeCount = 0;
    while (headNode != nullptr) {
        nodeCount++;
    }
    return nodeCount;
}

void push_front(node &headNode, int x) {
    node newNode = createNode(x);
    if (headNode == nullptr) {
        headNode = newNode;
    }
    else {
        newNode->next = headNode;
        headNode = newNode;
    }
}

void push_back(node &headNode, int x) {
    node newNode = createNode(x);
    if (headNode == nullptr) {
        headNode = newNode;
    }
    else {
        node updateNode = headNode;
        while (updateNode->next != nullptr) {
            updateNode = updateNode->next;
        }
        updateNode->next = newNode;
    }
}

void insert(node &headNode, int x, int position) {
    int numberOfNode = size(headNode);
    if (position <= 0 || position > numberOfNode + 1) {
        cout << "error ! No position" << endl;
        return;
    }
    if (position == 1) {
        push_front(headNode, x);
    }
    else if (position == numberOfNode - 1) {
        push_back(headNode, x);
    }
    else {
        node newNode = createNode(x);
        node updateNode = headNode;
        for (int i = 0; i < position - 2; i++) {
            updateNode = updateNode->next;
        }
        newNode->next = updateNode->next;
        updateNode->next = newNode;
    }
}

void pop_front(node &headNode) {
    if (headNode == nullptr) return;
    headNode = headNode->next;
}

void pop_back(node &headNode) {
    node firstNode = nullptr, lastNode = headNode;
    while (lastNode->next != nullptr) { // loop stop when lastNode = the last node
        firstNode = lastNode;
        lastNode = lastNode->next;
    }
    firstNode->next = nullptr;
}

void erase(node &headNode, int position) {
    int numberOfNode = size(headNode);
    if (position <= 0 || position > numberOfNode - 1) return;
    if (position == 1) {
        pop_front(headNode);
    }
    else if (position == numberOfNode - 1) {
        pop_back(headNode);
    }
    else {
        node firstNode = nullptr, lastNode = headNode;
        for (int i = 0; i < position - 1; i++) {
            firstNode = lastNode;
            lastNode = lastNode->next;
        }
        firstNode->next = lastNode->next;
    }
}

void printList(node headNode) {
    cout << "# ";
    while (headNode != nullptr) {
        cout << headNode->data << " ";
        headNode = headNode->next;
    }
    cout << "#\n";
}

void sortList(node &headNode) {
    for (node i = headNode; i->next != nullptr; i = i->next) {
        node minNode = i;
        for (node j = i->next; j != nullptr; j = j->next) {
            if (minNode->data > j->data) {
                minNode = j; // save node have minium value
            }
        }
        int saveData = minNode->data;
        minNode->data = i->data;
        i->data = saveData;
    }
}
//
void insertList(node &headNode, int choose) {
    int value, position;
    cout << "value: "; cin >> value;
    switch (choose) {
        case 1:
            cout << "position: "; cin >> position;
            insert(headNode, value, position);
            break;
        case 2:
            push_front(headNode, value);
            break;
        case 3:
            push_back(headNode, value);
    }
}

int chooseInsert() {
    cout << "\t1. insert position" << endl;
    cout << "\t2. push front: " << endl;
    cout << "\t3. push back: " << endl;
    cout << "chooseInsert: ";
    int choose; cin >> choose;
    return choose;
}

void deleteList(node &headNode, int choose) {
    switch (choose) {
        case 1:
            int position;
            cout << "position: "; cin >> position;
            erase(headNode, position);
            break;
        case 2:
            pop_front(headNode);
            break;
        case 3:
            pop_back(headNode);
    }
}

int chooseDelete() {
    cout << "\t1. delete position" << endl;
    cout << "\t2. pop front: " << endl;
    cout << "\t3. pop back: " << endl;
    cout << "chooseInsert: ";
    int choose; cin >> choose;
    return choose;
}

int main() {
    node headNode = nullptr;
    cout << "1. check if the list is empty" << endl;
    cout << "2. size of the list" << endl;
    cout << "3. insert data to the list" << endl;
    cout << "4. delete data of the list" << endl;
    cout << "5. sort the list" << endl;
    cout << "6. print the list" << endl;
    cout << "7. end the list" << endl;
    while (true) {
        int choose = 0;
        cout << "YOUR'CHOOSES: "; cin >> choose;
        switch (choose) {
            case 1:
                if (empty(headNode)) cout << "Empty" << endl;
                else cout << "Not empty" << endl;
                break;
            case 2:
                cout << "the size of list is " << size(headNode) << endl;
                break;
            case 3:
                choose = chooseInsert();
                insertList(headNode, choose);
                break;
            case 4:
                choose = chooseDelete();
                deleteList(headNode, choose);
                break;
            case 5:
                sortList(headNode);
                break;
            case 6:
                printList(headNode);
                break;
            case 7:
                cout << "okay, the list has ended";
        }
        if (choose == 7) break;
    }
}