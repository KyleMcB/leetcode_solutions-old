//%22 speed
class Solution {
public:
    string minWindow(const string & s, const string & t) {
        int l=0,r=0;
        string ans;
        unordered_map <char,int> charset;
        int satisfied=0;
        for (char c : t) {
            if (charset.count(c)) {
                charset.at(c)--;
            } else {
                charset.insert({c,0});
            }
        }
        if (charset.count(s[0]) > 0) {
            charset.at(s[0])+=1;
            if (charset.at(s[0]) == 1)
                satisfied+=1;
        }
        while (r < s.size() || l < s.size()) {
            if (satisfied == charset.size()) {
                if (ans.empty() || ans.size() > r-l+1) {
                    ans=s.substr(l,r-l+1);
                }
                if (charset.count(s[l])) {
                    charset.at(s[l])--;
                    if (charset.at(s[l]) == 0) {
                        satisfied--;
                    }
                }
                l++;
            } else {
                r++;
                if (r < s.size()) {

                    if (charset.count(s[r])) {
                        cout << charset.at(s[r]);
                        charset.at(s[r])++;
                        if (charset.at(s[r]) == 1) {
                            satisfied++;
                        }
                    }
                } else if (r == s.size()) break;
            }
        }
        return ans;
    }
};


//%12 speed
class Solution {
public:
    string minWindow(const string & s, const string & t) {
        int l=0,r=0;
        string ans;
        map <char,int> charset;
        int satisfied=0;
        for (char c : t) {
            if (charset.count(c)) {
                charset.at(c)--;
            } else {
                charset.insert({c,0});
            }
        }
        if (charset.count(s[0]) > 0) {
            charset.at(s[0])+=1;
            if (charset.at(s[0]) == 1)
                satisfied+=1;
        }
        while (r < s.size() || l < s.size()) {
            if (satisfied == charset.size()) {
                if (ans.empty() || ans.size() > r-l+1) {
                    ans=s.substr(l,r-l+1);
                }
                if (charset.count(s[l])) {
                    charset.at(s[l])--;
                    if (charset.at(s[l]) == 0) {
                        satisfied--;
                    }
                }
                l++;
            } else {
                r++;
                if (r < s.size()) {

                    if (charset.count(s[r])) {
                        cout << charset.at(s[r]);
                        charset.at(s[r])++;
                        if (charset.at(s[r]) == 1) {
                            satisfied++;
                        }
                    }
                } else if (r == s.size()) break;
            }
        }
        return ans;
    }
};
