#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer;


void PrintBoard(vector<string>& Board)
{
    cout << '\n';
    
    for(const auto& Y : Board)
    {
        for(const auto& X : Y)
        {
            cout << X;
        }
        cout << '\n';
    }
    cout << '\n';
}

void UpdateBoard(vector<string>& Board, vector<vector<bool>>& IsDeleted, int SizeX, int SizeY)
{
    for(int CurrentY = SizeY - 1; CurrentY >= 0; --CurrentY)
    {
        for(int CurrentX = 0; CurrentX < SizeX; ++CurrentX)
        {
            if(IsDeleted[CurrentY][CurrentX])
            {
                int NextPosY = CurrentY - 1;
                
                while(true)
                {
                    if(NextPosY < 0)
                    {
                        break;
                    }
                    else if(!IsDeleted[NextPosY][CurrentX])
                    {
                        Board[CurrentY][CurrentX] = Board[NextPosY][CurrentX];
                        IsDeleted[NextPosY][CurrentX] = true;
                        IsDeleted[CurrentY][CurrentX] = false;
                        Board[NextPosY][CurrentX] = 'X';
                        
                        break;
                    }
                    
                    Board[NextPosY][CurrentX] = 'X';
                    NextPosY -= 1;
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    
    bool IsEnd = true;
    
    int SizeX = board[0].size();
    int SizeY = board.size();
    
    vector<vector<bool>> IsDeleted(SizeY, vector<bool>(SizeX, false));
    vector<vector<bool>> IsCounted(SizeX, vector<bool>(SizeX, false));
    
    //PrintBoard(board);
    
    while(true)
    {
        for(int CurrentY = 0; CurrentY < SizeY - 1; ++CurrentY)
        {
            for(int CurrentX = 0; CurrentX < SizeX - 1; ++CurrentX)
            {
                char CurrentType = board[CurrentY][CurrentX];

                if(CurrentType == 'X')
                {
                    continue;
                }

                if(board[CurrentY + 1][CurrentX + 1] == CurrentType &&
                   board[CurrentY + 1][CurrentX] == CurrentType &&
                   board[CurrentY][CurrentX + 1] == CurrentType)
                {
                    IsEnd = false;

                    //cout << "Correct : " << CurrentY << ", " << CurrentX << '\n';
                    if(!IsDeleted[CurrentY + 1][CurrentX + 1])
                    {
                        answer += 1;
                        IsDeleted[CurrentY + 1][CurrentX + 1] = true;
                    }
                    if(!IsDeleted[CurrentY + 1][CurrentX])
                    {
                        answer += 1;
                        IsDeleted[CurrentY + 1][CurrentX] = true;
                    }
                    if(!IsDeleted[CurrentY][CurrentX + 1])
                    {
                        answer += 1;
                        IsDeleted[CurrentY][CurrentX + 1] = true;
                    }
                    if(!IsDeleted[CurrentY][CurrentX])
                    {
                        answer += 1;
                        IsDeleted[CurrentY][CurrentX] = true;
                    }
                }
            }
        }
        if(IsEnd)
        {
            break;
        }
        else
        {
            IsEnd = true;
            UpdateBoard(board, IsDeleted, SizeX, SizeY);
            //PrintBoard(board);
        }
    }
    
    return answer;
}