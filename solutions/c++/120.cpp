//speed %56%
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //I don't like changing input memory, but I'll make an except in this case
        if (triangle.empty()) return 0;
        if (triangle.size() == 1) return triangle[0][0];
        auto min3 = [] (int a, int b, int c) {
            return min(min(a,b),c);
        };
        auto get_dp = [&triangle](int row, int col)
        {
            if (row < 0 || col < 0 || col > row) return numeric_limits<int>::max();
            return triangle[row][col];
        };
        for (int row=1; row < triangle.size(); row+=1) {
            for (int col =0; col < triangle[row].size(); col+=1) {
                triangle[row][col] += min(get_dp(row-1,col-1), get_dp(row-1,col));
            }
        }
        return *min_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
    }
};
