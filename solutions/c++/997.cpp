//%88 speed

//solution inspired from https://leetcode.com/problems/find-the-town-judge/discuss/242938/JavaC%2B%2BPython-Directed-Graph
//thank you
class Solution {
public:
    int findJudge(const int N, vector<vector<int>>& trust) {

        vector<int> count(N+1,0);
        //each person is a node on a directed graph
        //the judge has a special property that edges in - edges out = N-1
        //I have a vector, count, for in - out edges
        for (auto & person : trust) {
            count.at(person[0])--;
            count.at(person[1])++;
        }
        for (int i=1; i < count.size();i++) {
            if (count[i] == N-1)
                return i;
        }
        return -1;
    }
};
