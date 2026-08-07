class Solution {
public:
    string reorganizeString(string s) {
        vector<int> frequency(26, 0);

        for (int i = 0; i < s.size(); ++i) {
            frequency[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (char c = 'a'; c <= 'z'; ++c) {
            if (frequency[c - 'a'] > 0) {
                pq.push({frequency[c - 'a'], c});
            }
        }

        string result;

        pair<int, char> previous = {0, '#'};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            result.push_back(current.second);

            current.first--;

            if (previous.first > 0) {
                pq.push(previous);
            }

            previous = current;
        }

        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};
