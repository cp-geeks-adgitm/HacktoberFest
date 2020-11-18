// The C++ Queue is a container adapter that gives the programmer a FIFO (first-in, first-
// out) data structure
//Queue methods are empty, push, pop, size, back, front
//push, pop and front works differently rest have same functionality
//as we have discussed earlier.
//no support for operator[], begin and end, Hence you can't iterate or 
//print the queue without poping the elements.

#include<iostream>
#include<queue>

using namespace std;

template<class T> 
void print_it(T& pq){
    while(!pq.empty()){
        cout << pq.front() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(){
    freopen("output.txt", "w", stdout);
    queue<int>q;
    
    //push
    //push elements at the end of queue.
    //works in constant time.
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);    

    //pop
    //pop the element from the front of queue
    //works in constant time
    q.pop();

    //front
    //return the front element of queue
    cout << "Front element: " << q.front() << "\n";
    cout << "Queue :";
    print_it(q);

}