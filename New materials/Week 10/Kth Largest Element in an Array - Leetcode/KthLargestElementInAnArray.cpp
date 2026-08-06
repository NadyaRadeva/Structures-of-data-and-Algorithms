class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int el = 0;

        for(int i = 0; i < k; ++i) {
            int current = pq.top();
            pq.pop();
            el = current;
        }

        return el;
    }
};
