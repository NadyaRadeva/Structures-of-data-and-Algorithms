//terminated due to timeout

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cheats;

    for (int i = 0; i < n; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            cheats.push_back(x);
        } 
        else if (cmd == "gun") {
            cheats.pop_back();
        } 
        else if (cmd == "milen") {
            int half = cheats.size() / 2;
            vector<int> left(cheats.begin(), cheats.begin() + half);
            vector<int> right(cheats.begin() + half, cheats.end());
            cheats.clear();
            cheats.insert(cheats.end(), right.begin(), right.end());
            cheats.insert(cheats.end(), left.begin(), left.end());
        }
    }

    cout << cheats.size() << endl;
    if (!cheats.empty()) {
        for (size_t i = 0; i < cheats.size(); ++i) {
            cout << cheats[i];
            if (i + 1 < cheats.size()) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
