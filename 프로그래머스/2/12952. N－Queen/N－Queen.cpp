#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ListX[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int ListY[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int answer;

void UpdateVec(vector<vector<bool>>& IsCanPutQueen, int PosX, int PosY, int UpdateX, int UpdateY, int n)
{
    while(true)
    {
        if(PosX < 0 || PosX >= n || PosY < 0 || PosY >= n)
        {
            break;
        }
        IsCanPutQueen[PosX][PosY] = false;
        PosX += UpdateX;
        PosY += UpdateY;
    }
}

void PutQueen(int n, vector<vector<bool>>& IsCanPutQueen, int Depth)
{
    if(n == Depth)
    {
        //cout << "Can Make Board" << '\n';
        answer += 1;
        return;
    }
    
    for(int Index = 0; Index < n; ++Index)
    {
        if(IsCanPutQueen[Index][Depth])
        {
            //cout << "Put Queen : " << Index << ", " << Depth << '\n';
            
            vector<vector<bool>> TempVec = IsCanPutQueen;
            
            for(int k = 0; k < 8; ++k)
            {
                UpdateVec(TempVec, Index, Depth, ListX[k], ListY[k], n);
            }
            
            PutQueen(n, TempVec, Depth + 1);
        }
    }
    
}

int solution(int n) {
    
    for(int Index = 0; Index < n; ++Index)
    {
        vector<vector<bool>> IsCanPutQueen(n, vector<bool>(n, true));
        
        for(int k = 0; k < 8; ++k)
        {
            UpdateVec(IsCanPutQueen, Index, 0, ListX[k], ListY[k], n);
        }
        
        PutQueen(n, IsCanPutQueen, 1);
    }
    return answer;
}