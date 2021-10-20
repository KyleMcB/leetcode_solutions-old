//slow
class Solution {
public:
    int reverse(int x) {

   //     std:: cout << sizeof(int);
        std::vector<int> str;
        bool sign=(x < 0)?true:false;
        int digit=0;
        while (x!=0) {
           digit=x%10;
         //   std::cout<< digit;
            str.push_back(digit);
            x=x-digit;
            x/=10;
        }

        //now digit will be used as 10^x
        digit=str.size()-1;
        int max=pow(2, 31)-1;
        int min=-1* pow(2,31);
        for (std::vector<int>::iterator it=str.begin(); it != str.end(); ++it) {
            if (*it *pow(10, digit) +x > max) return 0;
            if (*it *pow(10, digit) +x < min) return 0;
            x+=*it * pow(10, digit);
            digit-=1;
        }
        std::cout<<x<<endl;
       // x*=((sign)?-1:1);
        bool signx= (x < 0)?true:false;
        return x;
    }
};
