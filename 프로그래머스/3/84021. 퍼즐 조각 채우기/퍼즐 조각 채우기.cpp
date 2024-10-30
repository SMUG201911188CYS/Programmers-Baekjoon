#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <iomanip>

using namespace std;

struct Pos // 위치
{
    int x;
    int y;
    
    Pos(int X, int Y) : x(X), y(Y) {}
};

string board; // 보드 빈공간
string puzzle; // 퍼즐

unordered_map<int, vector<Pos>> puzzle_pos; // 퍼즐의 위치
unordered_map<int, vector<Pos>> board_pos; // 보드의 위치

int board_size; // 크기

void bfs(vector<vector<int>> & v, int condition, vector<vector<bool>> & is_visited, int x, int y)
{
    int _x[4] = {-1, 1, 0, 0};
    int _y[4] = {0, 0, -1, 1};
    char _s[4] = {'u', 'd', 'l', 'r'};
    
    queue<pair<Pos, char>> q; // 퍼즐 queue
    queue<Pos> pos_q; // 퍼즐 위치 queue
    
    string s = "";
    
    q.emplace(Pos(x, y), 's');
    
    while(!q.empty())
    {
        int current_x = q.front().first.x;
        int current_y = q.front().first.y;
        char current_c = q.front().second;
        q.pop();
        
        if(current_x < 0 || current_x >= board_size) // 범위를 벗어났다면, continue;
            continue;
        if(current_y < 0 || current_y >= board_size) // 범위를 벗어났다면, continue;
            continue;
        if(v[current_x][current_y] != condition) // 조건과 다르다면, continue;
            continue;
        if(is_visited[current_x][current_y]) // 이미 방문했다면, continue;
            continue;
        
        is_visited[current_x][current_y] = true; // 방문 처리
        
        s += current_c; // 방향 char 저장
        
        pos_q.push(Pos(current_x, current_y)); // 위치 저장
        
        for(int i = 0; i < 4; i++)
        {
            int next_x = _x[i] + current_x;
            int next_y = _y[i] + current_y;
            char next_c = _s[i];
            
            q.emplace(Pos(next_x, next_y), next_c);
        }
    }
    
    if(condition == 1) // 퍼즐
    {
        while(!pos_q.empty()) // 퍼즐 위치 저장
        {
            Pos temp = pos_q.front();
            puzzle_pos[0].push_back(temp);
            pos_q.pop();
        }
        
        puzzle = s;
    }
    else // 보드
    {
        while(!pos_q.empty()) // 보드 위치 저장
        {
            Pos temp = pos_q.front();
            board_pos[0].push_back(temp);
            pos_q.pop();
        }
        board = s;
    }
}

void rotate_v(vector<vector<int>> & v) // 벡터 회전
{
    vector<vector<int>> temp(board_size, vector<int>(board_size, 0));
    
    for(int i = 0, k = board_size - 1; i < board_size; i++, k--)
    {
        for(int j = 0; j < board_size; j++)
        {
            temp[i][j] = v[(board_size - 1) - j][i];
        }
    }
    
    v = temp;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;
    
    board_size = table.size();

    
    for(int i = 0; i  < 4; i++)
    {
        vector<vector<bool>> board_visited(board_size, vector<bool>(board_size, false)); // game_board 방문 체크
    
        for(int board_i = 0; board_i < board_size; board_i++) // 보드 빈 공간 찾기 시작
        {
            for(int board_j = 0; board_j < board_size; board_j++)
            {
                if(game_board[board_i][board_j] == 0 && !board_visited[board_i][board_j]) // 빈 공간 이거나 방문하지 않았다면,
                {
                    board = "";
                    board_pos.clear();
                    
                    bfs(game_board, 0, board_visited, board_i, board_j); // 보드의 빈 공간 찾기
                
                    bool is_correct = false;
                
                    for(int n = 0; n <= 4; n++) // 맞는 퍼즐 찾기 시작, table 90도, 180도, 270도 회전
                    {
                        vector<vector<bool>> table_visited(board_size, vector<bool>(board_size, false));

                        for(int i = 0; i < board_size && !is_correct; i++)
                        {
                            for(int j = 0; j < board_size && !is_correct; j++)
                            {
                                if(table[i][j] == 1 && !table_visited[i][j])
                                {                                                                                                
                                    puzzle = ""; // 퍼즐 초기화
                                    puzzle_pos.clear(); // 퍼즐 위치 map 초기화
                                
                                    bfs(table, 1, table_visited, i, j); // 퍼즐 찾기
                                    
                                    if(board == puzzle) // 퍼즐과 빈 공간이 같다면
                                    {
                                        int distance_x = board_pos[0][0].x - puzzle_pos[0][0].x; // 빈 공간과 퍼즐의 x값 좌표 차이
                                        int distance_y = board_pos[0][0].y - puzzle_pos[0][0].y; // 빈 공간과 퍼즐의 y값 좌표 차이
                                        bool flag = true;

                                        for(int k = 0; k < puzzle_pos[0].size(); k++)
                                        {
                                            if(board_pos[0][k].x - puzzle_pos[0][k].x != distance_x || board_pos[0][k].y - puzzle_pos[0][k].y != distance_y)
                                            {
                                                flag = false; // 좌표 값의 차이가 다르다면, 이는 같은 모양이 아님
                                            }
                                        }

                                        if(flag) // 같은 모양이라면,
                                        {
                                            answer += puzzle.length();

                                            for(auto pos : puzzle_pos[0]) // 찾은 퍼즐 0으로 초기화
                                            {
                                                table[pos.x][pos.y] = 0;
                                            }

                                            is_correct = true; // 찾았다면 break;   
                                        }
                                    }
                                }
                            }
                        }
                        rotate_v(table); // 회전
                    }
                }
            }
        }
        return answer;
    }
}
