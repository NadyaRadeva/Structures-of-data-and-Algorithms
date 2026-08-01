// https://www.hackerrank.com/contests/sda-homework-6/challenges/parent/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): value(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): value(x), left(left), right(right) {}
};

vector<vector<int>> children;
vector<int> tin, tout;
int timer = 0;

void dfs(int u)
{
    tin[u] = ++timer;

    for (int v : children[u])
        dfs(v);

    tout[u] = ++timer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    children.resize(N);
    tin.resize(N);
    tout.resize(N);

    vector<bool> hasParent(N, false);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        children[a].push_back(b);
        hasParent[b] = true;
    }

    int root = 0;

    for (int i = 0; i < N; i++)
    {
        if (!hasParent[i])
        {
            root = i;
            break;
        }
    }

    dfs(root);

    int Q;
    cin >> Q;

    while (Q--)
    {
        int x, y;
        cin >> x >> y;

        if (tin[x] <= tin[y] && tout[x] >= tout[y])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
