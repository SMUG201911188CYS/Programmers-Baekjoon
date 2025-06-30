#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int, int> Piece1;
    unordered_map<int, int> Piece2;
    
    for(const auto& x : topping)
    {
        Piece1[x] += 1;
    }
    
    for(const auto & x : topping)
    {
        Piece1[x] -= 1;
        Piece2[x] += 1;
        
        if(Piece1[x] == 0)
        {
            Piece1.erase(x);
        }
        
        if(Piece1.size() < Piece2.size())
        {
            break;
        }
        else if(Piece1.size() == Piece2.size())
        {
            answer += 1;
        }
        //cout << Piece1.size() << ", " << Piece2.size() << '\n';
    }
    return answer;
}