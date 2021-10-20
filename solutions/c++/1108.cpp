class Solution {
public:
    string defangIPaddr(string address) {
        auto length = address.size();
        for (auto i=0; i < address.size(); i++) {
            if (address[i] == '.') {
                address.insert(i+1,1,']');
                address.insert(i, 1, '[');
                i++;
            }
        }
        return address;
    }
};
