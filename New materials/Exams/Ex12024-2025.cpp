// https://www.hackerrank.com/contests/2024-2025-2/challenges/challenge-5368/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

long long MIN_N = 1;
long long MAX_N = 100000;
long long MIN_Di = 1;
long long MAX_Di = 2000;
long long MIN_Pi = 1;
long long MAX_Pi = 2000;

struct Land {
    long long diameter;
    long long price;
    double pricePerSquareMeter;
    long long index;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    if(N < MIN_N || N > MAX_N) {
        return -1;
    }

    vector<Land> lands(N);

    for(long long i = 0; i < N; ++i) {
        cin >> lands[i].diameter >> lands[i].price;

        if(lands[i].diameter < MIN_Di ||
           lands[i].diameter > MAX_Di) {
            return -1;
        }

        if(lands[i].price < MIN_Pi ||
           lands[i].price > MAX_Pi) {
            return -1;
        }

        lands[i].index = i + 1;

        lands[i].pricePerSquareMeter =
            (4.0 * lands[i].price) /
            (lands[i].diameter * lands[i].diameter);
    }

    sort(lands.begin(), lands.end(),
        [](const Land& a, const Land& b) {

            if(a.pricePerSquareMeter == b.pricePerSquareMeter) {
                return a.diameter > b.diameter;
            }

            return a.pricePerSquareMeter < b.pricePerSquareMeter;
        });

    for(long long i = 0; i < N; ++i) {
        cout << lands[i].index;

        if(i < N - 1) {
            cout << " ";
        }
    }

    cout << '\n';

    return 0;
}
