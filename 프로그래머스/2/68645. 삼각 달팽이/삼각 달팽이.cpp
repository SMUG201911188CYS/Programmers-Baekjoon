#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

void print_pramid(vector<vector<int>> pramid)
{
    for(auto x : pramid)
    {
        for(auto y : x)
            cout << setw(3) << y << " ";
        cout << '\n';
    }
}

void snail_move(int & x, int & y, int & num, int cnt, vector<vector<int>> & pramid, int direction)
{
    for(int i = 0; i < cnt; i++)
    {
        switch(direction)
        {
            case 0:
                y += 1;
                break;
            case 1:
                x += 1;
                break;
            case 2:
                x -= 1;
                y -= 1;
                break;
        }
        
        pramid[y][x] = num;
        num++;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> pramid(n, vector<int>(n, 0));
    
    int num = 1; // 숫자
    int cnt = n; // 가는 횟수
    int x = 0;
    int y = -1; // n -> n-1 -> n-2 -> ... -> 0까지 가도록

    //print_pramid(pramid);
    cout << '\n';
    
    for(int i = 0; cnt > 0; i++)
    {
        if(i > 2)
            i = 0;
        
        snail_move(x, y, num, cnt, pramid, i);
        cnt--;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            answer.push_back(pramid[i][j]);
        }
    }
    //print_pramid(pramid);
    
    return answer;
}