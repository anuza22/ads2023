#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> d;
    char command;
    int num;

    while (cin >> command) {
        if (command == '+') {
            cin >> num;
            d.push_front(num);
        } else if (command == '-') {
            cin >> num;
            d.push_back(num);
        } else if (command == '!') {
            break;  // Exit the loop and end the program
        } else if (command == '*') {
            if (d.size() < 2) {
                cout << "error" << endl;
            } else {
                int sum = d.front() + d.back();
                cout << sum << endl;
                d.pop_front();
                d.pop_back();
            }
        } 
    }

    return 0;
}
