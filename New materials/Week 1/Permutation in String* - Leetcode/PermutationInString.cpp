class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        int count[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            char c = s1[i];
            count[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {

            count[s2[right] - 'a']--;

            if (right - left + 1 > s1.size()) {
                count[s2[left] - 'a']++;
                left++;
            }

            bool found = true;

            for (int i = 0; i < 26; i++) {
                if (count[i] != 0) {
                    found = false;
                    break;
                }
            }

            if (found)
                return true;
        }

        return false;
    }
};
