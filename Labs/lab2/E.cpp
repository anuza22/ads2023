#include <bits/stdc++.h>
 
using namespace std;
 
class Node{
public :
    string num;
    Node *next;
};

struct Node *head=NULL;
 
void insert_Node(Node** head, string n){
    Node* new_node = new Node();
    new_node->num = n;
    new_node->next =(*head);
    (*head) = new_node;
}

void display_all_nodes(Node* node){
	
    while(node != NULL){
        cout<<node->num<<" ";
        node=node->next;
    }
    }
 
int main(){
	Node* head = NULL;
	vector <string> v;
	
    int n;
    cin>>n;
    
    string s[n];
    
    for(int i=0;i<n;i++){
	    cin>>s[i];    	
	}
	
	for(int i=n-1;i>=0;i--){
		insert_Node(&head,s[i]);

	}
	Node* temp = head;
	
	while(temp!= NULL){
		v.push_back(temp->num);
		temp = temp->next;
	}
	
	reverse(v.begin(),v.end());
	
    v.erase( unique( v.begin(), v.end() ), v.end() );
    int cnt = v.size();
    cout<<"All in all: "<< cnt<<endl ;
    cout<<"Students: "<<endl;
	for (auto it = v.begin();it != v.end();it++){
		cout <<*it <<endl;
	}
	
    return 0;
}