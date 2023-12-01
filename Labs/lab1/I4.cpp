#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string votes;
    cin >> votes;

    vector<int> elimination(n, 0);
    int sakayanagi_count = 0;
    int katsuragi_count = 0;

    for (char c : votes) {
        if (c == 'S') {
            sakayanagi_count++;
        } else {
            katsuragi_count++;
        }
    }

    char leader = (sakayanagi_count > katsuragi_count) ? 'S' : 'K';

    int elimination_count = 0;
    int i = 0;

    while (elimination_count < n - 1) {
        int next_candidate = (i + 1) % n;

        if (votes[i] != votes[next_candidate] && elimination[i] == 0) {
            elimination[i] = 1; // Eliminate the student
            elimination_count++;
        }

        i = (i + 1) % n; // Move to the next student
    }

    for (i = 0; i < n; i++) {
        if (elimination[i] == 0) {
            leader = votes[i]; // Find the remaining non-eliminated student
            break;
        }
    }

    cout << ((leader == 'S') ? "SAKAYANAGI" : "KATSURAGI") << endl;

    return 0;
}
