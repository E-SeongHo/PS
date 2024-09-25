#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<string> Image;

string quad_compress(int y, int x, int n)
{
    if(n == 1)
    {
        return Image[y][x] == '1' ? "1" : "0";
    }

    string first = quad_compress(y, x, n/2);
    string second = quad_compress(y, x+n/2, n/2);
    string third = quad_compress(y+n/2, x, n/2);
    string fourth = quad_compress(y+n/2, x+n/2, n/2);

    string sum = first + second + third + fourth;
    if(sum == "1111") return "1";
    if(sum == "0000") return "0";

    return "(" + sum + ")";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    Image.resize(N);

    for(int i = 0; i < N; ++i)
        cin >> Image[i];

    cout << quad_compress(0, 0, N);

    return 0;
}