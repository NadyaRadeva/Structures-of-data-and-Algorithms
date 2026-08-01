#include<iostream>
#include<vector>
#include<map>

const long long MIN_SIZE_N = 1;
const long long MAX_SIZE_N = 1000000;
const long long MIN_SIZE_A = 1;
const long long MAX_SIZE_A = 100000000;

struct Node {
    long long A;
    long long left;
    long long right;
};

std::vector<Node> tree;
std::map<long long, long long> verticalSums;

void dfs(long long index, long long x) {
    if (index == -1) return;

    Node &node = tree[index];
    verticalSums[x] += node.A;

    dfs(node.left,  x - 1);
    dfs(node.right, x + 1);
}

int main() {
    long long N;
    std::cin >> N;
    if (N < MIN_SIZE_N || N > MAX_SIZE_N) {
        return 0;
    }

    tree.resize(N);

    for (long long i = 0; i < N; ++i) {
        long long A, INDEX_LEFT, INDEX_RIGHT;
        std::cin >> A >> INDEX_LEFT >> INDEX_RIGHT;

        if (A < MIN_SIZE_A || A > MAX_SIZE_A) {
            return 0;
        }

        tree[i].A = A;
        tree[i].left = INDEX_LEFT;
        tree[i].right = INDEX_RIGHT;
    }

    dfs(0, 0);

    for (auto &p : verticalSums) {
        if (p.second != 0) {
            std::cout << p.second << " ";
        }
    }

    return 0;
}
