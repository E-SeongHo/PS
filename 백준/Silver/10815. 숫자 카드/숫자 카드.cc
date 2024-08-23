#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> Cards;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Cards.resize(N);
    for(int i = 0; i < N; ++i)
        cin >> Cards[i];

    sort(Cards.begin(), Cards.end());

    cin >> M;
    for(int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;

        bool has = false;
        int begin = 0;
        int end = N;
        while(begin < end)
        {
            int mid = begin + (end - begin) / 2;
            if(Cards[mid] == num) 
            {
                has = true;
                break;
            }
            if(Cards[mid] < num) begin = mid+1;
            else end = mid;
        }

        cout << has << " ";
    }

    return 0;
}