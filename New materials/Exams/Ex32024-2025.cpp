#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;

    cin >> N >> K;

    vector<long long> magicEneries(N);

    for(long long i = 0; i < N; ++i) {
        cin >> magicEneries[i];
    }

    unordered_map<long long, long long> countPrefix;
    unordered_map<long long, long long> firstIndex;

    long long prefix = 0;
    long long count = 0;
    long long maxLength = 0;

    countPrefix[0] = 1;
    firstIndex[0] = -1;

    for(long long i = 0; i < N; ++i) {

        prefix += magicEneries[i];

        long long needed = prefix - K;

        if(countPrefix.find(needed) != countPrefix.end()) {
            count += countPrefix[needed];
        }

        if(firstIndex.find(needed) != firstIndex.end()) {

            long long length = i - firstIndex[needed];

            if(length > maxLength) {
                maxLength = length;
            }
        }

        countPrefix[prefix]++;

        if(firstIndex.find(prefix) == firstIndex.end()) {
            firstIndex[prefix] = i;
        }
    }

    if(count == 0) {
        cout << -1 << '\n';
    }
    else {
        cout << maxLength << " " << count << '\n';
    }

    return 0;
}
