// https://www.hackerrank.com/contests/sda-practicum-test-1/challenges/1-7-4/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int frequency[52] = {0};

    for(char c : s) {

        if(c >= 'a' && c <= 'z') {
            frequency[c - 'a']++;
        }
        else {
            frequency[c - 'A' + 26]++;
        }
    }

    int odd = 0;

    for(int i = 0; i < 52; ++i) {
        if(frequency[i] % 2 == 1) {
            odd++;
        }
    }

    int answer = max(0, odd - 1);

    cout << answer << '\n';

    return 0;
}
