#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> MaxBoard;
vector<int> MaxTemp;
vector<int> MinBoard;
vector<int> MinTemp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    MaxBoard.resize(3);
    MaxTemp.resize(3);
    MinBoard.resize(3);
    MinTemp.resize(3);

    for(int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        MaxTemp[i] = MinTemp[i] = num;
    }
    

    for(int i = 1; i < N; i++)
    {
        vector<int>& MaxBoardRef = i % 2 == 1 ? MaxBoard : MaxTemp;
        vector<int>& MaxTempRef = i % 2 == 1 ? MaxTemp : MaxBoard;
        vector<int>& MinBoardRef = i % 2 == 1 ? MinBoard : MinTemp;
        vector<int>& MinTempRef = i % 2 == 1 ? MinTemp : MinBoard;
        
        for(int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            if(j == 0)
            {
                MaxBoardRef[j] = num + max(MaxTempRef[j], MaxTempRef[j+1]);
                MinBoardRef[j] = num + min(MinTempRef[j], MinTempRef[j+1]);
            }
            else if(j == 2)
            {
                MaxBoardRef[j] = num + max(MaxTempRef[j-1], MaxTempRef[j]);
                MinBoardRef[j] = num + min(MinTempRef[j-1], MinTempRef[j]);
            }
            else
            {
                MaxBoardRef[j] = num + max(max(MaxTempRef[j-1],MaxTempRef[j]), MaxTempRef[j+1]);
                MinBoardRef[j] = num + min(min(MinTempRef[j-1],MinTempRef[j]), MinTempRef[j+1]);
            }
        }
    }

    vector<int>& MaxBoardRef = N % 2 == 0 ? MaxBoard : MaxTemp;
    vector<int>& MinBoardRef = N % 2 == 0 ? MinBoard : MinTemp;
    
    int maxE = *max_element(MaxBoardRef.begin(), MaxBoardRef.end());
    int minE = *min_element(MinBoardRef.begin(), MinBoardRef.end());

    cout << maxE << " " << minE;

    return 0;
}