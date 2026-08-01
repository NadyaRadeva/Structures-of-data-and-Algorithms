#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 1000000;

int leftC[MAXN];
int rightC[MAXN];
int subtreeSize[MAXN];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> leftC[i] >> rightC[i];
    }

    vector<int> order;

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        order.push_back(u);

        if (leftC[u] != -1) st.push(leftC[u]);
        if (rightC[u] != -1) st.push(rightC[u]);
    }

    long long maxProduct = 0;

    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];

        int L = (leftC[u] == -1 ? 0 : subtreeSize[leftC[u]]);
        int R = (rightC[u] == -1 ? 0 : subtreeSize[rightC[u]]);

        subtreeSize[u] = 1 + L + R;
    }

    for (int u = 0; u < N; u++) {
        int L = (leftC[u] == -1 ? 0 : subtreeSize[leftC[u]]);
        int R = (rightC[u] == -1 ? 0 : subtreeSize[rightC[u]]);
        int P = N - L - R - 1;

        long long prod = 1;
        if (L > 0) prod *= L;
        if (R > 0) prod *= R;
        if (P > 0) prod *= P;

        if (prod > maxProduct) maxProduct = prod;
    }

    cout << maxProduct;

    return 0;
}
