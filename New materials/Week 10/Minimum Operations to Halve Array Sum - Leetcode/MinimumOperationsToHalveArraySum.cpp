class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());

        double sum = 0;

        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        double target = sum / 2;

        double reduced = 0;

        int operations = 0;

        while(reduced < target) {
            double current = pq.top();
            pq.pop();

            double half = current / 2;

            reduced += half;

            pq.push(half);

            operations++;
        }

        return operations;
    }
};
