#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Node
{
    int CurrentIndex;
    int Count;
    
    Node(int CI, int C) : CurrentIndex(CI), Count(C) {}
};

bool Cmp(Node& A, Node& B)
{
    if(A.Count <= B.Count)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solution(vector<int> stones, int k) {
    int answer = -1;
    int Size = stones.size();
    int CurrentPos = Size + 1;
    
    map<int, pair<int, int>> M;
    vector<Node> List(Size, Node(0, 0));

    for(int Idx = 0; Idx < Size + 2; ++Idx)
    {
        M[Idx].first = Idx - 1;
        M[Idx].second = Idx + 1;
    }
    
    for(int Idx = 0; Idx < Size ; ++Idx)
    {
        List[Idx].CurrentIndex = Idx + 1;
        List[Idx].Count = stones[Idx];
    }
    
    sort(List.begin(), List.end(), Cmp);
    
    for(int i = 0; i < Size; ++i)
    {
        int CurrentIndex = List[i].CurrentIndex;
                
        //cout << "C : " << CurrentIndex << ", P : " << M[CurrentIndex].first << ", N : " << M[CurrentIndex].second << '\n';
        
        M[M[CurrentIndex].first].second = M[CurrentIndex].second;
        M[M[CurrentIndex].second].first = M[CurrentIndex].first;
        
        if(M[M[CurrentIndex].first].second - M[M[CurrentIndex].second].first > k)
        {
            //cout << "Over" << '\n';
            answer = List[i].Count;
            break;
        }
    }
    return answer;
}