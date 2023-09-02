#include <iostream>
#include <map>
// Object type
//~_Tree

// properties
// sort keys from smallest to largest
// the keys are different
// iterator size can change in the end
// Not iterator + n : YES iterator++ or --

using namespace std;

int main()
{
// declare : (key, val)
    map<int, int> m{{1, 11}, {2, 22}, {3, 33}, {4, 44}};
    map<int, int> n{{5, 55}, {6, 66}, {7, 77}};
    int res = 0;
    int a[3] = {111, 222, 333};

// create iterator pair
    map<int, int>::iterator it_2;
    auto it = m.begin();

// elements access
    // swap
    swap(m, n); //swap m and n
    m.swap(n);  //swap m and n
    // at
    res = m.at(1); //-> return value of key 1 -> 11
        //res = m.at(5); //error (because m have not key 5)
    // count
    res = m.count(1); //-> return 1 (1 or 0)
    res = m.count(5); //-> return 0
    // operator
        //"[]"
        res = m[1]; //-> return value of key 1 -> 11 : same array and at
        res = m[5]; //-> return 0 ( add {5, 0} , because m have not key 5)
        //"="
        m = n; // m copy n
    // find
    it = m.find(5); //-> return iterator pair points to key 5 and value
    it = m.find(9); //-> return iterator size (Key = size, value = garbage value)
    // lower_bound
    it = m.lower_bound(6); //-> return iterator points to key 5 (lower bound of key 5 >= 5)
    it = m.lower_bound(8); //-> return iterator size (KEY = size, Value = garbage value)
    // upper_bound
    it = m.upper_bound(6); //-> return iterator pair to key 7
    it = m.upper_bound(8); //-> return iterator size (KEY = size, Value = garbage value)
    // equal_range
    pair<map<int, int>::iterator, map<int, int>::iterator> mp; // OR auto mp
    mp = m.equal_range(6); // same upper + lower
    cout << "The lower bound of key 6:\n"
         << "Key = " << mp.first->first << "\t"
         << "Value = " << mp.first->first << "\n\n";
    cout << "The upper bound of key 6:\n"
         << "Key = " << mp.second->first << "\t"
         << "Value = " << mp.second->second << "\n\n";

// allocate memory
    // get_allocator

// size
    // size
    res = m.size(); //-> return 3 (current size)
    // max_size
    res = m.max_size(); //-> return 178956970 ( more 178 million )
    // empty
    res = m.empty(); //-> return false ( true or false )

// insert
    // insert
    m.insert({4, 44}); // add {4, 44}
    m.insert(m.begin(), {3, 33});// faster : add {3, 33}
    m.insert(n.begin()++, n.end()--); // add [second element, 2nd last element)
    // emplace
    m.emplace(2, 22); // add {2, 22}
    // emplace_hint
    it = m.emplace_hint(m.begin(), 1, 11); // faster : add {1, 11} and -> return iterator points to key 1
    it = m.emplace_hint(m.begin(), 4, 32); //-> return iterator points to key 4 (because key 4 already exist)

// erase
    // erase
    m.erase(1); //erase key 1
    m.erase(m.find(2)); //erase key 2
        //m.erase(m.end()); //not understand
    m.erase(++m.begin(), --m.end()); //erase [2nd element, the last element)
    // clear
    m.clear(); //remove all

// compare
    // value_comp
    // key_comp

// print
    cout << "Key = " << it->first << "\t"
         << "Value = " << it->second << endl;
    cout << "res = " << res << endl;
    // foreach : ranged for loop
    cout << "Elements m:\n"
         << "KEY\t"
         << "VALUE\n";
    for (pair<int, int> x : m) {
        cout << x.first << "\t" << x.second << endl;
    }
    // iterator
    cout << "Elements n:\n"
         << "KEY\t"
         << "VALUE\n";
    for (auto it = n.begin(); it != n.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
}