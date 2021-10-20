//%29 speed
//I explore the graph untill I hit a node with node edges that goes on the return stack
class Solution {
    vector<vector<int>> graph;
    vector<int> stack;
    map<int, int> visited;
    bool cycle=false;
    void buildgraph(int n, const vector<vector<int>>& edges) {
        graph.clear();
        graph.insert(graph.end(), n, {});
        for (auto & edge : edges) {
            graph.at(edge[1]).push_back(edge[0]);
        }
    }
    void push(const int n) {
        stack.insert(stack.begin(), n);
    }
    void dfs(int node) {
        //cout << "processing node " << node << endl;
        if (cycle) return;
        if (visited.count(node) == 0) {
            visited.insert({node, 0});
            for (auto & child : graph.at(node)) {
                dfs(child);
            }
            visited.at(node)=1;
            push(node);
        } else if(visited.at(node) == 0) {
            cycle=true;
            return;
        } else if (visited.at(node) == 1) {
            return;
        }


    }
public:
    vector<int> findOrder(int numCourses,const  vector<vector<int>>& prerequisites) {
        buildgraph(numCourses, prerequisites);
        for (int i=0; i < numCourses; i++) {
            if (visited.count(i) == 0) {
                dfs(i);
            }
        }
        if (cycle) return {};
        return stack;
    }
};
