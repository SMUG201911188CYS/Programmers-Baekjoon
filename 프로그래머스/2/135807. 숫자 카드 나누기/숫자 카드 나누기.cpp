#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int A, int B)
{
    if(B == 0)
    {
        return A;
    }
    else
    {
        return GCD(B, A % B);
    }
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    bool FlagA = false;
    bool FlagB = false;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    if(arrayA.size() == 1)
    {
        if(arrayA[0] != arrayB[0])
        {
            answer = max(arrayA[0], arrayB[0]);
        }
        return answer;
    }
    
    int GCD_A = arrayA[0];
    int GCD_B = arrayB[0];
    
    for(int i = 1; i < arrayA.size(); ++i)
    {
        GCD_A = GCD(arrayA[i], GCD_A);
        GCD_B = GCD(arrayB[i], GCD_B);
    }
    
    if(GCD_A == 1 && GCD_B == 1)
    {
        return answer;
    }
    else
    {
        for(int i = 0; i < arrayA.size(); ++i)
        {
            if(arrayA[i] % GCD_B == 0)
            {
                FlagB = true;
                break;
            }
        }
        for(int i = 0; i < arrayA.size(); ++i)
        {
            if(arrayB[i] % GCD_A == 0)
            {
                FlagA = true;
                break;
            }
        }
        
        if(!FlagA && !FlagB)
        {
            answer = max(GCD_A, GCD_B);
        }
        else if(!FlagA && FlagB)
        {
            answer = GCD_A;
        }
        else if(FlagA && !FlagB)
        {
            answer = GCD_B;
        }
    }
    
    return answer;
}