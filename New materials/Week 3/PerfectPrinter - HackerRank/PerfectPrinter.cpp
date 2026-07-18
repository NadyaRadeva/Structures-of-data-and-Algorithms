// https://www.hackerrank.com/contests/sda-homework-3/challenges/challenge-2674/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool canPrint(long long time, int printers[], int k, long long sheets) {

    long long printed = 0;

    for (int i = 0; i < k; i++) {

        printed += time / printers[i];

        if (printed >= sheets)
            return true;
    }

    return false;
}

int main() {

    long long n;
    int k;

    cin >> n >> k;

    int* printers = new int[k];

    int fastest;

    for (int i = 0; i < k; i++) {

        cin >> printers[i];

        if (i == 0 || printers[i] < fastest)
            fastest = printers[i];
    }

    long long left = 0;
    long long right = 1LL * fastest * n;

    while (left < right) {

        long long mid = left + (right - left) / 2;

        if (canPrint(mid, printers, k, n))
            right = mid;
        else
            left = mid + 1;
    }

    cout << left;

    delete[] printers;

    return 0;
}
