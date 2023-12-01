#include<iostream>
using namespace std;

struct Node {
    string data;
    Node* next = NULL;
};

int main() {
    int n;

    // Prompt the user for the number of names
    cout << "Enter the number of names: ";
    cin >> n;

    Node* head = new Node();
    Node* start = head;

    Node* prevNode = nullptr; // To keep track of the previous node

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        
        if (i == 0 || start->data != a) {
            head->data = a;
            
            if (prevNode != nullptr) {
                prevNode->next = head;
            }
            
            head->next = new Node();
            prevNode = head;
            head = head->next;
        }
    }

    // Print the unique names
    start = start->next; // Skip the initial empty node
    while (start->next != NULL) {
        cout << start->data << " ";
        start = start->next;
    }

    // Free memory
    while (start != NULL) {
        Node* temp = start;
        start = start->next;
        delete temp;
    }

    return 0;
}
