#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node * newNode = new Node(s);
    if(tail == NULL || head == NULL){
        tail = newNode;
        head = tail;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

}
void add_front(string s){
    Node * newNode = new Node(s);
	newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;
    head = newNode;

}
bool empty(){
    return head == NULL;
}
void erase_front(){
   Node *tmp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    if (head == NULL) {
        tail = NULL;
    }
    delete tmp;
}
void erase_back(){
	Node * cur = tail;
	if(tail->prev != NULL) tail = tail->prev;
	else head = NULL;

	tail->next = NULL;

	delete cur;

}
string front(){
	return head->val;
}
string back(){
	return tail->val;
}
void clear(){
	// head = NULL;
	// head->prev = NULL;

	while(head != NULL) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}