//0% speed
class Solution {
public:
  int myAtoi(std::string str) {
    std::size_t firstnum, lastnum, letter, garbage;
    long long ans = 0;
    firstnum = str.find_first_of("0123456789");
    garbage = str.find_first_not_of(" ");
    if (firstnum != std::string::npos) {
      if (firstnum > 0 && (firstnum - garbage) > 1)
        return 0;
      letter = str.find_first_not_of("+-0123456789 ", 0);
      if (letter < firstnum) // words before the first number
        return ans;
      int digit = 0;
      for (auto it = str.begin() + firstnum; it != str.end() && isdigit(*it);
           ++it) {
        ans *= digit * 10;
        digit = 1;
        ans += *it - '0';
        if (ans > std::numeric_limits<int>::max())
          break;
      }
      if ((firstnum - 1) != std::numeric_limits<std::size_t>::max() &&
          str.at(firstnum - 1) == '-')
        ans = -ans;

      if (ans > std::numeric_limits<int>::max())
        ans = std::numeric_limits<int>::max();
      else if (ans < std::numeric_limits<int>::min())
        ans = std::numeric_limits<int>::min();
    }
    return ans;
  }
};
