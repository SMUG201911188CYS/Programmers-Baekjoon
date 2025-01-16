#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int Length = number.length();
    
    if(Length == k)
    {
        return answer;
    }
    
    for(int Idx = k; Idx < Length; ++Idx)
    {
        answer += number[Idx];
    }
    //cout << Length << '\n';
    
    int Count = 0;
    
    for(int Idx = k - 1; Idx >= 0; --Idx)
    {
        if(answer[0] <= number[Idx])
        {
            char Temp = answer[0];
            answer[0] = number[Idx];
            Count += 1;
            for(int Idx2 = 1; Idx2 < Length; ++Idx2)
            {
                if(answer[Idx2] <= Temp)
                {
                    char Temp2 = answer[Idx2];
                    answer[Idx2] = Temp;
                    Temp = Temp2;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return answer;
}