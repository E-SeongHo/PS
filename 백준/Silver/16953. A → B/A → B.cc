#include <iostream>
#include <time.h>

using namespace std;

int count = 1; // 전역변수로 선언 : 연산횟수에 1 더한 값을 출력해야 하므로 1로 초기화

// src에서 des로 바꿀수 있는가를 판별하고, 그에 따른 정해진 값(count)을 출력하는 함수
void Solve(int src, int des, int last) // last는 des의 마지막 자리 수
{
    if (src == des) return; // source와 destination이 같으면 바꿀 수 있는 경우이므로 return
    if (src > des) // source가 destination보다 크면 바꿀수 없는 경우이므로 count는 -1 
    {
        count = -1;
        return;
    }
    else // 그 외의 경우
    {
        count++; // 일단 count를 1 증가시킨다.
        switch(last)
        {
            // des의 마지막 자리수가 3,5,7,9면 변환이 불가능하다.
            case 3 :
            case 5 :
            case 7 :
            case 9 :
                count = -1;
                break;
            // des의 마지막 자리수가 0,2,4,6,8이면 변환이 가능 할 수도 있다.
            // des를 2로 나누고 그 수가 가능한 변환인지 다시 한 번 판별
            case 0 :
            case 2 :
            case 4 :
            case 6 :
            case 8 :
                Solve(src, des/2, (des/2)%10);
                break;
            // des의 마지막 자리수가 1이면 변환이 가능 할 수도 있다.
            // des의 마지막 숫자 1을 빼고(des/10) 그 수가 가능한 변환인지 다시 한 번 판별
            case 1 :
                Solve(src, des/10, (des/10)%10);
                break;
        }
        return;
    }
}

int main()
{
    int src; // 변환하려는 숫자
    int des; // 목표하는 숫자
    cin >> src >> des; // 입력처리

    clock_t start = clock(); 
    Solve(src, des, des%10); // 함수 재귀호출을 통한 해결
    clock_t end = clock();

    // 전역변수 count를 출력 및 실행시간 출력
    cout << count << endl; 
    // cout << "Run Time : " << (double)(end - start)/CLOCKS_PER_SEC << "sec" << endl;
    return 0;
}