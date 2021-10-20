//77% speed
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) {
            return s;
        }
        pair<int,int> onletter = on_a_letter(s);
        pair<int,int> betweenletter = between_letters(s);
        //cout << betweenletter.second << endl;
        cout << onletter.second*2 +1 << " " << betweenletter.second*2+2 << endl;
        if (onletter.second *2 +1 > betweenletter.second*2+2) {
           // cout << "expected\n";
           // cout << onletter.first << endl << onletter.second << endl;
            return s.substr(onletter.first - onletter.second, onletter.second*2+1);
        } else {
           // cout << "why?\n";
        return s.substr(betweenletter.first - betweenletter.second, betweenletter.second*2+2);
        }
    }
    //I need a function to find the longest palindrone on a letter
    pair<int,int> on_a_letter(const string & line) {
        int pos=0,size=0;
        for (int index=1; index < line.size()-1; index++) {
            for (int distance=1; index-distance >= 0 && index+distance < line.size(); distance++) {
                if (line[index-distance] == line[index+distance]) {
                    //cout << line[index-distance] << line[index+distance] <<endl;
                    if (distance > size) {
                        pos=index;
                        size=distance;
                    }
                }
                else {
                    break;
                }
            }
        }
        //if (size)
        return pair<int,int>(pos, size);
    }
    //I need afunction to find the L. Palin. inbetween letters
    pair<int,int> between_letters(const string & line) {
       int pos=0,size=-1;
        for (int index=0; index < line.size()-1; index++) {
            if (line[index] == line[index+1]) {
                for(int distance =0;index-distance >= 0 && index+distance < line.size();distance++) {
                    if (line[index-distance] == line[index+distance+1]) {
                        if (distance > size) {
                            pos=index;
                            size=distance;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return pair<int,int>(pos,size);
    }
};
