#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    Node*top;

    public:
    Stack() { top = NULL;}

    void push(int data){
        Node * temp = new Node(data);

        if (!temp){
            exit(1);
        }
        temp->data = data;
        temp->next = top;

        top = temp;
    }

    bool empty(){
        return top == NULL;
    }

    int topVal(){
        if(top == NULL) {
            cout << "Stack is empty. Cannot get the top element." << endl;
            return -1;
        }
        return top->data;
    }

    void pop(){
       if (top == NULL) {
        cout << "Stack is empty. Cannot pop." << endl;
        return;
    }

    Node* temp = top;  
    top = top->next;  
    delete temp;    
    }

    void print(){
        if(top){
            while(top!=NULL){
            cout << top->data << " ";
            top = top->next;
            }
        }
    }
};

int main()
{
    // Creating a stack
    Stack s;
 
    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
 
    // Display stack elements
    s.print();
 
    // Print top element of stack
    cout << "\nTop element is " << s.topVal() << endl;
 
    // Delete top elements of stack
    s.pop();
    s.pop();
 
    // Display stack elements
    s.print();
      // Print top element of stack
    cout << "\nTop element is " << s.topVal() << endl;
 
    return 0;
}