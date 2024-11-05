#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 1e9;

struct info
{
    int x;
    int y;
    int cnt;
    
    info(int X, int Y, int CNT) : x(X), y(Y), cnt(CNT) {}
};

int min_lever;
int min_exit;
int size_x;
int size_y;
int start_x;
int start_y;

int _x[4] = {1, 0, -1, 0};
int _y[4] = {0, 1, 0, -1};

void find_target(char target, const vector<string> & maps, vector<vector<bool>> & is_visited, int cnt, int x, int y)
{
 
    queue<info> q;
    
    q.emplace(info(x, y, cnt));

    while(!q.empty())
    {
        int current_x = q.front().x;
        int current_y = q.front().y;
        int current_cnt = q.front().cnt;
    
        q.pop();
        
        if(current_x >= size_x || current_x < 0)
        {
            continue;
        }
        if(current_y >= size_y || current_y < 0)
        {
            continue;
        }

        if(maps[current_y][current_x] == target)
        {
            if(target == 'L')
            {
                if(min_lever > current_cnt)
                {
                    start_x = current_x;
                    start_y = current_y;
                    min_lever = current_cnt;
                }
            }
            else
            {
                min_exit = min(min_exit, current_cnt);
            }
            continue;
        }

        if(is_visited[current_y][current_x])
        {
            continue;
        }
        if(maps[current_y][current_x] == 'X')
        {
            continue;
        }
        
        is_visited[current_y][current_x] = true;
        
        for(int i = 0; i < 4; i++)
        {
            int next_x = current_x + _x[i];
            int next_y = current_y + _y[i];
            int next_cnt = current_cnt + 1;
            
            q.emplace(next_x, next_y, next_cnt);
        }
    }

}

int solution(vector<string> maps) {
    int answer = 0;
    
    min_lever = MAX;
    min_exit = MAX;
    
    size_x = maps[0].size();
    size_y = maps.size();
    
    bool flag = false;
    
    vector<vector<bool>> is_visited1(size_y, vector<bool>(size_x, false));
    vector<vector<bool>> is_visited2(size_y, vector<bool>(size_x, false));
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            if(maps[i][j] == 'S')
            {
                start_x = j;
                start_y = i;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }
    
    find_target('L', maps, is_visited1, 0, start_x, start_y);
    
    if(min_lever == 1e9)
    {
        return -1;
    }
    
    find_target('E', maps, is_visited2, 0, start_x, start_y);
    
    if(min_exit == 1e9)
    {
        return -1;
    }
    
    answer = min_lever + min_exit;
    
    return answer;
}