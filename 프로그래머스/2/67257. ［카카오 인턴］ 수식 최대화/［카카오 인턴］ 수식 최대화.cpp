#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long operate(long long n1, long long n2, char op)
{
    long long ret = -1;
    if(op == '+') ret = n1 + n2;
    else if(op == '-') ret = n1 - n2;
    else if(op == '*') ret = n1 * n2;
    
    return ret;
}
long long solution(string expression) {
    long long answer = 0;
    
    int num = 0;
    vector<long long > numsOrigin;
    vector<char> operatorsOrigin;
    for(auto c : expression)
    {
        if(c < '0' || c > '9')
        {
            numsOrigin.push_back(num);
            num = 0;
            operatorsOrigin.push_back(c);
        }
        else
        {   
            num *= 10;
            num += c - '0';           
        }
    }
    numsOrigin.push_back(num);
    
    vector<char> orders = {'*', '+', '-'};
    sort(orders.begin(), orders.end());
    do
    {
        vector<long long> nums(numsOrigin);
        vector<char> operators(operatorsOrigin);
        
        for(auto o : orders)
        {
            for(int i = 0; i < operators.size(); i++)
            {
                if(o == operators[i])
                {
                    long long res = operate(nums[i], nums[i+1], operators[i]);
                    nums[i] = res;
                    nums.erase(nums.begin() + i+1);
                    operators.erase(operators.begin() + i);
                    i--;
                }
            }
        }
        long long sum = nums[0];
        answer = max(answer, abs(sum));
    } 
    while(next_permutation(orders.begin(), orders.end()));
    
    return answer;
}