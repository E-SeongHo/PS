#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    for(auto n : nums)
        m[n]++;

    int size = nums.size();
    
    int answer = min(size/2, static_cast<int>((m.size())));
    
    return answer;
}