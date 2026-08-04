// ═══════════════════════════════════════════════════════
// Problem: 133. Clone Graph
// Difficulty: Medium
// Topics: Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
// Runtime: 0 ms (Beats 100.0%)
// Memory: 12.3 MB (Beats 11.8%)
// Submitted: Aug 4, 2026
// Link: https://leetcode.com/problems/clone-graph/
// ═══════════════════════════════════════════════════════

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

     Node* dfs(Node* node, map<Node*, Node*>& oldToNew){
        if (node == nullptr){
            return nullptr;
        }

        if (oldToNew.count(node)){
            return oldToNew[node];
        }

        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for (Node* n : node->neighbors){
            copy->neighbors.push_back(dfs(n, oldToNew));
        }

        return copy;
    }
};
