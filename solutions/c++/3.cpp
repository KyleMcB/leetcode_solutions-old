//83% speed
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     vector<int> table(256, 0);
    int maxstr=0, track=0;
    for(int i=0;i<s.length();i++)
    {
        while(table[s[i]])table[s[track++]]=0;
        table[s[i]]=1;
        maxstr=max(maxstr, i-track+1);

    }
    return maxstr;
    }
};
