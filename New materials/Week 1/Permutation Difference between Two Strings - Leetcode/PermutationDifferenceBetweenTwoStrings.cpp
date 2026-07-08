class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int pos[256];

        for(int i = 0; i < s.size(); ++i) {
            pos[s[i]] = i;
        }

        int ans = 0;

        for(int i = 0; i < t.size(); ++i) {
            ans += abs(i - pos[t[i]]);
        }

        return ans;
    }
};
