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

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int end = -30001;
    int next_start = 0;
    
    for(const auto x : routes)
    {
        next_start = x[0];
        if(next_start > end)
        {
            answer++;
            end = x[1];
        }
    }
    
    return answer;
}