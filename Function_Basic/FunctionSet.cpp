#include <iostream>
#include <set>
//Object type
    //~_Tree

//properties
    //sort elements from smallest to largest
    //the elements are different
    //have not iterator + n
    //iterator ++;
using namespace std;
int main() {
//declare
    set<int> s{1, 4, 3}; //{1, 3, 4}
    set<int> t = {2, 5, 6}; //{2, 5, 6}
    int a[3] = {111, 222, 333};
    int res = 0;

//create iterator
    set<int>::iterator it_2;
    auto it = s.begin();

//elements access
    //find
    it = s.find(1); //-> return iterator points to 1
    it = s.find(2); //because s have not 2 -> return iterator points to last element
    //count
    res = s.count(1); //-> return 1
    res = s.count(2); //-> return 0
    //swap
    swap(s, t); //swap s and t
    s.swap(t); //swap s and t
    //merge
    //operator
        //"="
        s = t; //s copy t
        //"&"
        //"&&"
    //lower_bound
    it = s.lower_bound(5); //-> return iterator points to 5 ( lower bound of 5 >= 5 -> 5 )
    it = s.lower_bound(7); //have not -> return iterator size
    // //upper_bound
    it = s.upper_bound(6); //-> return iterator points to 6 ( upper bound of 5 > 5 -> next element )
    it = s.upper_bound(7); //have not -> return iterator size
    //equal_range
    auto x = s.equal_range(5); //x != iterator
    cout << "The lower bound of 5: " << *x.first << endl; //-> return 5
    cout << "The upper bound of 5: " << *x.second << endl; //-> return 6

//insert
    //insert
    s.insert(4); //add 4
    s.insert(s.begin(), 1); //faster : add 1
    s.insert(a, a + 3); //add array a
    // //emplace
    s.emplace(3); //add 3
    // emplace_hint
    t.emplace_hint(t.begin() , 7); //add 7
    it = t.emplace_hint(t.begin() , 7); //-> return iterator points to 7

//erase
    //erase
    s.erase(4); //erase 4
    s.erase(s.find(6), s.end()); //erase [6, last element + 1)
    s.erase(s.begin(), s.end()); //erase [first element, last element + 1)
    //clear
    s.clear(); //remove all

//print
    cout << *it << endl;
    cout << "res = " << res << endl;
    //foreach : ranged for loop
    cout << "s : ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    //iterator
    cout << "t : ";
    for (auto it = t.begin(); it != t.end(); it++) {
        cout << *it << " ";
    }

//distance
    res = distance(t.begin(), t.find(6)); //-> return 2 (the number of lement [1st element, element 6) )
    cout << "\n" << res;

//compare
    //key_compare

//allocate memory
    //get_allocator

//size
    //size
    s.size(); //-> return 0 (current size)
    //max_size
    s.max_size(); //-> return 214748364 ( more 214 million )
    //empty
    s.empty(); //-> return true (true or false)
}