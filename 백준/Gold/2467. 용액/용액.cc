#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Liquids;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Liquids.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Liquids[i];

    int head = 0;
    int tail = N-1;

    int ans = 2000000000;
    int l1 = Liquids[head];
    int l2 = Liquids[tail];
    
    while(head < tail)
    {
        int combine = Liquids[head] + Liquids[tail];

        if(abs(combine) < ans)
        {
            ans = abs(combine);
            l1 = Liquids[head];
            l2 = Liquids[tail];
        }

        if(combine >= 0) tail--;
        else head++;
    }

    cout << l1 << " " << l2;
    return 0;
}