//%49 speed
class Solution {
    struct item {
        vector<int> point;
        uint mag;
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<item> mags;
        for (auto & point : points) {
            mags.push_back({
                point,
                point[0]*point[0] +point[1]*point[1]
            });
        }
        sort(mags.begin(), mags.end(), [](const item & a, const item & b){
            return a.mag < b.mag;
        });
        vector<vector<int>> ans;
        for (int i=0; i<K;i++) {
            ans.push_back(mags[i].point);
        }
        return ans;
    }
};
