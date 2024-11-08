#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> & a, vector<int> & b)
{
    if(a[1] < b[1])
    {
        return true;
    }
    
    return false;
}

int solution(vector<vector<int>> targets) {
    
    int answer = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    int end = -1;
    
    for(int i = 0; i < targets.size(); i++)
    {
        if(end <= targets[i][0])
        {
            cout << targets[i][0] << ", " << targets[i][1] << '\n';
            answer++;
            end = targets[i][1];
        }
    }
    
    return answer;
}