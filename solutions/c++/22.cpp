//88% speed
class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        if (n ==0) return {""};
        if (n == 1) {
            return {{"()"}};
        }
        ans.clear();
        recur("(", n-1, n);
        return ans;
    }
    void recur(const string & line, int open, int closed) {
        if (open == 0 and closed == 0) {
            ans.push_back(move(line));
            return;
        }
        if (open == closed) {
            recur(line + "(", open-1, closed);
            return;
        }
        if (open > 0)
        recur(line + "(", open-1, closed);
        if (closed > 0)
        recur(line + ")", open, closed-1);
    }
};
