//Unlike vectors, contiguous storage allocation may not be
//guaranteed.
//Double Ended Queues are basically an implementation of the data structure double 
//ended queue.

// Random access - constant O(1), operator[] for random accessing elements is available.
// Insertion or removal of elements at the end or beginning - constant O(1)
// Insertion or removal of elements - linear O(n)

//Apart from push_front and pop_front, Deque use the same methods as of array.
//So, we will see how to use push_front and pop_front only, for rest you can refer  
//to vector.

#include<iostream>
#include<deque>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    deque<int> deq(5, 0); //initialising deque with zeroes.
    cout << "deque: ";
    for (int i = 0; i < 5; i++){
        cout << deq[i] << " ";
    }
    cout << endl;

    //push_front;
    deq.push_front(-1);
    deq.push_front(-2);

    //pop_front
    deq.pop_front();

    cout << "deque: ";
    for (int i = 0; i < 5; i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;
}