class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); i++) {
            string curr = s.substr(i, 10);

            if (seen.count(curr)) {
                if (!repeated.count(curr)) {
                    repeated.insert(curr);
                    result.push_back(curr);
                }
            } else {
                seen.insert(curr);
            }
        }

        return result;
    }
};
