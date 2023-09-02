#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next; // save pointer to next element
};

typedef Node *node; // declare con tro kieu Node
// cap phat dong cho node moi voi du lieu la so nguyen x
node makeNode(int x) {
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

bool empty(node a) {
    return a == nullptr;
}

int size(node a) {
    int count = 0;
    while (a != nullptr) {
        ++count;
        a = a->next;
    }
    return count;
}

void push_front(node &a, int x) { // phai them reference
    node tmp = makeNode(x);
    if (a == nullptr) {
        a = tmp;
    }
    else {
        tmp->next = a;
        a = tmp;
    }
}

void push_back(node &a, int x) {
    node tmp = makeNode(x);
    if (a == nullptr) {
        a = tmp; // bat buoc phai truyen tham chieu
    }
    else {
        node p = a;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void insert(node &a, int x, int pos) {
    int numberOfNode = size(a);
    if (pos <= 0 || pos > numberOfNode + 1) { // pos > n + 1 hay n
        cout << "error"; return;
    }
    if (numberOfNode == 1) { // add vao dau
        push_front(a, x); return;
    }
    if (pos == numberOfNode - 1) {
        push_back(a, x); return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    } // p dang o truoc vi tri pos
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

void pop_front(node &a) {
    if (a == nullptr) return;
    a = a->next;
}

// void pop_back(node &a) {
//     if (a == nullptr) return;
//     node p = a;
//     int numberOfNode = size(a);
//     for (int i = 1; i < numberOfNode - 1; i++) {
//         p = p->next;
//     }
//     p->next = nullptr;
// }

void pop_back(node &a) {
    if (a == nullptr) return;
    node first = nullptr, last = a;
    while (last->next != nullptr) {
        first = last;
        last = last->next;
    }
    if (first == nullptr) { // co 1 element
        a = nullptr;
    }
    else {
        first->next = nullptr;
    }
}

void erase(node &a, int pos) {
    int numberOfNode = size(a);
    if (pos <= 0 || pos > numberOfNode + 1) {
        cout << "error"; return;
    }
    node first = nullptr, last = a;
    for (int i = 1; i < pos; i++) {
        first = last;
        last = last->next;
    } // last trung vs vi tri muon xoa
    if (first == nullptr) a = a->next; // xoa vi tri dau tien
    else {
        first->next = last->next;
    }
}

void print(node a) {
    cout << "------------------" << endl;
    while (a != nullptr) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << "\n------------------" << endl;
}

int main() {
// create head node
    node head = nullptr;

    // pointer auto 4 bye for computer 64-bit
    // push_back(head, 6);
    // push_front(head, 5);
    // insert(head, 4, 2);
    print(head);
    cout << size(head) << endl;
}