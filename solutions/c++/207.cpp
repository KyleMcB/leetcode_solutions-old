//%40 speed
class Solution {
   vector<vector<int>> graph;
    set<int> white,gray,black;
    bool cycle=false;
   void buildgraph(int size, const vector<vector<int>>& edges) {
        graph.clear();
        graph.reserve(size);
        for (int i=0; i< size; i++) {
            graph.push_back({});
        }
        for (auto & edge : edges) {
            graph.at(edge[0]).push_back(edge[1]);
            //[0,1] zero points to one, to complete zero you must take one
        }
    }
    bool detectcycle() {
        white.clear(); gray.clear(); black.clear();
        for (int i=0; i < graph.size(); i++)
            white.insert(i);
        while (!white.empty()) {
            if (cycle) return true;
           // cout << *white.begin();
            dfs(*white.begin());
        }
        if (cycle) return true;
        return false;
    }
    void dfs(int node) {
       // cout << "processing " << node << endl;
        if (black.count(node) > 0 || cycle) return;
        if (gray.count(node) > 0) {
            cycle=true;
            return;
            //do we have children?
            if (graph.at(node).empty()) {
                //no then its safe to go black
                gray.erase(gray.find(node));
                black.insert(node);
            } else {
                //we are gray, if all children are black we switch black else there is a cycle
                for (auto & neighbor : graph.at(node)) {
                    if (black.count(neighbor) == 0) {
                        cycle=true;
                        return;
                    }
                }
                gray.erase(gray.find(node));
                black.insert(node);
            }
        }
        if (white.count(node) > 0) {
            //add all children and switch to gray
            white.erase(white.find(node));
            gray.insert(node);
            for (auto & neighbor : graph.at(node)) {
                dfs(neighbor);
            }
            gray.erase(gray.find(node));
            black.insert(node);
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return true;
        buildgraph(numCourses, prerequisites);
        return !detectcycle();
    }
};
