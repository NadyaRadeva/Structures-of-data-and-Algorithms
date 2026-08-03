class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> freq;

        freq[0] = 1;

        int prefix = 0;
        int answer = 0;

        for (int i = 0; i < nums.size(); ++i) {
            prefix += nums[i];

            if (freq.count(prefix - goal)) {
                answer += freq[prefix - goal];
            }

            freq[prefix]++;
        }

        return answer;
    }
};
