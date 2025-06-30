#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    if(a.second > b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector<int> solution(string s) {
    unordered_map<string, int> List;
    string Temp = "";
    
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            Temp += s[i];
        }
        else if((s[i] == '}' || s[i] == ',') && Temp != "")
        {
            List[Temp] += 1;
            Temp = "";
        }
    }
    
    vector<pair<string, int>> ListToVec(List.begin(), List.end());
    vector<int> answer(ListToVec.size(), 0);
    
    sort(ListToVec.begin(), ListToVec.end(), cmp);
    
    int Index = 0;
    
    for(const auto x : ListToVec)
    {
        answer[Index] = stoi(x.first);
        Index += 1;
    }
    
    return answer;
}