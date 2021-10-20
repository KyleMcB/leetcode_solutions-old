//%59 speed
class Solution {
    set<pair<int,int>> unexplored;
    void fill(int x, int y) {
        for (int loop0=0; loop0 < x; loop0++) {
            for (int loop1=0; loop1 < y; loop1++) {
                unexplored.insert({loop0,loop1});
            }
        }
    }
    int islands=0;
    void add_neighbors_to_queue(pair<int,int> loc, queue<pair<int,int>>& q, const vector<vector<char>>& grid) {
        auto [x,y]=loc;
        if (x > 0)
            q.push({x-1,y});
        if (x < grid.size()-1)
            q.push({x+1,y});
        if (y > 0)
            q.push({x,y-1});
        if (y < grid[0].size()-1)
            q.push({x,y+1});
    }
    void bfswater(pair<int,int> loc, const vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        set<pair<int,int>> visited;
        q.push(loc);
        while (!q.empty()) {
            auto curloc = q.front();
            //cout << curloc.first << " " << curloc.second << endl;
            q.pop();
            //is this not water or already visited?
            if (visited.count(curloc) > 0 || spot(curloc, grid) == '1') {
                continue;
            }
            //add all the neighbors to the queue
            add_neighbors_to_queue(curloc, q, grid);
            unexplored.erase(curloc);
        }
    }
    void bfsland(pair<int,int> loc, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        //set<pair<int,int>> visited;
        q.push(loc);
        while (!q.empty()) {
            auto curloc = q.front();
            //cout << curloc.first << " " << curloc.second << endl;
            q.pop();
            //is this not water or already visited?
            if (spot(curloc, grid) == '0') {
                continue;
            }
            //add all the neighbors to the queue
            add_neighbors_to_queue(curloc, q, grid);
            grid[curloc.first][curloc.second]='0';
        }
        islands+=1;
        //cout << islands << endl;
    }
    char spot(pair<int,int> loc, const vector<vector<char>>& grid) {
        return grid[loc.first][loc.second];
    }
    void linear_Scan(vector<vector<char>>& grid) {
        for (int x=0; x < grid.size(); x+=1) {
            for (int y=0; y < grid[0].size(); y+=1) {
                if (spot({x,y}, grid) == '1') {
                    bfsland({x,y}, grid);
                }
            }
        }
    }

public:

    int numIslands( vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        //fill(grid.size(), grid[0].size());
        linear_Scan(grid);
        return islands;
    }
};
