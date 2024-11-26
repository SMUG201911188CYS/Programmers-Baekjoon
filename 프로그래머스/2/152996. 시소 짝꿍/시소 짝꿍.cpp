#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long GCD(long a, long b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
}

long LCM(long a, long b)
{
    return (a * b) / GCD(a, b);
}

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long, long> List;
    
    long _LCM = 0;
    
    for(int Index = 0; Index < weights.size(); ++Index)
    {
        List[weights[Index]] += 1;
    }
    
    for(auto& x : List)
    {
        if(x.second >= 2)
        {
            answer += x.second * (x.second - 1) / 2;
        }
        
        for(auto& y : List)
        {
            if(x.first == y.first)
            {
                continue;
            }
            
            _LCM = LCM(y.first, x.first);
            
            
            if(_LCM == y.first || _LCM == x.first)
            {
                _LCM *= 2;
            }
            
            if(_LCM / y.first >= 2 && _LCM / y.first <= 4 && _LCM / x.first >= 2 && _LCM / x.first <= 4)
            {
                answer += x.second * y.second;
            }
        }
        
        List.erase(x.first);
    }
    
    return answer;
}