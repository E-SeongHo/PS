#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int open = 0;
    
    for(auto paren : s)
    {
        if(paren == '(') open++;
        else if(paren == ')') open--;
        
        if(open < 0) return false;
    }
    
    return open == 0;
}