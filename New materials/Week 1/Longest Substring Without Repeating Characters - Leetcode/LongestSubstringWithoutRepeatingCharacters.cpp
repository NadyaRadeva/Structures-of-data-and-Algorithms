class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int frequencies[256] = {0};

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            frequencies[s[right]]++;

            while (frequencies[s[right]] > 1) {
                frequencies[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
