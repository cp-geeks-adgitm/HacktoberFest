#include<iostream>
#include<vector>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    vector<int> v1;
    vector<int> v2(6, 0);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    //assign
    v2.assign(v1.begin(), v1.end()); 
    //this will overwrite the content of v2 with v1.
    //v2 become identical to v1 irrespective of its initial size and values it contain.
    cout << "vector v2: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
    cout << endl;

    //at
    //returns the element at ith position.
    cout << "using at: ";
    for(int i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " "; 
        //unlike v2[i], at throws an exception on vector overrun instead of displaying 
        //garbage value.

    }
    cout << endl;

    //back()
    //return the back value of vector
    cout <<  "using back: " << v2.back() << endl; 

    //front()
    //return the first element of vector
    cout << "using front: "<< v2.front() << endl; 

    //begin()
    //return the iterator to first element of vector
    cout << "using begin: " << *v2.begin() << endl; 

    //end()
    //return the iterator just past the end of vector
    cout << "using end: " <<  *(v2.end() - 1)<< endl; 

    //capacity
    //returns the number of elements that the vector can hold before it
    //will need to allocate more space. Don't confuse it with size, both are different
    cout << "capacity: " << v2.capacity() << endl;
    
    
    //clear
    //deletes the all elements of the vector
    v2.clear();
    cout << "using clear: ";  
    v2.empty() ? cout << "v2 is empty\n": cout << "v2 is not empty\n"  << endl;
    //let us fill v2 again
    v2.assign(v1.begin(), v1.end());
    
    //empty 
    //returns true if vector is empty else returns false.
    cout << "using empty: " << " ";
    v2.empty() ? cout << "v2 is empty\n": cout << "v2 is not empty\n";

    //erase
    //erase the element at specified location or in a range, 
    //it take location in terms of iterator
    //return an iterator to the element after the erased element.
    auto itr = v2.erase(v2.begin()+1);
    cout << "after erasing 2nd element, we get the iterator to the 3rd element i.e: " << *itr  << endl;  

    //insert
    //syntax 1:
    //first argument is the location in term of iterator and second argument is the value you want to insert at that location
    //return the iterator to the inserted element
    cout << "using insert: ";
    cout << "using syntax 1\n";
    auto itr1 = v2.insert(v2.begin()+1, 2);
    cout << "inserted value: "<< *itr1 << endl;
    //syntax 2:
    //first argument is the location in term of iterator
    //second argument is the no. of element you want to insert at that position
    //value of that elements
    cout << "after using syntax 2 and inserting 5, v2 would be\n";
    v2.insert(v2.end(), 1, 5);
    for(int ele: v2){
        cout << ele << " ";
    }
    cout << endl;
    //syntax 3
    //first argument is the location in term of iterator
    //second argument and third argument are the iterator to starting and end of the vector you want to insert.
    v2.insert(v2.end(), v1.begin(), v1.end());
    cout << "after using syntax 3 and inserting v1 in v2, v2 would be\n";
    for(int ele: v2){
        cout << ele << " ";
    }
    cout << endl;

    //pop_back
    //deletes the last element of vector
    v2.pop_back();

    //push_back
    //appends element to the last of vector
    v2.push_back(4);

    //rbegin
    //return a reverse iterator to the end of vector.
    //rend
    //The function rend() returns a reverse_iterator to the beginning of the current vector.
    auto itr3 = v2.rbegin(); 
    cout << "using rbegin & rend for iterating v2 in reverse : ";
    for(itr3; itr3 != v2.rend(); itr3++){
        cout << *itr3 << " ";

    }
    cout << endl;

    //resize
    //resize the vector to specified size, if val is specified 
    //then any newly-created elements will be initialized to have
    //a value of val.
    v2.resize(5);
    cout << "after resizing, v2 would be\n";
    for(int ele: v2){
        cout << ele << " ";
    }
    cout << endl;

    //size()
    //returns the number of elements in the vector
    cout << "size of vector v2: " << v2.size() << endl;

    //swap()
    //swap the content of two vectors
    //works in constant time
    v2.swap(v1);
    cout << "after swapping with v1, v2 would be: ";
    for(int ele: v2){
        cout << ele << " ";
    }
    cout << endl;

}