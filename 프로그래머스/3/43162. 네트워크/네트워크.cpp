#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int parent[201];

int find_parent(int num)
{
    if(parent[num] == num)
        return num;
    else
        return find_parent(parent[num]);
}

void union_parent(int a, int b)
{
    int a_parent = find_parent(a);
    int b_parent = find_parent(b);
    
    if(a_parent > b_parent)
        parent[a_parent] = b_parent;
    else
        parent[b_parent] = a_parent;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> network;
    
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(computers[i][j] == 1)
            {
                union_parent(i + 1, j + 1);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        parent[i] = find_parent(i);
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << parent[i] << ", ";
        network.insert(parent[i]);
    }
    
    return network.size();
}