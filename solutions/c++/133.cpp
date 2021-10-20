//%72 speed
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    struct copypair {
        Node* src;
        Node* dst;
    };
    set<Node*> visited;
    map<int, Node*> created;
    void link(Node* a, Node* b) {
        a->neighbors.push_back(b);
    }
    Node* getNode(int n) {
        if (created.count(n) > 0) {
            return created.at(n);
        } else {
            Node* temp = new Node{};
            temp->val=n;
            created.insert({n, temp});
            return temp;
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* newroot= getNode(node->val);
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node * cur = q.front();
            q.pop();
            if (visited.count(cur) > 0) {
                continue;
            }
            Node * copy = getNode(cur->val);
            for (auto & neighboor : cur->neighbors) {
                q.push(neighboor);
                link(copy, getNode(neighboor->val));
            }
            visited.insert(cur);
        }

        return newroot;
    }
};
