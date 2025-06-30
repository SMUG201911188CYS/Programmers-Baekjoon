#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    bool Flag = false;

    for(int k = 0; k < 5; ++k)
    {
        for(int y = 0; y < 5; ++y)
        {
            for(int x = 0; x < 5; ++x)
            {
                if(places[k][y][x] == 'P')
                {   
                    if(y + 1 < 5 && places[k][y + 1][x] == 'P')
                    {
                        // 바로 아래 있다면
                        Flag = true;
                        //cout << "Case 1" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                    else if(x + 1 < 5 && places[k][y][x + 1] == 'P')
                    {
                         // 바로 오른쪽에 있다면
                        Flag = true;
                        //cout << "Case 2" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                    else if(y + 2 < 5 && places[k][y + 2][x] == 'P' && places[k][y + 1][x] != 'X')
                    {
                        // 2칸 아래에 있고, 사이 칸이 없다면
                        Flag = true;
                        //cout << "Case 3" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                    else if(x + 2 < 5 && places[k][y][x + 2] == 'P' && places[k][y][x + 1] != 'X')
                    {
                        // 2칸 오른쪽에 있고, 사이 칸이 없다면
                        Flag = true;
                        //cout << "Case 4" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                    else if(x + 1 < 5 && y + 1 < 5 && places[k][y + 1][x + 1] == 'P' && (places[k][y + 1][x] != 'X' || places[k][y][x + 1] != 'X'))
                    {
                        //대각선 아래에 있고, 아래 + 오른쪽이 칸이 없다면
                        Flag = true;
                        //cout << "Case 5" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                    else if(x + 1 < 5 && y - 1 > -1 && places[k][y - 1][x + 1] == 'P' && (places[k][y - 1][x] != 'X' || places[k][y][x + 1] != 'X'))
                    {
                        //대각선 위에 있고, 위 + 오른쪽이 칸이 없다면
                        Flag = true;
                        //cout << "Case 6" << '\n';
                        //cout << "Point : " << y << ", " << x << '\n';
                        break;
                    }
                }
            }
        }
        if(Flag)
        {
            answer.push_back(0);
            Flag = false;
        }
        else
        {
            answer.push_back(1);
        }
    }
    
    return answer;
}