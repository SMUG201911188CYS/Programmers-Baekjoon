#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> _time;
    
    for(const auto x : timetable)
    {
        int temp = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));
        _time.push_back(temp);
    }
    
    sort(_time.begin(), _time.end());
    
    int start_time = 540;
    int crew_time = 0;
    int size = timetable.size();
    int index = 0;
    int cnt = 0;
    string hour;
    string min;

    for(int i = 0; i < n; i++)
    {
        cnt = 0;
        
        for(; index < size && cnt < m; ++index, ++cnt)
        {
            if(_time[index] > start_time)
            {
                break;
            }
            
            crew_time = _time[index];
        }
        if(i < n - 1)
        {
            start_time += t;
        }
    }
    
    if(cnt == m)
    {
        crew_time -= 1;
    }
    else
    {
        crew_time = start_time;
    }
    
    if(crew_time / 60 < 10)
    {
        hour = "0" + to_string(crew_time / 60);
    }
    else
    {
        hour = to_string(crew_time / 60);
    }

    if(crew_time % 60 < 10)
    {
        min = "0" + to_string(crew_time % 60);
    }
    else
    {
        min = to_string(crew_time % 60);
    }
    
    answer = hour + ":" + min;

    return answer;
}