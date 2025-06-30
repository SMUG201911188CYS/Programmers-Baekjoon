#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    map<pair<int, int>, map<pair<int, int>, bool>> M;
    
    pair<int, int> Pos = make_pair(0, 0);
    pair<int, int> MoveDir = make_pair(0, 0);
    
    for(int i = 0; i < dirs.length(); ++i)
    {
        if(dirs[i] == 'U')
        {            
            MoveDir = make_pair(0, 1);
        }
        else if(dirs[i] == 'L')
        {
            MoveDir = make_pair(-1, 0);
        }
        else if(dirs[i] == 'R')
        {
            MoveDir = make_pair(1, 0);
        }
        else
        {
            MoveDir = make_pair(0, -1);
        }

        if(Pos.first + MoveDir.first < -5 || Pos.first + MoveDir.first > 5 || Pos.second + MoveDir.second < -5 || Pos.second + MoveDir.second > 5)
        {
            continue;
        }
        
        pair<int, int> NextPos = make_pair(Pos.first + MoveDir.first, Pos.second + MoveDir.second);
        
        if(!M[Pos][NextPos])
        {
            answer += 1;
            M[Pos][NextPos] = true;
            M[NextPos][Pos] = true;
        }
        
        Pos = NextPos;
    }
    
    return answer;
}