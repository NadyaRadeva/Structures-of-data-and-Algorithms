//https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/puncakes/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canCook(long long time, int cooks[], int K, long long pancakes) {
    long long made = 0;

    for (int i = 0; i < K; i++) {
        made += time / cooks[i];

        if (made >= pancakes) {
            return true;
        }
    }

    return false;
}

int main() {

    long long P;
    int K;

    cin >> P >> K;

    int* cooks = new int[K];

    int minTime;

    for (int i = 0; i < K; i++) {
        cin >> cooks[i];

        if (i == 0 || cooks[i] < minTime) {
            minTime = cooks[i];
        }
    }

    long long left = 0;
    long long right = 1LL * minTime * P;

    while (left < right) {

        long long mid = left + (right - left) / 2;

        if (canCook(mid, cooks, K, P)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << endl;

    delete[] cooks;

    return 0;
}
