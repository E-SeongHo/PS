#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> trees;
vector<long long> sum; // !!!size!!!

int find_height(int begin, int end, int falloff, int cut)
{
    for(int h = end; h >= begin; --h)
    {   
        cut += falloff;
        if(cut >= M) return h;
    }
    return -1;
}
int main()
{
    cin >> N >> M;
    trees.resize(N+1);
    sum.resize(N+1);

    for(int i = 1; i <= N; ++i)
    {
        cin >> trees[i];
    }

    if(M == 0)
    {
        cout << 0;
        return 0;
    }

    sort(trees.begin(), trees.end());
    
    int idx = -1;
    for(int i = trees.size()-2; i >= 0; --i)
    {
        sum[i] = (trees[i+1] - trees[i]) * (trees.size()-i-1) + sum[i+1];
        
        if(sum[i] >= M) 
        {
            idx = i;
            break;
        }
    }

    int falloff = trees.size()-1 - idx;
    int begin = trees[idx]+1;
    int end = trees[idx+1]-1;
    long long cut = sum[idx+1];

    int h = find_height(begin, end, falloff, cut);
    if(h == -1) h = trees[idx];

    cout << h;
    return 0;
}