#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> answer;

void set_answer(int before, int after)
{
    vector<int> temp = {before, after};
    answer.emplace_back(temp);
}

void hanoi(int n, int start = 1, int end = 3, int via = 2, int cnt = 0)
{
    if(n == 1)
    {
        set_answer(start, end);
        return;
    }
    
    hanoi(n - 1, start, via, end, cnt + 1);
    
    set_answer(start, end);
    
    hanoi(n - 1, via, end, start, cnt + 1);

}


vector<vector<int>> solution(int n) {

    hanoi(n, 1, 3, 2);
    
    return answer;
}