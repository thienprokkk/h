#include <iostream>
#include <vector>
//Object type
    //~vector

//properties
    //vector is dynamic array
    //insert() : can not use reverse iterator
using namespace std;

int main() {
//declare
    vector<int> v(3, 100); //{100, 100, 100}
    vector<int> u(2, 300); //{300, 300}
    int a[3] = {111, 222, 333};
    int res = 0;

//create iterator
    vector<int>::iterator it1;
    auto it2 = v.begin(); //iterator points to first element

//elements access
    //swap
    v.swap(u); //swap u and v
    //at
    v.at(1); //return second element -> 300
    v.at(0); //return first element -> 300
        //v.at(4); //error : because size is 2
    //operator
        //"[]"
        v[1]; //return second element -> 300 : same array : same at()
        v[0]; //return first element -> 300
        v[4]; //return garbage value -> because vector only have 2 elements
        //"="
        v = u; //v copy u
    //front
    v.front(); //return first element -> 100
    //back
    v.back(); //return last element -> 100
    //data
    int* pointer = v.data(); //return a pointer to the first element of data vector != iterator
    cout << "The first element: " << *pointer << endl;

//insert
    //push_back
    v.push_back(1); //add 1 to the end
    //insert
    v.insert(v.begin() ,2); //add 2 to the begin
    v.insert(v.begin() + 1, 3, 200); //add 3 numbers 100 : before the second element
    v.insert(v.begin() + 1, u.begin(), u.end()); //add vector u : before the second element
        v.insert(v.begin(), a, a + 3); //add array a : before the first element
    //emplace
    v.emplace(v.end(), 5); //add 5 : after the last element
    //emplace_back
    v.emplace_back(6); //add 6 to the end
// === 1:::
    //assign
    v.assign(5, 9); //assign vector to {9, 9, 9, 9, 9}
    v.assign({1, 2, 3, 4, 5}); //assign vector to {1, 2, 3, 4, 5}
    v.assign(u.begin(), u.end()); //assign vector to vector u ( v = u)
        v.assign(a, a + 3); //assign vector to array a

//distance
    res = distance(v.begin(), v.end()); //-> return 3 (the numbers of elements [v[0], last element + 1) )
    res = v.end() - v.begin(); //same distance

//print
    cout << "res = " << res << endl;
    //foreach : ranged for loop
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    //iterator
        //way 1
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    //OR : v.at(i)
    }
    cout << endl;
        //way 2
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

// === 2:::
//erase
    //pop_back
    v.pop_back(); //erase the last element
    //erase
    v.erase(v.begin()); //erase the first element
    v.erase(v.begin() + 5, v.end()); //erase [6th element, last element + 1)
    //clear
    v.clear(); //remove all
    //shrink_to_fit

//allocate memory
    //get_allocator

//size
    //size
    v.size(); //-> 0 (current size)
    //empty
    v.empty(); //true (true or false)
    //resize
    v.resize(5); //resize to 5 -> add 5 digits 0 === {0, 0, 0, 0, 0}
    v.resize(9, 8); //resize to 9 -> add 4 digits 8 === {0,.., 0, 8, 8, 8, 8}
        v.resize(6); //resize to 6 -> erase 3 : the last elements
    // //max_size
    v.max_size(); //-> 1073741823 == more than 1 billion 70 million
    //capacity
    v.capacity(); //-> return capacity is provided for vector
    //reserve
    v.reserve(5); //-> return provide a minium of 5 element for vector
}