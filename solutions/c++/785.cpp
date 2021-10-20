//%speed 0% (ouch) 124ms
class Solution {
    enum class color {blue, red};
    set<int>& othercolor(int node) {
        if (red.count(node) > 0) {
            return blue;
        } else {
            return red;
        }
    }
    unordered_map<int, color> color_map;
    set<int> red, blue;
    set<int> visited;
    void bfs(vector<vector<int>>& graph, int start) {
        queue<int> node_q;
        for (int start =0; start < graph.size();start++) {
        node_q.push(start);
        color_map.insert({start, color::red});
        cout << "node " << start << " in red\n";
        while (!node_q.empty()) {
            //have we already been visited?
            //get the first element and delete it at the end
            int & thisnode = node_q.front();
            if (visited.count(thisnode) > 0) {
                node_q.pop();
                continue;
            }
            for (auto & child : graph[thisnode]) {
                othercolor(thisnode).insert(child);
                if (red.count(thisnode) > 0) {
                    cout << "node " << child << " in blue\n";
                } else {
                    cout << "node " << child << " in red\n";
                }
                node_q.push(child);
            }
            visited.insert(thisnode);
            node_q.pop();
        }
    }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited.clear(); color_map.clear();
        bfs(graph, 0);
        for (int node : red) {
            for (int child : graph[node]) {
                if (red.count(child) > 0) {
                    cout <<"red "<< node << " and " << child << endl;
                    return false;
                }
            }
        }
        for (int node : blue) {
            for (int child : graph[node]) {
                if (blue.count(child) > 0) {
                     cout << "blue " << node << " and " << child << endl;
                    return false;
                }
            }
        }
        return true;
    }
};

//100ms but still off the chart slow. Looks like most runtimes are around 25ms, so I could use some improvement here.
//I did use a lot less memory than other solutions.
class Solution {
    enum class color {blue, red};
    set<int>& othercolor(int node) {
        if (red.count(node) > 0) {
            return blue;
        } else {
            return red;
        }
    }
    unordered_map<int, color> color_map;
    set<int> red, blue;
    set<int> visited;
    void bfs(vector<vector<int>>& graph, int start) {
        queue<int> node_q;
        for (int start =0; start < graph.size()&& (visited.size() < graph.size());start++) {
        node_q.push(start);
        color_map.insert({start, color::red});
        cout << "node " << start << " in red\n";
        while (!node_q.empty()) {
            //have we already been visited?
            //get the first element and delete it at the end
            int & thisnode = node_q.front();
            if (visited.count(thisnode) > 0) {
                node_q.pop();
                continue;
            }
            for (auto & child : graph[thisnode]) {
                othercolor(thisnode).insert(child);
                if (red.count(thisnode) > 0) {
                    cout << "node " << child << " in blue\n";
                } else {
                    cout << "node " << child << " in red\n";
                }
                node_q.push(child);
            }
            visited.insert(thisnode);
            node_q.pop();
        }
    }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        visited.clear(); color_map.clear();
        bfs(graph, 0);
        for (int node : red) {
            for (int child : graph[node]) {
                if (red.count(child) > 0) {
                    cout <<"red "<< node << " and " << child << endl;
                    return false;
                }
            }
        }
        for (int node : blue) {
            for (int child : graph[node]) {
                if (blue.count(child) > 0) {
                     cout << "blue " << node << " and " << child << endl;
                    return false;
                }
            }
        }
        return true;
    }
};
