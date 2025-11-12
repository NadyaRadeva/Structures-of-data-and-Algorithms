//Score: 90

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;

const int MIN_N_SIZE = 2;
const int MAX_N_SIZE = 1000000;
const int MIN_AI_SIZE = 1;
const int MAX_AI_SIZE = 1000000;

long long bestTreePosition(vector<long long>& heights) {
    long long n = heights.size();
    vector<long long> size_after(n, 0);
    stack<long long> st;

    for (long long i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= heights[i]) {
            st.pop();
        }
        st.push(heights[i]);
        size_after[i] = (int)st.size();
    }

    long long bestPos = 1;   
    long long bestCnt = 0;
    for (long long j = 0; j < n; ++j) {
        long long cnt = (j + 1 < n) ? size_after[j + 1] : 0;
        if (cnt > bestCnt) {
            bestCnt = cnt;
            bestPos = j + 1;
        }
    }

    return bestPos;
}

int main() {
    long long n;
    cin >> n;
    if (n < MIN_N_SIZE || n > MAX_N_SIZE) {
        return 0;
    }

    vector<long long> heights(n);
    for (long long i = 0; i < n; ++i) {
        cin >> heights[i];
        if (heights[i] < MIN_AI_SIZE || heights[i] > MAX_AI_SIZE) {
            return 0;
        }
    }

    cout << bestTreePosition(heights) << endl;
    return 0;
}
