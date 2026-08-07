class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int minStones = 0;

        for(int i = 0; i < k; i++) {
            int current = pq.top();
            pq.pop();
            current -= current / 2;
            pq.push(current);
        }

        int answer = 0;

        while(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }

        return answer;
    }
};
