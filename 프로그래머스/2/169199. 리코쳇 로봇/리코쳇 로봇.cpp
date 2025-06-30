#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int answer;
int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

vector<string> _board;
int x_size;
int y_size;

struct Pos
{
    int x;
    int y;
    int cnt;
    
    Pos(int X, int Y, int CNT) : x(X), y(Y), cnt(CNT) {}
};

void FindStart(int x, int y)
{
    vector<vector<bool>> IsVisited(x_size, vector<bool>(y_size, false));
    int cnt = 0;
    
    queue<Pos> q;
    
    q.emplace(x, y, 0);
    
    int CurrentX = 0;
    int CurrentY = 0;
    int CurrentCnt = 0;
    int NextX = 0;
    int NextY = 0;
    
    while(!q.empty())
    {
        CurrentX = q.front().x;
        CurrentY = q.front().y;
        CurrentCnt = q.front().cnt;
        
        q.pop();
        if(_board[CurrentX][CurrentY] == 'G')
        {
            answer = min(answer, CurrentCnt);
            continue;
        }
        else if(IsVisited[CurrentX][CurrentY])
        {
            continue;
        }
        
        IsVisited[CurrentX][CurrentY] = true;
        
        for(int i = 0; i < 4; i++)
        { 
            NextX = CurrentX + dir_x[i];
            NextY = CurrentY + dir_y[i];
            
            if(NextX < 0 || NextY < 0 || NextX >= x_size || NextY >= y_size)
            {
                continue;
            }
            else if(_board[NextX][NextY] == 'D')
            {
                continue;
            }
            
            while(true)
            {
                if(NextX + dir_x[i] < 0 || NextY + dir_y[i] < 0 || NextX + dir_x[i] >= x_size || NextY + dir_y[i] >= y_size || _board[NextX + dir_x[i]][NextY + dir_y[i]] == 'D')
                {
                    break;
                }
                
                NextX += dir_x[i];
                NextY += dir_y[i];
            }
            
            q.emplace(NextX, NextY, CurrentCnt + 1);
        }
    }
    
}

int solution(vector<string> board) {
    answer = 1e9;
    
    _board = board;
    x_size = board.size();
    y_size = board[0].size();

    
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == 'R')
            {
                FindStart(i, j);
                break;
            }
        }
    }
    
    if(answer == 1e9)
    {
        answer = -1;
    }
    
    return answer;
}