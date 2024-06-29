#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    
    stringstream sstream(s);
    string buffer;
    
    int prev = 0;
    int answer = 0;
    while(getline(sstream, buffer, ' '))
    {
        if(buffer == "Z") answer -= prev;
        else
        {
            int current = stoi(buffer);
            answer += current;
            prev = current;
        }
            
    }
    
    return answer;
}