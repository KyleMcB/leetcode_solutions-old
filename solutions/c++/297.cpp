//%18 speed
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    struct item {
      uint id;
      const TreeNode* node;
    };
    string serialize(const TreeNode* root) {
        if (not root) return "";
        stringstream ss;
        uint id=1;
        string answer;
        queue<item> q;
        q.push({id, root});
        id++;
        while (not q.empty()) {
            item cur = q.front();
            const TreeNode* node = cur.node;
            q.pop();
            ss << ": id " << cur.id << " val " << node->val << " ";
            string left, right;
            if (node->left) {
                //id++;
                q.push({id, node->left});
                ss << "left "<< id << " ";
                id++;
            }
            if (node->right) {
                //id++;
                q.push({id, node->right});
                ss << "right " << id << " ";
                id++;
            }

        }
        //cout << ss.str();
        return ss.str();

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string & data) {
        if (data.empty()) return nullptr;
        // : id # val # (left #) (right)
        stringstream ss(data);
        map<uint, TreeNode*> ids;
        //vector<TreeNode*> nodes;
        uint id=0;
        int val=0;
        string word;
        for ( ss >> word; not ss.eof(); ss >> word) {
            if (word == "id") {
                ss >> id;
            }
            if (word == "val") {
                ss >> val;
                TreeNode* node = new TreeNode(val);
                //node->val=val;
                //nodes.push_back(node);
                ids.insert({id, node});
                val=id=0;
            }
        }
        //cout << "ids size " << ids.size();
        //ok if everything went well I have all the nodes, ids, and values, now I just need to link them
        stringstream ss2(data);
        int left=0, right=0;
        word.clear();
        for (ss2 >> word; not ss2.eof(); ss2 >> word) {
            //cout << word;
            if (word == ":") {
                id=left=right=0;
            }
            if (word == "id") {
                ss2 >> id;
            }
            if (word == "left") {
                ss2 >> left;
                //cout << "node " << id << " left " << left << endl;
                ids.at(id)->left=ids.at(left);
            }
            if (word == "right") {
                ss2 >> right;
                //cout << "node " << id << " right " << right << endl;
                ids.at(id)->right=ids.at(right);
            }
        }
        return ids.at(1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
