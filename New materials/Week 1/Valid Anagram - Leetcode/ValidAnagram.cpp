class Solution {
public:
    bool isAnagram(string s, string t) {
        int counterS[256] = {0};
        int counterT[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            counterS[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            counterT[t[i]]++;
        }

        for (int i = 0; i < 256; i++) {
            if (counterS[i] != counterT[i])
                return false;
        }

        return true;
    }
};
