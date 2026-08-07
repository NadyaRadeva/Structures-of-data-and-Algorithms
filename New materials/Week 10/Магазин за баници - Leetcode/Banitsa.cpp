#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Order {
    long long arrival;
    long long cook;
    int index;
};

struct Compare {
    bool operator()(const Order& a, const Order& b) const {

        if (a.cook == b.cook)
            return a.index > b.index;

        return a.cook > b.cook;
    }
};

int main() {
    int N;
    cin >> N;

    vector<Order> orders(N);

    for (int i = 0; i < N; i++) {
        cin >> orders[i].arrival >> orders[i].cook;
        orders[i].index = i;
    }

    sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {return a.arrival < b.arrival;});

    priority_queue<Order, vector<Order>, Compare> pq;

    long long currentTime = 0;
    int i = 0;

    while (i < N || !pq.empty()) {
        if (pq.empty()) {
            currentTime = max(currentTime, orders[i].arrival);
        }

        while (i < N && orders[i].arrival <= currentTime) {
            pq.push(orders[i]);
            i++;
        }

        Order current = pq.top();
        pq.pop();

        cout << current.index << " ";

        currentTime += current.cook;
    }

    return 0;
}
