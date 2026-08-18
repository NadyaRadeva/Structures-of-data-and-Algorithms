#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> prices(N);

    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    vector<int> days(N, 0);
    stack<int> st;

    for (int i = N - 1; i >= 0; --i) {

        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        if (!st.empty()) {
            days[i] = st.top() - i;
        }

        st.push(i);
    }

    for (int i = 0; i < N; ++i) {
        cout << days[i];

        if (i < N - 1) {
            cout << " ";
        }
    }

    cout << '\n';

    return 0;
}
