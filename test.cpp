#include <iostream>
using namespace std;

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

int main() {
    node headNode = nullptr;
    push_back(headNode, 5);
    printList(headNode);
}