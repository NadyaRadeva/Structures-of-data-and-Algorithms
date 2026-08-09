class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // If there are fewer than n - 1 trust relationships,
        // there cannot be a judge.
        //
        // Why?
        // The judge must be trusted by all other n - 1 people.
        if (trust.size() < n - 1) {
            return -1;
        }


        // indegree[i] = how many people trust person i
        //
        // outdegree[i] = how many people person i trusts
        //
        // We use n + 1 because people are numbered 1 ... n.
        // Index 0 will not be used.
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);


        // Go through every trust relationship.
        //
        // trust[i] looks like:
        //
        // [a, b]
        //
        // meaning:
        // person a trusts person b.
        for (int i = 0; i < trust.size(); ++i) {

            // a trusts someone,
            // so a has one more outgoing edge.
            outdegree[trust[i][0]]++;


            // b is trusted by someone,
            // so b has one more incoming edge.
            indegree[trust[i][1]]++;
        }


        // Check every person.
        for (int i = 1; i <= n; ++i) {
            // A town judge must satisfy TWO conditions:
            //
            // 1. Everybody else trusts the judge.
            //    Therefore indegree[i] == n - 1
            //
            // 2. The judge trusts nobody.
            //    Therefore outdegree[i] == 0
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }


        // If nobody satisfies both conditions,
        // there is no town judge.
        return -1;
    }
};
