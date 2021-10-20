//%90 speed
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
       bool is_dig_log = [] (const string & a) {
         auto space_pos_a = a.find(' ');
         return isdigit(a[space_pos_a]);
       };
            auto it = stable_partition(logs.begin(), logs.end(), [] (const string & a) {
         auto space_pos_a = a.find(' ');
         return !isdigit(a[space_pos_a+1]);
       });
      sort(logs.begin(),it,[](const string & a, const string & b){
          if (a.substr(a.find(' ')+1) == b.substr(b.find(' ')+1)) {
              return a < b;
          }
          return a.substr(a.find(' ')+1) < b.substr(b.find(' ')+1);
      });
        return logs;
    }

};
