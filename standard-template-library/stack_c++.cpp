// The C++ Stack is a container adapter that gives the programmer the functionality of a
// stack -- specifically, a FILO (first-in, last-out) data structure.
//stack methods are empty, push, pop, size, top
//push, pop and tops works differently, rest have same functionality
//as we have discussed earlier.
//no support for operator[], begin and end, Hence you can't iterate or 
//print the stack without poping the elements.

#include<iostream>
#include<stack>

using namespace std;

template<class T> 
void print_it(T& st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    freopen("output.txt", "w", stdout);
    stack<int>st;
    
    //push
    //push element at the top of stack.
    //works in constant time.
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);    

    //pop
    //pop the element from the top of stack
    //works in constant time
    st.pop();

    //front
    //return the front element of stueue
    cout << "top element: " << st.top() << "\n";
    cout << "stack :";
    print_it(st);

}