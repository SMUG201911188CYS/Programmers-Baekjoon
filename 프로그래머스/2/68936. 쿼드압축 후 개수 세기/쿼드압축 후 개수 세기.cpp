#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    unordered_map<int, int> UM;
    int Size = arr.size();
    int N = 0;
    
    vector<vector<vector<int>>> DP;
    
    DP.push_back(arr);
    
    if(Size == 1)
    {
        UM[arr[0][0]] += 1;
        answer.push_back(UM[0]);
        answer.push_back(UM[1]);
    
        return answer;
    }
    
    while(Size != 0)
    {
        Size /= 2;
        N++;
    }

    for(int k = 1; k <= N; ++k)
    {
        if(k == N)
        {
            UM[DP[k-1][0][0]] += 1;
            continue;
        }
        vector<vector<int>> Temp1;
        for(int i = 0; i < DP[k-1].size(); i += 2)
        {
            vector<int> Temp2;
            for(int j = 0; j < DP[k-1].size(); j += 2)
            {      
                int Check = DP[k-1][i][j] + DP[k-1][i][j+1] + DP[k-1][i+1][j] + DP[k-1][i+1][j+1];
                if(Check == 4 || Check == 0)
                {
                    Temp2.push_back(DP[k-1][i][j]);
                }
                else
                {
                    UM[DP[k-1][i][j]] += 1;
                    UM[DP[k-1][i][j+1]] += 1;
                    UM[DP[k-1][i+1][j]] += 1;
                    UM[DP[k-1][i+1][j+1]] += 1;
                    Temp2.push_back(9);
                }
            }
            Temp1.push_back(Temp2);
        }
        DP.push_back(Temp1);
    }
    
    answer.push_back(UM[0]);
    answer.push_back(UM[1]);
    
    return answer;
}