//%18 speed
class Solution {
     unordered_map<char, string> morse{
    {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
    {'f', "..-."}, {'g', "--."},  {'h', "...."}, {'i', ".."},   {'j', ".---"},
    {'k', "-.-"},  {'l', ".-.."}, {'m', "--"},   {'n', "-."},   {'o', "---"},
    {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
    {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"}, {'y', "-.--"},
    {'z', "--.."}

     };
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //cout << morse["a"];
        set<string> strset;
        for (auto &word : words) {
            string code;
            for (char letter : word) {
                code.append(morse[letter]);
            }
             cout << code << endl;
            strset.insert(code);
        }
        return strset.size();
    }

};

//%81 speed
class Solution {
    const unordered_map<char, string> morse{
    {'a', ".-"},   {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."},
    {'f', "..-."}, {'g', "--."},  {'h', "...."}, {'i', ".."},   {'j', ".---"},
    {'k', "-.-"},  {'l', ".-.."}, {'m', "--"},   {'n', "-."},   {'o', "---"},
    {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},  {'s', "..."},  {'t', "-"},
    {'u', "..-"},  {'v', "...-"}, {'w', ".--"},  {'x', "-..-"}, {'y', "-.--"},
    {'z', "--.."}

     };
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        //cout << morse["a"];
        set<string> strset;
        for (auto &word : words) {
            string code;
            for (char letter : word) {
                //const char &
                code.append(morse.at(letter));
            }
             cout << code << endl;
            strset.insert(code);
        }
        return strset.size();
    }

};
