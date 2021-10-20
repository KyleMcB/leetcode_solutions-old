//0ms runtime
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int result=0;
        fill_set(J, jewels);
        auto size=S.size();
        for (auto i=0; i<size;i++) {
            if (jewels.count(S[i]) > 0) {
                result++;
            }
        }
        return result;
    }
    void fill_set(string& input, unordered_set<char>& theset) {
        auto size = input.size();
        for (auto i=0;i < size;i++) {
            theset.insert(input[i]);
        }
    }
};
