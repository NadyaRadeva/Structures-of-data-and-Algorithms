#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>

const int MIN_SIZE_POW_FRIENDS = 1;
const int MAX_SIZE_POW_FRIENDS = 33;
const int MIN_SIZE_INVITED_FRIENDS = 1;
const int MAX_SIZE_INVITED_FRIENDS = 100000;

int handleRequest(long long groupSize, long long grIndex, int depth) {
    if (groupSize == 1) {
        return depth;
    }

    long long group = groupSize / 3;

    if (grIndex <= group) {
        return handleRequest(group, grIndex, depth + 1);
    } 
    else if (grIndex <= 2 * group) {
        return depth;
    } 
    else {
        return handleRequest(group, grIndex - 2 * group, depth + 1);
    }
}

int main() {
    int n, p;
    cin >> n >> p;

    if (n < MIN_SIZE_POW_FRIENDS || n > MAX_SIZE_POW_FRIENDS || p < MIN_SIZE_INVITED_FRIENDS || p > MAX_SIZE_INVITED_FRIENDS) {
        return 1;
    }

    long long totalFriends = 1;
    for (int i = 0; i < n; ++i) {
        totalFriends *= 3;
    }

    vector<int> candies;

    for (int i = 0; i < p; ++i) {
        long long friendIndex;
        cin >> friendIndex;

        if (friendIndex < 1 || friendIndex > totalFriends) {
            return -1;
        }

        candies.push_back(handleRequest(totalFriends, friendIndex, 1));
    }

    for (int c : candies)
        cout << c << endl;

    return 0;
}
