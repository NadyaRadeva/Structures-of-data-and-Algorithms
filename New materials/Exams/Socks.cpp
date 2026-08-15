// https://www.hackerrank.com/contests/sda-2025-2026-final-exam-ghquw/challenges/sock-triplets/problem

#include <bits/stdc++.h>
using namespace std;

long long MIN_N = 1;
long long MAX_N = 10000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    if (N < MIN_N || N > MAX_N) {
        return -1;
    }

    unordered_map<string, int> count;

    count.reserve(N);

    for (int i = 0; i < N; ++i) {
        string colour;
        cin >> colour;
        ++count[colour];
    }

    int triplets = 0;

    for (auto& kvp : count) {
        triplets += kvp.second / 3;
    }

    cout << triplets << '\n';

    return 0;
}
