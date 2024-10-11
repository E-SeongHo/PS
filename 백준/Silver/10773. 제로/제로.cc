#include <iostream>
#include <vector>

using namespace std;

int K;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> K;
    vector<int> v;
    v.reserve(K);

    int sum = 0;
    for(int i = 0; i < K; ++i)
    {
        int n;
        cin >> n;
        if(n) 
        {
            v.push_back(n);
            sum += n;
        }
        else
        {
            sum -= v.back();
            v.pop_back();
        }
    }

    cout << sum;

    return 0;
}
