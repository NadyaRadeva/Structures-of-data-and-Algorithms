class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        vector<int> sums;

        for (int i = 0; i <= nums.size() - k; i++) {

            int sum = 0;

            for (int j = 0; j < k; j++) {
                sum += nums[i + j];
            }

            sums.push_back(sum);
        }

        double maxAverage = (double)sums[0] / k;

        for (int i = 1; i < sums.size(); i++) {
            maxAverage = max(maxAverage, (double)sums[i] / k);
        }

        return maxAverage;
    }
};
