#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int min_fatigue;
unordered_map<string, unordered_map<string, int>> u_m;

void mining(const vector<string> & minerals, const vector<string> & _picks)
{
    int cnt = 0;
    int fatigue = 0;
    int pick_cnt = 0;
    int size = minerals.size();
    int pick_size = _picks.size();
    
    vector<vector<int>> cost = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
    
    
    while(true)
    {
        if(cnt >= size || pick_cnt >= pick_size)
        {
            min_fatigue = min(fatigue, min_fatigue);
            break;
        }
        
        for(int i = 0; i < 5 && cnt < size; i++, cnt++)
        {
            fatigue += u_m[_picks[pick_cnt]][minerals[cnt]];
        }
        
        pick_cnt++;
    }
    
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    min_fatigue = 1e9;
    
    vector<string> picks_str = {"dia", "iron", "stone"};
    
    u_m["dia"]["diamond"] = 1;
    u_m["dia"]["iron"] = 1;
    u_m["dia"]["stone"] = 1;
    
    u_m["iron"]["diamond"] = 5;
    u_m["iron"]["iron"] = 1;
    u_m["iron"]["stone"] = 1;
    
    u_m["stone"]["diamond"] = 25;
    u_m["stone"]["iron"] = 5;
    u_m["stone"]["stone"] = 1;
    
    vector<string> _picks;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < picks[i]; j++)
        {
            _picks.push_back(picks_str[i]);
        }
    }
    
    do
    {
        mining(minerals, _picks);   
    }while(next_permutation(_picks.begin(), _picks.end()));
    
    return min_fatigue;
}