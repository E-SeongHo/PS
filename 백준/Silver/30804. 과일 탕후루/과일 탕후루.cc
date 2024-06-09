#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N; // 1 <= N <= 200,000 
vector<int> Fruits; // 1 ~ 9
vector<int> Table;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    Fruits.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> Fruits[i];
    }

    int ret = -1;
    int ptr = 0;
    vector<int> has(10, 0);

    for(int i = 0; i < N; i++)
    {
        has[Fruits[i]]++;

        int cnt = 0;
        for(int j = 1; j < 10; j++)
        {
            if(has[j]) cnt++;
        }

        while(cnt > 2)
        {
            has[Fruits[ptr]]--;
            if(!has[Fruits[ptr]]) cnt--;

            ptr++;
        }

        ret = max(ret, accumulate(has.begin(), has.end(), 0));
    }

    cout << ret;
    return 0;
}