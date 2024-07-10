#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    if((sum1 + sum2) % 2 == 1) return -1;
    
    queue1.reserve(queue1.size() + queue2.size());
    queue2.reserve(queue1.size() + queue2.size());
    
    int front1 = 0;
    int front2 = 0;
    
    int cnt = 0;
    while(front1 < queue1.size() && front2 < queue2.size())
    {  
        // why...?
        if(cnt > 300000 * 2) return -1;
        
        if(sum1 == sum2) return cnt;
        
        if(sum1 > sum2)
        {
            int temp = queue1[front1++];
            queue2.push_back(temp);

            sum2 += temp;
            sum1 -= temp;
        }
        else
        {
            int temp = queue2[front2++];
            queue1.push_back(temp);

            sum2 -= temp;
            sum1 += temp;
        }
        cnt++;
    }
    
    return -1;
}