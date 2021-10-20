//27% speed
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ans;//coolest data structure yet
        for (const auto & word : strs) {
            string key(word);
            sort(key.begin(), key.end());
            //I built the key for this word
            if (ans.count(key) > 0) {
                ans.at(key).push_back(word);
            } else {
                ans.insert({key, vector<string>{word}});
            }
        }
        vector<vector<string>> converted;
        for (auto kvpair : ans) {
            converted.push_back(move(kvpair.second));
        }
        return  converted;
    }
};

//5% speed
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>,vector<string>> ans;//coolest data structure yet
        for (const auto & word : strs) {
            multiset<char> chrset;
            for (const auto & letter : word) {
                    chrset.insert(letter);
            }
            //I built the key for this word
            if (ans.count(chrset) > 0) {
                ans.at(chrset).push_back(word);
            } else {
                ans.insert({chrset, vector<string>{word}});
            }
        }
        vector<vector<string>> converted;
        for (auto kvpair : ans) {
            converted.push_back(move(kvpair.second));
        }
        return  converted;
    }
};
