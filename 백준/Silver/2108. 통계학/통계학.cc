#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> Cnts(8001, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int most_freq = 0;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        Cnts[num+4000]++;
        most_freq = max(most_freq, Cnts[num+4000]);
    }

    vector<int> v(N);
    int idx = 0;
    int sum = 0;
    int freq = 9999;
    bool freq_update = false;

    for(int i = 0; i < 8001; ++i)
    {
        for(int j = 0; j < Cnts[i]; ++j)
        {
            v[idx++] = i-4000;
            sum += i-4000;
        }

        if(Cnts[i] == most_freq)
        {
            if(freq == 9999) freq = i-4000;
            else if(!freq_update) 
            {
                freq = i-4000;
                freq_update = true;
            }
        }
    }

    cout << (int)round(float(sum) / N) << '\n';
    cout << v[N/2] << '\n';
    cout << freq << '\n';
    cout << v.back() - v.front() << '\n';
}