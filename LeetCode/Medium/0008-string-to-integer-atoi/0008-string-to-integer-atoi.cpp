class Solution {
public:
    int myAtoi(string s) {

        const int MAX = 2147483647;
        const int MIN = -2147483648;
        
        bool started = false;
        int sign = 1;
        int sum = 0;

        for(auto c : s)
        {
            bool flag = false;
            if(started)
            {
                if(c >= '0' && c <= '9') flag = true;
                else break;
            }
            else
            {
                if(c >= '0' && c <= '9') 
                {
                    flag = true;
                    started = true;
                }
                else if(c == '-') 
                {
                    sign = -1; 
                    started = true;   
                }
                else if(c == '+')
                {
                    sign = +1;
                    started = true;
                } 
                else if(c == ' ') continue;
                else return 0;
            }

            if(flag)
            {
                int digit = c - '0';
                if(sum > MAX / 10 || sum == MAX / 10 && digit > MAX % 10)
                    return sign == 1 ? MAX : MIN;
                
                sum *= 10;
                sum += digit;
            }
            
        }

        return sign * sum;
    }
};