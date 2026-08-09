class Solution {
public:
    unordered_set<int> visited;

    void dfs(int curr, vector<vector<int>>& isConnected) {
        visited.insert(curr);

        for(int i = 0; i < isConnected.size(); ++i) {
            if(isConnected[curr][i] && !visited.count(i)) {
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int components = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited.count(i)) {
                dfs(i, isConnected);
                ++components;
            }
        }    

        return components;
    }
};
