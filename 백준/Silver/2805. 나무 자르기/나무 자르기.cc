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

int binary_find(int begin, int end, int falloff, int pivot_idx)
{
    if(begin >= end) 
    {
        int cut = sum[pivot_idx] + (trees[pivot_idx] - begin) * falloff;
        if(cut < M) return begin-1;
        else return begin;
    }
    
    int mid = (begin + end) / 2;
    long long cut = sum[pivot_idx] + (trees[pivot_idx] - mid) * (long long)falloff; 

    if(cut > M) return binary_find(mid+1, end, falloff, pivot_idx);
    else if(cut < M) return binary_find(begin, mid-1, falloff, pivot_idx);
    else return mid;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
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
    int begin = trees[idx];
    int end = trees[idx+1]-1;
    long long cut = sum[idx+1];

    //int h = find_height(begin, end, falloff, cut);
    int h = binary_find(begin, end, falloff, idx+1);

    cout << h;
    return 0;
}