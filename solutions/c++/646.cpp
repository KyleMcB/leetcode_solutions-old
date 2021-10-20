//these solutions were highly based of the proveded solutions from leetcode. mostly for education
//speed 14%
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return 0;
        if (pairs.size() == 1) return 1;
        sort(pairs.begin(), pairs.end(), [](auto a, auto b){
            return a[1] < b[1];
        });
        int cur = pairs[0][1];
        int ans=1;
        for (auto& pair: pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans+=1;
            }
        }
        return ans;
    }

};

//speed 93%
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return 0;
        if (pairs.size() == 1) return 1;
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int cur = pairs[0][1];
        int ans=1;
        for (auto& pair: pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans+=1;
            }
        }
        return ans;
    }

};
//these are completely the same except for auto in the lambda parameter
