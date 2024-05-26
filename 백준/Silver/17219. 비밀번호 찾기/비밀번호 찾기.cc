#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int N, M;
unordered_map<string, string> PassWords;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string address, password;
        cin >> address >> password;

        PassWords[address] = password;
    }

    for(int i = 0; i < M; i++)
    {
        string address;
        cin >> address;

        cout << PassWords[address] << "\n";
    }

    return 0;
}