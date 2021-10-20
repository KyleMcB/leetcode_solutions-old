//4ms runtime. Why did I write it that way? We all start from somewhere.
class Solution {
public:
    string toLowerCase(string str) {
        if (str.empty()) return str;
        for (int i = str.size(); i >= 0;i--) {
            if (str[i] <= 'Z')
                if (str[i] >= 'A')
                    str[i]+=32;
        }
        return str;
    }
};
