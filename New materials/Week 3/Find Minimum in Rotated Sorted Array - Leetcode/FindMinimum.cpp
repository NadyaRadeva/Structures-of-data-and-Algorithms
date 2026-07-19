class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 5001;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[left] <= nums[mid]) {
                if(nums[left] < result) {
                    result = nums[left];
                }
                left = mid + 1;
            }
            else {
                if (nums[mid] < result) {
                    result = nums[mid];
                }
                right = mid - 1;
            }
        }

        return result;
    }
};
