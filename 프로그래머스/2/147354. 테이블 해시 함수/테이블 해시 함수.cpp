#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int Standard;

bool Compare(vector<int> & v1, vector<int> & v2)
{
    if(v1[Standard] < v2[Standard])
    {
        return true;
    }
    else if(v1[Standard] == v2[Standard])
    {
        return v1[0] > v2[0] ? true : false;
    }
    
    return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    int Count = 0;
    vector<int> Result(row_end - row_begin + 1, 0);
    
    Standard = col - 1;
    
    sort(data.begin(), data.end(), Compare);
    
    for(int i = row_begin - 1; i <= row_end - 1; ++i, ++Count)
    {
        for(int j = 0; j < data[0].size(); ++j)
        {
            Result[Count] += data[i][j] % (i + 1);
        }
    }

    answer += Result[0];
    
    for(int i = 1; i < Result.size(); i++)
    {
        answer = answer ^ Result[i];
    }
    
    return answer;
}