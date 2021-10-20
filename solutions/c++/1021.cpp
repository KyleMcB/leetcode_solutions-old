//6% speed :-(
class Solution {
public:
    string removeOuterParentheses(string S) {
        int open_level=0;
        bool inner=false;
        for (int i=0; i < S.size();i++){
        if (S[i] == '(') {
            open_level++;
            if (!inner) {
                S.erase(i,1);
                i--;
                inner=true;
            }
        }
        else if (S[i] == ')') {
            open_level--;
            if (open_level == 0){
                S.erase(i,1);
                i--;
                inner=false;
            }
        }
        //cout << open_level;
        }
        return S;
    }
};

//%88 speed
class Solution {
public:
    string removeOuterParentheses(string S) {
        int open_level=0;
        bool inner=false;
        string ans;
        for (int i=0; i < S.size();i++){
        if (S[i] == '(') {
            open_level++;
            if (!inner) {
                //S.erase(i,1);
                //i--;
                inner=true;
            }
            else {
                ans.push_back(S[i]);
            }
        }
        else if (S[i] == ')') {
            open_level--;
            if (open_level == 0){
                // S.erase(i,1);
                // i--;
                inner=false;
            } else {
                ans.push_back(S[i]);
            }
        }
        //cout << open_level;
        }
        return ans;
    }
};
