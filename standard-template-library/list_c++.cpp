//Lists are sequences of elements stored in a linked list. Compared to vectors, they allow
//fast insertions and deletions, but slower random access.
//merge, sort, remove, remove_if, splice and unique, these are unique 
//methods of list. Rest methods are as of vectors.

#include<iostream>
#include<list>
using namespace std;

void print_it(list<int> &lis){
    for(int ele: lis){
        cout << ele << " ";
    }
    cout << endl;

}

bool remove_odd(const int &ele){
    return ele%2;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    list<int> lis1, lis2;
    lis1.push_back(2);
    lis1.push_back(4);
    lis1.push_back(6);
    lis1.push_back(8);
    cout << "list: ";
    print_it(lis1);

    //Note: operator[] for random accessing elements don't work in list because it's implemented
    //using linked list. Although, you can use iterator approach or syntax that I used in print_it function above.
    
    //merge
    //merges two sorted lists (sorted lists are prerequisite).
    //merged lis i.e lis2 get empty after merging.
    lis2.push_back(1);
    lis2.push_back(3);
    lis2.push_back(5);
    lis2.push_back(6);
    lis1.merge(lis2);
    print_it(lis1);
    lis2.empty()?cout << "lis2 is empty":cout << "lis2 is not empty";
    cout << endl;

    //sort
    //sort the list in nlogn time.
    lis1.sort(greater<int>());
    print_it(lis1);

    //remove
    //remove all elements that are equal to specified element
    //runs in linear time
    lis1.remove(6);
    cout << "After removing all 6's lis1 would be: ";
    print_it(lis1);

    //remove_if
    //removes all elements that returns true on passing to unary function
    //runs in linear time
    lis1.remove_if(remove_odd);
    print_it(lis1);

    //reverse
    //reverse the list
    //runs in linear time
    lis1.reverse();
    cout << "On reversing : ";
    print_it(lis1);
    // cout << lis1[1];

    //splice 
    //transfer list, elements from another list into the list.
    //splice() simply moves elements from one list to another, and doesn't actually do any copying or
    //deleting. Because of this, splice() runs in constant time.
    //
    //syntax 1
    //To transfer complete list into another at a specified position.
    //first argument is the location where insertion requires.
    //second argument is the list to be inserted
    lis2.splice(lis2.begin(), lis1);
    cout << "using syntax 1 of splice to transfer lis1 to lis2:\n";
    cout << "lis2: ";
    print_it(lis2);
    cout << "lis1: ";
    print_it(lis1);
    
    //syntax 2
    //if you want to transfer an element from the lis2 then pass the location of 
    //the element as extra argument to lis
    lis1.splice(lis1.begin(), lis2, lis2.begin());
    cout << "lis1: ";
    print_it(lis1);

    //syntax 3
    //if you want to transfer multiple elements just pass the starting and ending position
    lis1.splice(lis1.begin(), lis2, lis2.begin(), lis2.end());
    cout << "lis1: ";
    print_it(lis1);

    //unique
    //removes all consecutive duplicate elements. 
    //Note that only consecutive duplicates are removed, which may require that you sort() the list first.
    



    
    
    
    
}