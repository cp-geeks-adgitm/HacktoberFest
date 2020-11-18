//The C++ Set is an associative container that contains a sorted set of unique objects.
//Methods of sets are: 
//begin, clear, count, empty, end, equal_range, erase, 
//find, insert, key_comp, lower_bound, max_size, rbegin,
//rend, size, swap, upper_bound, value_comp

#include<iostream>
#include<set>
#include<vector>

using namespace std;

void print_it(set<int>& s){
    for(auto itr = s.begin(); itr != s.end(); itr++) cout << *itr << " ";
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    set<int>s;

    //insert
    //insert the element in set. 
    //runs in log(n)
    s.insert(4);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    s.insert(3);

    //count 
    //return number of occurence of key
    //runs in log(n)
    cout << "occurence of key 3 in s: ";
    cout << s.count(3) << endl;

    //equal_range
    //returns two iterators - one to the first element that contains
    //key, another to a point just after the last element that contains 
    //key.
    //you can also use pair<set<int>::iterator, set<int>::iterator> in-place of
    //auto.
    auto p = s.equal_range(3);
    cout << *p.first << " " << *p.second << endl;
    
    //erase
    //erase the keys from set.

    //syntax 1
    //erase a key by passing iterator.
    s.erase(s.begin());

    //syntax 2
    //erase keys in a range
    s.erase(s.begin(), s.find(3));

    //syntax 3
    //erase a key by passing value
    s.erase(4);

    print_it(s);

    //insert
    //insert keys in the set

    //syntax 1
    //insert range of keys in set
    vector<int>v = {1, 2, 3, 4};
    s.insert(v.begin(), v.end());

    //syntax 2
    //insert a key in s if it doesn't exist in s.
    //The return value is pair of an iterator to the element that need 
    //to insert, and a boolean describing whether an insertion took place.
    auto p1 = s.insert(2);
    cout << "Is value inserted ?\n";
    p1.second ? cout << "yes\n" : cout << "no\n";
    cout << "we can access the key in set using returned iterator: " << *p1.first << endl;

    //lower_bound
    //returns an iterator to the first element which has a value
    //greater than or equal to key.
    //runs in logarithmic time.
    auto ptr = s.lower_bound(3);
    cout << *ptr << endl;

    //rest of the functions are same as practiced earlier
     

}