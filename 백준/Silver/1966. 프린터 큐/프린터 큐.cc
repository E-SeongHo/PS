#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        cin >> N >> M;
        queue<pair<int, bool>> q;
        priority_queue<int> pq;

        for(int i = 0; i < N; ++i)
        {
            int rank;
            cin >> rank;
            if(i == M) q.push({rank, true});
            else q.push({rank, false});

            pq.push(rank);
        }

        int cnt = 0;
        while(true)
        {
            if(pq.top() == q.front().first)
            {
                if(q.front().second) break;

                pq.pop();
                q.pop();
                cnt++;
            }
            else 
            {
                q.push(q.front());
                q.pop();
            }
        }

        cout << cnt+1 << '\n';
    }
    return 0;
}