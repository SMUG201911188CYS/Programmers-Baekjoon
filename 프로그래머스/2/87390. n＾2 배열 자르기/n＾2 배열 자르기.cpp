#include <string>
#include <vector>
#include <iostream>

using namespace std;

//1234 -> 0 / 2234 -> 1 / 3334 -> 2 / 4444 -> 3

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    
    int cnt = 0;
    for(long long i = left; i <= right; ++i)
    {
        long long A = i / n; // 자릿 수
        long long B = i % n; // 인덱스 번호
        long long Value = 0;
        
        if(A >= B)
        {
            Value = A + 1;     
        }
        else
        {
            Value = (A + 1) + (B - A);     
        }
        //cout << A << ", " << B << ", " << Value << '\n';
        
        answer[cnt++] = Value;
    }
    
    return answer;
}