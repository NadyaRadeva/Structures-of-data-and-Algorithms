#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {
    int counterS1[26] = {0};
    int counterS2[26] = {0};

    for (int i = 0; i < s1.size(); i++) {
        counterS1[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.size(); i++) {
        counterS2[s2[i] - 'a']++;
    }

    int diff = 0;

    for (int i = 0; i < 26; i++) {
        diff += abs(counterS1[i] - counterS2[i]);
    }

    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
