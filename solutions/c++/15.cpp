//5% speed
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        unordered_map<int,int> lookup;
        set<multiset<int>> ans;
        set<int> attempted;
        set<int> zeroes;
        for (int i=0; i< nums.size(); i+=1) {
            lookup.insert({nums[i],i});
            if (nums[i] == 0)
                zeroes.insert(i);
        }
        if (zeroes.size() > 2) {
            ans.insert({0,0,0});
        }
        //a+b+c=0
        for (int a=0; a < nums.size(); a+=1) {
            if (attempted.count(nums[a]) > 0 ) {
                continue;
            }
            for (int b=a+1; b < nums.size(); b+=1) {
                //if a==b skip
                if (a==b) continue;
                //we know a != b
                //c=-a-b
                int needed_value = -nums[a]-nums[b];
                if (lookup.count(needed_value) > 0){
                    //we have a c for our a and b values
                    //make sure its not the same index as a and b
                    int c = lookup.at(needed_value);
                    if (c != a && c != b){
                        ans.insert({nums[a],nums[b],nums[c]});
                        //cout << "a b c " << nums[a] << " " << nums[b] << " " << nums[c] << endl;
                    }
                }
            }
            attempted.insert(nums[a]);
        }
        vector<vector<int>> ret;
        for (auto & aset : ans) {
            ret.push_back(vector<int>(aset.begin(), aset.end()));
        }
        return ret;
    }
};
