class Solution {
    // Maps:
    //
    // original node -> cloned node
    //
    // Example:
    //
    // original 1 -> clone 1
    // original 2 -> clone 2
    // original 3 -> clone 3
    //
    // We need this because the graph can contain cycles.
    unordered_map<Node*, Node*> indexToNode;

public:
    Node* cloneGraph(Node* node) {

        // If the original graph is empty,
        // there is nothing to clone.
        if (!node) {
            return node;
        }

        // Have we already cloned this node?
        //
        // find(node) searches for the original node
        // inside our map.
        auto iter = indexToNode.find(node);

        // If the node is already in the map,
        // return its already-created clone.
        //
        // We DON'T create another clone.
        if (iter != indexToNode.end()) {
            return iter->second;
        }

        // Create a new node with the same value
        // as the original node.
        Node* newNode = new Node(node->val);

        // IMPORTANT:
        //
        // Store the relationship immediately:
        //
        // original node -> cloned node
        //
        // We do this BEFORE cloning the neighbors.
        indexToNode[node] = newNode;


        // Go through all neighbors of the original node.
        for (auto neighbor : node->neighbors) {
            // Clone the neighbor and add the cloned
            // neighbor to newNode's neighbors.
            //
            // cloneGraph(neighbor) either:
            //
            // 1. creates a new clone, OR
            // 2. returns an existing clone if we
            //    already visited this node.
            newNode->neighbors.push_back(
                cloneGraph(neighbor)
            );
        }

        // Return the cloned node.
        return newNode;
    }
};
