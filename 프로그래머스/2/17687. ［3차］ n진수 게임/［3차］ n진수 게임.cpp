#include <string>
#include <vector>
#include <iostream>

using namespace std;

string translate(int num, int notation)
{
    string ret;
    while(num)
    {
        int digit = num % notation;
        string s;
        if(digit >= 10)
        {
            switch(digit)
            {
                case 10:
                    s = "A";
                    break;
                case 11:
                    s = "B";
                    break;
                case 12:
                    s = "C";
                    break;
                case 13:
                    s = "D";
                    break;
                case 14:
                    s = "E";
                    break;
                case 15:
                    s = "F";
                    break;
            }            
        }
        else
        {
            s = to_string(digit);
        }
        
        ret = s + ret;
        num = num / notation;
    }
    
    return ret;
}
    
string solution(int n, int t, int m, int p) {
    
    if(p == m) p = 0;
    
    int num = 0;
    string s = "0";
    
    int turn = 1;
    string ret;
    
    while(1)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if((turn % m) == p)
            {
                ret += s[i];
            }
            turn++;
            
            if(ret.size() == t) return ret;
        }
        s = translate(++num, n);
    }
    
    return "";
}