//%74 speed
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> maxx(grid.at(0).size());
        vector<int> maxy(grid.size());
        int sum=0;
        for (int i=0; i < grid.size(); i++) {
            maxx[i]=0;
            for (auto & x : grid[i]) {
                maxx[i]=max(maxx[i], x);
            }
        }
        for (int i=0; i< grid.at(0).size(); i++) {
            maxy[i]=0;
            for (int x =0; x < grid.size(); x++) {
                maxy[i]=max(grid[x][i], maxy[i]);
            }
        }
        for (int y=0; y < grid.size(); y++) {
            for (int x=0; x < grid.at(0).size(); x++) {
                sum+=min(maxy[y], maxx[x]) - grid[y][x];
                grid[y][x]= min(maxy[y], maxx[x]);
            }
        }
        return sum;
    }
};
