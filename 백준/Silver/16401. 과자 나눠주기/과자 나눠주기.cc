#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<int> Snacks;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N;
    Snacks.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Snacks[i];

    sort(Snacks.begin(), Snacks.end());

    int begin = 1;
    int end = Snacks.back();

    while(begin <= end)
    {
        int mid = begin + (end - begin) / 2;

        int num = 0;
        for(auto snack : Snacks)
            num += snack / mid;

        if(num >= M) begin = mid+1;
        else end = mid-1;
    }

    cout << end;
    
    return 0;
}