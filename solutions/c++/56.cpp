//%44 speed
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto size = intervals.size();
        if (size == 0) {
            return {};
        }
        if (size == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const auto & a, const auto & b){
            return a[0] < b[0];
        });
        auto print = [&intervals]() {
          for (auto & x : intervals)  {
              cout << "["<< x[0] << " " << x[1] << "] ";
          }
            cout << endl;
        };
        for (auto index = intervals.begin()+1; index != intervals.end(); index++) {
            vector<int>& current = *index;
            vector<int>& prev = *(index-1);
            if (current[0] <= prev[1]) {
                int start = min(current[0], prev[0]);
                int finish = max(current[1], prev[1]);
                prev[0]=10;
                prev[1]=1;
                current[0]=start;
                current[1]=finish;

            }
        }
        print();
        intervals.erase(remove_if(intervals.begin(),
                                  intervals.end(), [](const auto & interval){ return interval[0] > interval[1];}),
                        intervals.end());
        return intervals;
    }
};

//%0 speed
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto size = intervals.size();
        if (size == 0) {
            return {};
        }
        if (size == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const auto & a, const auto & b){
            return a[0] < b[0];
        });
        auto print = [&intervals]() {
          for (auto & x : intervals)  {
              cout << "["<< x[0] << " " << x[1] << "] ";
          }
            cout << endl;
        };
        for (auto index = intervals.begin()+1; index != intervals.end(); index++) {
            vector<int>& current = *index;
            vector<int>& prev = *(index-1);
            if (current[0] <= prev[1]) {
                int start = min(current[0], prev[0]);
                int finish = max(current[1], prev[1]);
                index=intervals.erase(index-1);
                (*index)[0]=start;
                (*index)[1]=finish;
            }

        }
        return intervals;
    }
};
