#include <iostream>
#include <deque>
using namespace std;

int main() {
// declare
    deque<int> d, q;
// elements access
    // assign
    d.assign();
    d.at();
    d.back();
    d.front();
    d[0];
    d = q;
    d.swap();
// insert
    d.insert();
    d.emplace();
    d.emplace_back();
    d.emplace_front();
    d.push_back();
    d.push_front();
// erase
    d.erase();
    d.clear();
    d.pop_back();
    d.pop_front();
// size
    d.size();
    d.max_size();
    d.resize();
    d.shrink_to_fit();
// allocator memory
    d.get_allocator();
}