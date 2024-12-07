#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int Size = elements.size();
    set<int> List;
    vector<vector<int>> DP(Size, vector<int>(Size, 0));
    
    for(int i = 0; i < Size; i++)
    {
        DP[0][i] = elements[i];
        List.insert(DP[0][i]);
    }
    
    for(int i = 1; i < Size; ++i)
    {
        for(int j = 0, k = i; j < Size; ++j, k = (k == Size - 1) ? 0 : ++k)
        {
            DP[i][j] = DP[i-1][j] + DP[0][k];
            List.insert(DP[i][j]);
        }
        cout << '\n';
    }
    
    return List.size();
}