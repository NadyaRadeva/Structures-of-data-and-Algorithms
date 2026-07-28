class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(128, 0);

        for (char c : t) {
            count[c]++;
        }

        int left = 0;
        int right = 0;

        int needed = t.size();

        int minLength = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            if (count[s[right]] > 0) {
                needed--;
            }

            count[s[right]]--;
            right++;

            while (needed == 0) {

                if (right - left < minLength) {
                    minLength = right - left;
                    start = left;
                }

                count[s[left]]++;

                if (count[s[left]] > 0) {
                    needed++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};
