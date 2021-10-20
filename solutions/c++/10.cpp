//92% speed
//tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector<vector<int>> table;
        for (int i=0; i<s.size()+1; i++){
            table.push_back(vector<int>(p.size()+1,0));
        }
        table[0][0]=true;
        for (int i=1; i < table[0].size(); i++) {
            if (p[i-1] == '*')
                table[0][i]=table[0][i-2];
            //cout<< table[0][i];
        }
        //cout << endl;
        for (int y=1; y < table.size(); y++) {
            for (int x=1; x<table[0].size(); x++) {
                //y index is for s and x index is for p

                if (s[y-1] == p[x-1] || p[x-1] == '.') {
                    table[y][x]=table[y-1][x-1];
                    //cout << table[y-1][x-1];
                    continue;
                }
                else if (p[x-1] == '*') {
                    bool none = table[y][x-2];
                    bool atleast_one = false;
                    if (s[y-1] == p[x-2] || p[x-2] == '.') {
                        atleast_one=table[y-1][x];
                    }
                    table[y][x]=none|atleast_one;
                    //cout << table[y][x];
                } else {
                    table[y][x]=false;
                }

            }
            //cout << endl;
        }
        return (table.back()).back();
    }
};

//memoization
//93% speed
class Solution {
    enum Result { UNCHECKED=2, TRUE = 1, FALSE = 0};

public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        // vector<vector<Result>> dp (s.length()+1, vector<Result>(p.length()+1, Result.UNCHECKED));
        std::vector<std::vector<int>> dp (s.length()+1, std::vector<int>(p.length()+1, 2));
        return recurdp(s,p,0,0, dp);
    }

    bool recurdp(string const &s, string const &p, int si, int pi, vector<vector<int>>& dp) {
        if (dp[si][pi] != UNCHECKED) {
            return dp[si][pi];
        }
        if (pi >= p.length()) {
            dp[si][pi] = si >= s.length();
            return dp[si][pi];
        }
        bool pair_match = (si < s.length() && (s[si] == p[pi] || p[pi] == '.'));
        if (p.length()-pi > 1 && p[pi+1] == '*') {
            dp[si][pi]= recurdp(s, p,si,pi+2,dp) || (pair_match && recurdp(s, p,si+1,pi,dp));
            return dp[si][pi];
        }
        if (pair_match) {
            dp[si][pi] = recurdp(s, p,si+1,pi+1,dp);
            return dp[si][pi];
        }
        return false;
    }


    bool recur(string const &s, string const &p) {
        if (p.empty()) return s.empty();
        bool pair_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() > 1 && p[1] == '*') {

            bool result = recur(s, p.substr(2)) || (pair_match && recur(s.substr(1), p));
            return result;
        }
        if (pair_match) {
            return recur(s.substr(1), p.substr(1));
        }
        return false;
    }

};
