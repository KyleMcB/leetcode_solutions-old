//12% speed
class Solution {
    const vector<int> highestontheleft(const vector<int>& height) {
        vector<int> ans(height.size());
        int current=0;
        for (int i=0; i < height.size(); i+=1) {
            ans[i]=current;
            current=max(current, height[i]);
        }
        return ans;
    }
    const vector<int> highestontheright(const vector<int>& height) {
        vector<int> ans(height.size());
        int current=0;
        for (int i=height.size()-1; i >= 0; i-=1) {
            ans[i]=current;
            current=max(current, height[i]);
        }
        return ans;
    }
public:
    int trap(const vector<int>& height) {
        const vector<int> leftmax= highestontheleft(height);
        const vector<int> rightmax= highestontheright(height);
        int total=0;
        for (int i=0; i < height.size(); i+=1) {
            int local_potential=min(leftmax[i], rightmax[i]) - height[i];
            if (local_potential > 0)
            total+=min(leftmax[i], rightmax[i]) - height[i];
            //cout << min(leftmax.at(i), rightmax.at(i)) - height.at(i) << " = " << min(leftmax.at(i), rightmax.at(i)) << " - " << height.at(i) << endl;
        }
        return total;
    }
};

//5%
class Solution {
    const vector<int> highestontheleft(const vector<int>& height) {
        vector<int> ans;
        int current=0;
        for (int i=0; i < height.size(); i+=1) {
            ans.push_back(current);
            current=max(current, height[i]);
        }
        return ans;
    }
    const vector<int> highestontheright(const vector<int>& height) {
        vector<int> ans;
        int current=0;
        for (int i=height.size()-1; i >= 0; i-=1) {
            ans.insert(ans.begin(), current);
            current=max(current, height[i]);
        }
        return ans;
    }
public:
    int trap(const vector<int>& height) {
        const vector<int> leftmax= highestontheleft(height);
        const vector<int> rightmax= highestontheright(height);
        int total=0;
        for (int i=0; i < height.size(); i+=1) {
            int local_potential=min(leftmax[i], rightmax[i]) - height[i];
            if (local_potential > 0)
            total+=min(leftmax[i], rightmax[i]) - height[i];
            //cout << min(leftmax.at(i), rightmax.at(i)) - height.at(i) << " = " << min(leftmax.at(i), rightmax.at(i)) << " - " << height.at(i) << endl;
        }
        return total;
    }
};
