// Stack implementation with class based handler 
// Author : github.com/dev117uday

#include <iostream>

using namespace std;

struct Stack {
    int number;
    Stack *next;
};

class ImplStack {
    Stack *top;
    int counter;
public:
    ImplStack(){
        this->top = nullptr;
        counter = 0;
    }
    void empty_message(){
        cout << "Stack is empty \n";
    }
    void push(int number) {
        auto *pStack = new Stack();
        pStack->number = number;
        if (this->top == nullptr){
            pStack->next = nullptr;
            top = pStack;
            counter++;
        } else {
            pStack->next = top;
            top = pStack;
            counter++;
        }
    }
    void display(){
        Stack *ptr = this->top;
        if (empty()) {
            cout << "Stack is empty \n";
            return;
        }
        while (ptr != nullptr){
            cout << ptr->number << "\n";
            ptr = ptr->next;
        }
    }
    bool empty(){
        Stack *ptr = this->top;
        if (ptr == nullptr){
            return true;
        } else {
            return false;
        }
    }
    void topOfStack(){
        if (empty()) {
            empty_message();
        } else {
            cout << "Top : " << this->top->number << endl;
        }
    }
    void pop(){
        if (empty()) {
            empty_message();
        }
        Stack *ptr = this->top;
        this->top = ptr->next;
        cout << "Popping : " << ptr->number << endl;
        delete ptr;
    }
};

int main(){
    ImplStack stack1;
    stack1.push(0);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.display();
    stack1.topOfStack();
    stack1.pop();
    stack1.pop();
    stack1.topOfStack();
    stack1.display();
}
