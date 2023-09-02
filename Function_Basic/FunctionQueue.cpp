#include <iostream>
#include <queue>
using namespace std;

int main() {
// declare
    queue<int> q, q1;
// insert
    // emplace
    q.emplace(4); // add 4 vao cuoi
    // push
    q.push(5); // add 5 vao cuoi

// erase
    // pop
    // q.pop(); // erase first elements
// elements access
    // front
    int res = q.front(); // return the first element
    // back
    res = q.back(); // return the last element
    // swap
    q.swap(q1);

// size
    // size
    q.size();
    // empty
    q.empty();
    
// print
    while (q.empty() == false) {
        cout << q.front() << " ";
        q.pop();
    }
}