#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int>& PA, pair<int, int>& PB)
{
    if(PA.second > PB.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> UM;
    
    for(const auto& x : tangerine)
    {
        UM[x] += 1;
    }
    
    vector<pair<int, int>> TangerineVector(UM.begin(), UM.end());
    
    sort(TangerineVector.begin(), TangerineVector.end(), Compare);
    
    for(int i = 0; i < TangerineVector.size(); i++)
    {
        if(k <= 0)
        {
            break;
        }
        
        k -= TangerineVector[i].second;
        answer += 1;
    }
    
    return answer;
}