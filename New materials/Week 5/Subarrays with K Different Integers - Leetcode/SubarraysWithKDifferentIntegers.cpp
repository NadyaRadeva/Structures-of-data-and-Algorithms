class Solution {
public:

    int atMostK(vector<int>& nums, int k) {
        vector<int> freq(100001, 0);

        int left = 0;
        int distinct = 0;
        int result = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(freq[nums[right]] == 0) {
                distinct++;
            }

            freq[nums[right]]++;


            while(distinct > k) {
                freq[nums[left]]--;

                if(freq[nums[left]] == 0) {
                    distinct--;
                }

                left++;
            }

            result += right - left + 1;
        }

        return result;
    }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
