#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int Size = triangle.size();
    
    for(int i = Size - 1; i > 0; i--)
    {
        for(int j = 0; j < triangle[i].size() - 1; j++)
        {
            triangle[i - 1][j] = max(triangle[i - 1][j] + triangle[i][j], triangle[i - 1][j] + triangle[i][j + 1]);
        }
    }
    
    return triangle[0][0];
}