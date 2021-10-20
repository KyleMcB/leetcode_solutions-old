//55% speed
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        vector<vector<int>> table;
        for (int i=0; i <= s.size();i++){
            table.push_back(vector<int>(p.size()+1,0));
        }
        table[0][0]=true;
        for (int i=1; i < table[0].size(); i++) {
            if (p[i-1] == '*')
                table[0][i]=table[0][i-1];
            //cout<< table[0][i];
        }

         for (int y=1; y < table.size(); y++) {
            for (int x=1; x<table[0].size(); x++) {
                //y index is for s and x index is for p
                if (s[y-1] == p[x-1] || p[x-1] == '?'){
                    table[y][x]=table[y-1][x-1];
                } else if (p[x-1] == '*') {
                    table[y][x]=table[y-1][x]|table[y][x-1];
                } else {
                    table[y][x]=false;
                }

            }
        }
        return (table.back()).back();
    }
};
