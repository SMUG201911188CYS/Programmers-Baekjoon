#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

enum line
{
    INLINE = -1,
    NONE,
    OUTLINE
};

struct CharacterPos
{
    int x;
    int y;
    int move_cnt;

    CharacterPos(int X, int Y, int MOVE_CNT) : x(X), y(Y), move_cnt(MOVE_CNT) {}
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 999999;
    
    vector<vector<int>> world(101, vector<int>(101, NONE));
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    for(auto x : rectangle)
    {
        int x1 = x[0] * 2;
        int y1 = x[1] * 2;
        int x2 = x[2] * 2;
        int y2 = x[3] * 2;
        
        for(int i = y1; i <= y2; i++)
        {
            for(int j = x1; j <= x2; j++)
            {
                if(i == y1 || i == y2 || j == x1 || j == x2)
                {
                    if(world[i][j] != INLINE)
                    {
                        world[i][j] = OUTLINE;
                    }
                }
                else
                {
                    world[i][j] = INLINE;
                }
            }
        }
    }
    
    queue<CharacterPos> q;
    vector<vector<bool>> is_visit(101, vector<bool>(101, false));
    
    q.emplace(characterX, characterY, 0);

    int next_x[4] = {0, 1, -1, 0};
    int next_y[4] = {1, 0, 0, -1};
    
    while(!q.empty())
    {
        const int x = q.front().x;
        const int y = q.front().y;
        const int move_cnt = q.front().move_cnt;
        
        q.pop();
        
        if(world[y][x] != OUTLINE || is_visit[y][x])
            continue;

        if(x == itemX && y == itemY)
        {
            if (move_cnt < answer)
                answer = move_cnt;
            
            continue;
        }

        is_visit[y][x] = true;
        
        for(int i = 0; i < 4; i++)
        {
            if(y + next_y[i] > 100 || y + next_y[i] < 0 || x + next_x[i] > 100 || x + next_x[i] < 0)
                continue;
            if(is_visit[y + next_y[i]][x + next_x[i]])
                continue;

            q.emplace(x + next_x[i], y + next_y[i], move_cnt + 1);
        }
        
    }
    
    return answer / 2;
}