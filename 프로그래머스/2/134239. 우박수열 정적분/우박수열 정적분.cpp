#include <string>
#include <vector>
#include <iostream>

using namespace std;

void collatz_cal(int k, vector<double> & y_pos)
{
    y_pos.push_back(k);
    
    if(k == 1)
        return;
    
    if(k % 2 == 0)
        collatz_cal(k / 2, y_pos);
    else
        collatz_cal(k * 3 + 1, y_pos);
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> y_pos;
    vector<double> areas;
    
    collatz_cal(k, y_pos);
    
    int n = y_pos.size() - 1;
    
    for(int i = 1; i <= n; i++)
    {
        double area = (y_pos[i] + y_pos[i-1]) * 1 / 2;
        areas.push_back(area);
    }
    
    for(auto x : ranges)
    {
        int a = x[0];
        int b = x[1];
        
        double sum_area = 0;
        
        if(a == 0 && b == 0)
        {
            for(auto x : areas)
                sum_area += x;
            answer.push_back(sum_area);
            
            continue;
        }
        
        b += n;
        
        if(b < a)
            sum_area = -1;
        else if(b == a)
            sum_area = 0;
        else
        {
            for(int i = a; i < b; i++)
            {
                sum_area += areas[i];
            }
        }
        
        answer.push_back(sum_area);
    }
    
    return answer;
}