//%25 speed could use some improvement

class Solution {
    struct Node {
        map<char, Node> letters;
        bool end=false;
    }root;
    void insert(const string & line) {
        Node* node=&root;
        for (int i=0,end=line.size(); i < end; i++ ) {
            const char & letter= line[i];
            //is the letter already in the node?
            if (node->letters.count(letter) > 0) {
                //yes, follow it
                node=&node->letters.at(letter);
            } else {
                //no it isn't, create a node and follow it
                node->letters.insert({letter,{}});
                node=&node->letters.at(letter);
            }
        }
        node->end=true;
    }
        void test(){
            insert("the");
            Node* node=&root;
            if (node->letters.count('t') > 0) {
                cout << 't';
                node=&node->letters.at('t');
            }
            if (node->letters.count('h') > 0) {
                cout << 'h';
                node=&node->letters.at('h');
            }
            if (node->letters.count('e') > 0) {
                cout << 'e';
                node=&node->letters.at('e');
            }
            if (node->end) {
                cout << "\nsucces";
            }
    }
    string longest;
    int lsize=0;
public:
    string longestWord(const vector<string>& words) {
        for (const auto & word : words) {
            insert(word);
        }
        recur(root, "");
        return longest;
    }
    void recur(const Node& node, string word) {
        //is the next letter an end?
        for (auto neighbor=node.letters.begin(); neighbor != node.letters.end(); ++neighbor ) {
            //neighbor->first is the key
            //neighbor->second is the node pointed to be the key
            if (neighbor->second.end) {
                string temp(word);
                temp.append(1,neighbor->first);
                if (temp.size() > lsize) {
                    longest=temp;
                    lsize=longest.size();
                }
                recur(neighbor->second, temp);
            }
        }
    }
};
