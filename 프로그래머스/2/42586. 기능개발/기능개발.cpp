#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int complete_day = 0;
        int cnt = progresses[i];
        
        while(cnt < 100)
        {
            cnt += speeds[i];
            complete_day++;
        }
        
        cout << complete_day << '\n';
        q.push(complete_day);
    }
    
    
    while(!q.empty())
    {
        int function_cnt = 1;
        int publish = q.front();
        q.pop();
        
        cout << "p : " << publish << '\n';
        
        while(!q.empty())
        {
            int next_publish = q.front();
            cout << "np : " << next_publish << '\n';
            
            if(publish >= next_publish)
            {
                q.pop();
                function_cnt++;
            }
            else
            {
                break;
            }
        }
        
        answer.push_back(function_cnt);
        
    }
    
    return answer;
}