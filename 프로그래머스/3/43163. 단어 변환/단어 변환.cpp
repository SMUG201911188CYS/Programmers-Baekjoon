#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int min_cnt;
int v_size;
int w_size;

vector<string> _words;
string _target;

void find_target(int cnt, string word, vector<bool> is_used)
{
    if(word == _target)
    {
        min_cnt = min(min_cnt, cnt);
        return;
    }

    if(cnt == v_size)
        return;
    
    string temp = word;

    for(int i= 0; i < v_size; i++)
    {
        if(is_used[i])
            continue;

        int n = 0;
        
        for(int j = 0; j < w_size; j++)
        {
            if(word[j] != _words[i][j] && !is_used[i])
                n++;
        }

        if(n == 1)
        {
            is_used[i] = true;
            find_target(cnt + 1, _words[i], is_used);
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    min_cnt = 999999;
    _words = words;
    _target = target;
    v_size = words.size();
    w_size = begin.length();

    vector<bool> is_used(v_size, false);
    
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    find_target(0, begin, is_used);
    
    return min_cnt;
}