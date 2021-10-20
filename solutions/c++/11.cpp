//66%
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int l=0,r=height.size()-1;
        int ans=0;
        auto area = [&height] (int a, int b) {
            return (b-a) * min(height[a], height[b]);
        };
        while (l < r) {
            ans=max(ans, area(l,r));
            if (height[l] < height[r]){
                l+=1;
            } else {
                r-=1;
            }
        }
        return ans;
    }
};
