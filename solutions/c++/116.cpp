//speed %6 also, note I didn't actually solve this one
//I was supposed to use constant memory and I didn't notice till after I solved it
//I might get around to fixing that
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    struct item {
        Node* node;
        int dist;
    };
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<item> q;
        q.push({root,0});
        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            if (q.front().dist == dist) {
                node->next=q.front().node;
            } else {
                node->next=nullptr;
            }
            if (node->left) {
                q.push({node->left, dist+1});
            }
            if (node->right) {
                q.push({node->right, dist+1});
            }
        }
        return root;
    }
};
