// Linkedlist implementation with class based handler 
// Author : github.com/dev117uday

#include <iostream>

using namespace std;

// struct Linkedlist
struct linkedlist
{
    int number;
    linkedlist *next;
};

// class to implement handle Linkedlist
class impl_LL
{
    linkedlist *head = nullptr;     // pointer on the head of linkedlist
    linkedlist *guide = nullptr;    // pointer on the end of linkedlist

public:
    void insert(int number)
    {
        auto *ptr = new linkedlist();
        ptr->number = number;
        ptr->next = nullptr;
        // if list is empty
        if (head == nullptr)
        {
            head = ptr;
            guide = ptr;
        }
        else        // if list is not empty
        {
            guide->next = ptr;
            guide = ptr;
        }
    }
    void display()
    {
        linkedlist *ptr = head;

        while (ptr != nullptr)
        {
            cout << ptr->number << " ";
            ptr = ptr->next;
        }
    }
    void insert_begin(int number ) 
    {
        auto *ptr = new linkedlist();
        ptr->number = number;
        ptr->next = head;
        head = ptr;     // changing head to point to the newly add first node
    }
    void insert_end(int number)
    {
        auto *ptr = new linkedlist();
        ptr->number = number;
        guide->next = ptr;
        ptr->next = nullptr;
        guide = ptr;    // changing guide to point to the newly add last node
    }
    void insert_before(int before, int number) 
    {
        if (head->next == nullptr) 
        {
            // if it only contains one node
            insert_begin(number);
        }
        linkedlist *ptr = head;

        while (ptr != nullptr)
        {
            if(ptr->next == nullptr)    // Not found condition
            {
                cout << "\nNot found\n";
                break;
            } 
            else if (ptr->next->number == before)
            {
                auto *new_node = new linkedlist();
                new_node->number = number;
                new_node->next = ptr->next;
                ptr->next = new_node;
                break;
            }
            ptr = ptr->next;
        }
        
    }
    void insert_after(int after, int number) 
    {
        if (head->next == nullptr) 
        {
            insert_end(number);
        }
        linkedlist *ptr = head;

        while (ptr != nullptr)
        {
            if(ptr->next == nullptr)        // Not found condition
            {
                cout << "\nNot found\n";
                break;
            } 
            else if (ptr->number == after)
            {
                if(ptr->next == nullptr){
                    insert_end(number);
                }
                auto *new_node = new linkedlist();
                new_node->number = number;
                new_node->next = ptr->next;
                ptr->next = new_node;
                break;
            }
            ptr = ptr->next;
        }
        
    }
    void delete_begin()
    {
        linkedlist *ptr = head;
        head = head->next;
        delete(ptr);
    }
    void delete_end()
    {
        linkedlist *ptr = head;
        while(ptr != nullptr)
        {
            if (ptr->next->next == nullptr)
            {
                linkedlist *temp = ptr->next;
                guide = ptr;
                ptr->next = nullptr;
                delete(temp);
                break;
            }
            ptr = ptr->next;
        }
    }
    void delete_node (int number) 
    {
        linkedlist *ptr = head;
        while(ptr->next != nullptr)
        {
            if(ptr->next->number == number)
            {
                linkedlist *temp = ptr->next;
                ptr->next = ptr->next->next;
                delete(temp);
                return;
            }
            ptr = ptr->next;
        }
    }
};

int main()
{
    impl_LL LinkedL;
    LinkedL.insert(0);
    LinkedL.insert(1);
    LinkedL.insert(2);
    LinkedL.insert_begin(-1);
    LinkedL.insert_end(3);
    LinkedL.insert_before(1,10);
    LinkedL.insert_after(1,20);
    LinkedL.display();
    cout << "\n";
    LinkedL.delete_begin();
    LinkedL.display();
    cout << "\n";
    LinkedL.delete_end();
    LinkedL.display();
    LinkedL.delete_node(2);
    cout << "\n";
    LinkedL.display();

}
