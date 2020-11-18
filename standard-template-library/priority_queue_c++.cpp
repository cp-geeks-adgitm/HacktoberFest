//Priority queues are a type of container adapters, specifically designed such that the first 
//element of the queue is the greatest of all elements in the queue and elements are in non increasing order

//empty, pop, push, size, top are methods of priority queue

// Time Complexity:
// empty: O(1)
// pop: O(2*log(n))
// push: O(log(n))
// size: O(1)
// top: O(1)
//making priority queue by pushing n elements: O(n*log(n))
//making priority queue by passing vector as container parameter: O(n)
//no support for operator[], begin and end.Hence you can't iterate or 
//print the priority queue without poping the elements.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<class T> 
void print_it(T& pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    freopen("intput.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int>v;
    //max_heap in O(n*log(n))
    cout << "max_heap in O(n*log(n)): ";
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    print_it(pq);
    //max_heap in O(n)
    cout << "max_heap in O(n): ";
    priority_queue<int>pq1(v.begin(), v.end()); 
    print_it(pq1);
    
    //min_heap in O(n*log(n))
    //For min_heap, pass the container and comparator while declaring priority queue 
    cout << "min_heap in O(n*log(n)): ";
    priority_queue<int, vector<int>, greater<int> > pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);
    print_it(pq2);
    //min_heap in O(n)
    cout << "min_heap in O(n): ";
    priority_queue<int, vector<int>, greater<int> >pq3(v.begin(), v.end());
    print_it(pq3);

    //empty
    //returns true if priority_queue is empty else false
    pq.empty() ? cout << "pq is empty\n": cout << "pq is not empty";

    //push
    //add an element to the end of the queue
    pq.push(1);

    //top
    //returns the top element in queue;
    cout << "top element: "<<pq.top();

    //pop
    //pop the top element from the queue
    pq.pop();




}



