#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool FindBingo(const char & temp, const vector<string> & board)
{
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(temp == board[i][j])
            {
                cnt1 += 1;
            }
            
            if(temp == board[j][i])
            {
                cnt2 += 1;
            }
        }
        
        if(cnt1 == 3 || cnt2 == 3)
        {
            return true;
        }
        else
        {
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    
    for(int i = 0; i < 3; ++i)
    {
        if(board[i][i] == temp)
        {
            cnt1 += 1;
        }
        if(board[i][2 - i] == temp)
        {
            cnt2 += 1;
        }
    }
    
    if(cnt1 == 3 || cnt2 == 3)
    {
        return true;
    }

    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    
    vector<pair<int, int>> White;
    vector<pair<int, int>> Black;
    
    int WhiteCnt = 0;
    int BlackCnt = 0;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O')
            {
                White.emplace_back(i, j);
                WhiteCnt += 1;
            }
            else if(board[i][j] == 'X')
            {
                Black.emplace_back(i, j);
                BlackCnt += 1;
            }
        }
    }
    
    bool IsBingo;
    
    if((WhiteCnt + BlackCnt) % 2 == 0) 
    {
        if(WhiteCnt != BlackCnt)
        {
            answer = 0;
            return answer;
        }
        
        IsBingo = FindBingo('O', board);
        
        if(IsBingo)
        {
            if(WhiteCnt != BlackCnt + 1)
            {
                answer = 0;
                return answer;
            }
        }
    }
    else
    {
        if(WhiteCnt != BlackCnt + 1)
        {
            answer = 0;
            return answer;
        }
        
        IsBingo = FindBingo('X', board);
        
        if(IsBingo)
        {
            if(WhiteCnt + 1 != BlackCnt)
            {
                answer = 0;
                return answer;
            }
        }
    }
    
    if(FindBingo('X', board) && FindBingo('O', board))
    {
        answer = 0;
        return answer;
    }
    
    return answer;
}