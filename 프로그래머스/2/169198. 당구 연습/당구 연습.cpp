#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    int BallX = 0;
    int BallY = 0;
    
    double Height = 0;
    double Width = 0;
    
    for(const vector<int> Ball : balls)
    {
        BallX = Ball[0];
        BallY = Ball[1];
        
        int StartLength = 0;
        int TargetLength = 0;
        int Result = 1e9;
        
        
        if(startY != BallY || startX < BallX)
        {
            StartLength = ((-1 * BallX) - startX) * ((-1 * BallX) - startX);
            TargetLength = (BallY - startY) * (BallY - startY);
            Result = min(Result, StartLength+TargetLength);
        }
        
        if(startY != BallY || startX > BallX)
        {
            StartLength = ((-1 * (m - BallX)) - (m - startX)) * ((-1 * (m - BallX)) - (m - startX));
            TargetLength = (BallY - startY) * (BallY - startY);
            Result = min(Result, StartLength+TargetLength);
        }
        
        if(startX != BallX || startY < BallY)
        {
            StartLength = (BallX - startX) * (BallX - startX);
            TargetLength = ((-1 * BallY) - startY) * ((-1 * BallY) - startY);
            Result = min(Result, StartLength+TargetLength);
        }
        
        if(startX != BallX || startY > BallY)
        {
            StartLength = (BallX - startX) * (BallX - startX);
            TargetLength = ((-1 * (n - BallY)) - (n - startY)) * ((-1 * (n - BallY)) - (n - startY));
            Result = min(Result, StartLength+TargetLength);
        }

        answer.push_back(Result);
    }
    return answer;
}