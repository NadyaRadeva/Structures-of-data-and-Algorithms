class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long allPairs = n * (n - 1) / 2;
        long long goodPairs = 0;

        unordered_map<int, int> tracker;

        for (int i = 0; i < nums.size(); ++i) {
            int target = nums[i] - i;

            goodPairs += tracker[target];
            tracker[target]++;
        }

        return allPairs - goodPairs;
    }
};
