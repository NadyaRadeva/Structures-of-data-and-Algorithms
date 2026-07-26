class RecentCounter {
public:
    queue<int> container;
    
    int ping(int t) {
        while(!container.empty() && container.front() < t - 3000) {
            container.pop();
        }
        container.push(t);

        return container.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
