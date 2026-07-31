void topView(Node* root) {
    if (!root) {
        return;
    }

    map<int, int> top;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        Node* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (top.find(hd) == top.end()) {
            top[hd] = node->data;
        }

        if (node->left) {
            q.push({node->left, hd - 1});
        }

        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto x : top) {
        cout << x.second << " ";
    }
}
