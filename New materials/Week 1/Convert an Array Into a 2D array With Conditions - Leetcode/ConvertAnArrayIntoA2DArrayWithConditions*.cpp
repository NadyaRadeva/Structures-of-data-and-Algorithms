class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<int> freq(nums.size() + 1, 0);
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            int x = nums[i];

            if (freq[x] == ans.size()) {
                ans.push_back({});
            }

            ans[freq[x]].push_back(x);
            freq[x]++;
        }

        return ans;
    }
};
