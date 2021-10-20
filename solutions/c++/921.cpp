//0ms runtime
class Solution {
public:
    int minAddToMakeValid(string S) {
        uint64_t open=0, closed=0;
        for (auto & letter : S) {
            if (letter =='(') {
                open++;
            }else if (letter == ')') {
                if (open > 0) {
                    open--;
                } else{
                    closed++;
                }
            }
        }
        return open + closed;
    }
};
