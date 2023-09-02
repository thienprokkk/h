#include <iostream>
#include <stack>
using namespace std;
// LIFO

int main() {
// declare
    stack<int> st, st_2;
// elements access
    // swap
    st.swap(st_2);
    // operator=
    st = st_2;
// insert
    st.emplace(4); // them 4 vao top
    st.push(5); // them 5 vao top
// erase
    st.pop(); // xoa 1 top
// size
    st.size(); // return size
    st.empty(); // return true or false
// print
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
