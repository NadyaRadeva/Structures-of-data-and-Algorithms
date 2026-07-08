#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {
    int counter[256] = {0};

    for (int i = 0; i < s.size(); ++i) {
        counter[(unsigned char)s[i]]++;
    }

    int odd = 0;

    for (int i = 0; i < 256; ++i) {
        if (counter[i] % 2 != 0)
            odd++;
    }

    return (odd <= 1) ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
