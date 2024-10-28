#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if(a[1] != b[1])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

struct node
{
    int x;
    int index;
    int left_node;
    int right_node;
};

unordered_map<int, node> tree;

void add_node(int current, int insert_vertex)
{
    //cout << "current vertex : " << current << '\n';
    
    if(tree[insert_vertex].x < tree[current].x)
    {
        //cout << "left" << '\n';
        
        if(tree[current].left_node == 0)
        {
            //cout << "insert :" << insert_vertex << " to " << current << '\n'; 
            tree[current].left_node = insert_vertex;
        }
        else
        {
            add_node(tree[current].left_node, insert_vertex);
        }
    }
    else
    {
        //cout << "right" << '\n';
        
        if(tree[current].right_node == 0)
        {
            //cout << "insert :" << insert_vertex << " to " << tree_vertex_info[current].index << '\n'; 
            tree[current].right_node = insert_vertex;
        }
        else
        {
            add_node(tree[current].right_node, insert_vertex);
        }
    }
}

void preorder(int index, vector<vector<int>> & answer) {
	
    //cout << tree_vertex_info[index].index << " ";
    answer[0].push_back(tree[index].index);
    
	if (tree[index].left_node != 0) {
		preorder(tree[index].left_node, answer);
	}
    
	if (tree[index].right_node != 0) {
		preorder(tree[index].right_node, answer);
	}
}

void postorder(int index, vector<vector<int>> & answer) {   
    
	if (tree[index].left_node != 0) {
		postorder(tree[index].left_node, answer);
	}
    
	if (tree[index].right_node != 0) {
		postorder(tree[index].right_node, answer);
    }
    
    answer[1].push_back(tree[index].index);
    //cout << tree_vertex_info[index].index << " ";
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    
    int start_vertex = 0;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        nodeinfo[i].push_back(i + 1);
        tree[nodeinfo[i][2]].x = nodeinfo[i][0];
        tree[nodeinfo[i][2]].index = nodeinfo[i][2];
        tree[nodeinfo[i][2]].left_node = 0;
        tree[nodeinfo[i][2]].right_node = 0;  
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    start_vertex = nodeinfo[0][2];
    
    /*for(int i = 0; i < nodeinfo.size(); i++)
    {
        cout << "x : " << nodeinfo[i][0] << ", " << "y : " << nodeinfo[i][1] << ", " << "index : " << nodeinfo[i][2] << '\n';
    }
    cout << '\n';
    */
    
    for(int i = 1; i < nodeinfo.size(); i++)
    {
        //cout << "insert : " << nodeinfo[i][2] << '\n';
        
        add_node(start_vertex, nodeinfo[i][2]);
    }
    
    preorder(start_vertex, answer);
    postorder(start_vertex, answer);
    
    return answer;
}