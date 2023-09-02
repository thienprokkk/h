#include <oistream>
#include <queue>
using namespace std;

int main() {
// declare
    priority_queue<int> pq;
// elements access
    pq.top();
    pq.swap();
// insert
    pq.emplace();
    pq.push();
// erase
    pq.pop();
// size
    pq.empty();
    pq.size();
}