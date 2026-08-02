class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> s;

        for(int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            string key = str;

            sort(key.begin(), key.end());
            s[key].push_back(str);
        }

        vector<vector<string>> result;

        for (auto& v : s) {
            result.push_back(std::move(v.second));
        }

        return result;
    }
};
