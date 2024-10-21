#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;


int bfs(int i, int j, vector<string> maps, vector<vector<bool>> & isCheck, int v_size, int s_size)
{
    int x[4] = {0, 1, -1, 0};
    int y[4] = {1, 0, 0, -1};
    stack<pair<int, int>> s;
    int cnt = 0;
    
    s.emplace(i, j);
    
    while(!s.empty())
    {
        pair<int, int> pos = s.top();
        s.pop();
        
        if(pos.first < 0 || pos.first >= v_size)
            continue;
        if(pos.second < 0 || pos.second >= s_size)
            continue;
        if(isCheck[pos.first][pos.second])
            continue;
        if(maps[pos.first][pos.second] == 'X')
            continue;
        
        cnt += maps[pos.first][pos.second] - '0';
        
        isCheck[pos.first][pos.second] = true;
        
        for(int k = 0; k < 4; k++)
        {
            s.emplace(pos.first + x[k], pos.second + y[k]);
        }
        
    }
    
    return cnt;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int v_size = maps.size();
    int s_size = maps[0].size();
    
    vector<vector<bool>> isCheck(v_size, vector<bool>(s_size, false));
    
    
    for(int i = 0; i < v_size; i++)
    {
        for(int j = 0; j < s_size; j++)
        {
            if(maps[i][j] != 'X' && !isCheck[i][j])
            {
                int cnt = bfs(i, j, maps, isCheck, v_size, s_size);
                answer.push_back(cnt);
            }
        }
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }
    
    /*for(auto x : answer)
    {
        cout << x << ", " << '\n';
    }*/
    
    return answer;
}