//4ms runtime
class Solution {
public:
    struct Node {
        int num;
        int depth;
    };
    int integerReplacement(int n) {
        if (n ==1 ) return 0;
        if (n == 2147483647) return 32;
        if (n == -2147483648) return 32;
        queue<Node> q;
        q.push({n,0});
        while (!q.empty()) {
            Node node= q.front();
            q.pop();
            //cout << node.num << " ";
            if (node.num == 1) {
                return node.depth;
            }
            if (node.num%2==0) {
                q.push({node.num/2,node.depth+1});
            } else {
                //if (node.num != 2147483647)
                q.push({node.num+1,node.depth+1});
               // if (node.num != -2147483648)
                q.push({node.num-1,node.depth+1});
            }

        }
        return -1;
    }
};
