#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string>b)
{
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<int, string>> _plans;
    unordered_map<string, int> u_m;
    
    for(auto x : plans)
    {
        string time = x[1];
        int temp = (stoi(time.substr(0, 2)) * 60) + (stoi(time.substr(3)));
        u_m[x[0]] = stoi(x[2]);
        _plans.emplace_back(temp, x[0]);
    }

    sort(_plans.begin(), _plans.end());
    
    
    int size = plans.size();
    int index = 0;
    int time = _plans[index].first;
    string job = _plans[index].second;
    stack<string> s;
    
    index++;
    
    while(index < size)
    {
        //cout << job << ", " << time << '\n';
        
        if(time + u_m[job] > _plans[index].first)
        {
            s.push(job);
            u_m[job] -= _plans[index].first - time;
            //cout << "stack push : " << job << ", left time : " << u_m[job] << '\n';
        }
        else
        {
            answer.push_back(job);
            
            time += u_m[job];
            
            //cout << "answer push : " << job << ", time : " << time << '\n';
            
            while(!s.empty())
            {
                job = s.top();
                //cout << "stack job : " << job << ", " << time << '\n';
                if(u_m[job] + time <= _plans[index].first)
                {
                    //cout << "answer push : " << job << ", time : " << time << '\n';
                    answer.push_back(job);
                    time += u_m[job];
                    s.pop();
                }
                else
                {
                    u_m[job] -= _plans[index].first - time;
                    //cout << "stack push : " << job << ", left time : " << u_m[job] << '\n';
                    break;
                }
            }
        }

        time = _plans[index].first;
        job = _plans[index].second;
        index++;
    }
    
    //cout << "answer push : " << job << '\n';
    answer.push_back(job);
    
    while(!s.empty())
    {
        job = s.top();
        //cout << "answer push : " << job << '\n';
        s.pop();
        answer.push_back(job);
    }
    
    return answer;
}