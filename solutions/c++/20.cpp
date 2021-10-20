//0ms runtime
class Solution {

public:
    bool isValid(string s) {
        if (s.empty()) return true;
        if (s.size() &1) {
            //cout << "quick fail";
            return false;
        }
        stack<char> st;
        for (int i=0; i < s.size(); i+=1) {
            //cout << s[i] << " ";
            if (s[i] == '(') {
                st.push('(');
                continue;
            }
            if (s[i] == '{') {
                st.push('{');
                continue;
            }
            if (s[i] == '[') {
                st.push('[');
                continue;
            }
            if (s[i] == ')') {
                if (st.empty()){
                    return false;
                }
                if (st.top() == '(') {
                    st.pop();
                    continue;
                } else {
                    //cout << "1";
                    return false;
                }
            }
            if (s[i] == '}') {
                if (st.empty()){
                    return false;
                }
                if (st.top() == '{') {
                    st.pop();
                    continue;
                } else {
                    //cout<< "2";
                    return false;
                }
            }
            if (s[i] == ']') {
                if (st.empty()){
                    return false;
                }
                if (st.top() == '[') {
                    st.pop();
                    continue;
                } else {
                    //cout <<"3";
                    return false;
                }
            }
            //cout<< "4";
            return false;
        }
        //cout <<"5";
        if (st.empty()){
            return true;
        } else {
            return false;
        }
    }
};
