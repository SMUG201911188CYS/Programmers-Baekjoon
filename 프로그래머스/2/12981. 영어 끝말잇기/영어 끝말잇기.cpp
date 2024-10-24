#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};

    int order = 1;
    int cnt = 1;
    char last_word;
    set<string> used_word;
    

    // start

    used_word.insert(words[0]);
    last_word = words[0][words[0].length() - 1];
    order++;
    
    for(int i = 1; i < words.size(); i++)
    {
        if(used_word.find(words[i]) != used_word.end())
        {
            //cout << "is already used. order : " << order << ", cnt : " << cnt << '\n';
            answer[0] = order;
            answer[1] = cnt;
            break;
        }
        else if(last_word != words[i][0])
        {
            //cout << "discrepancy word. order : " << order << ", cnt : " << cnt << '\n';
            answer[0] = order;
            answer[1] = cnt;
            break;
        }
        else
        {
            used_word.insert(words[i]);
            last_word = words[i][words[i].length() - 1];
        }

        if(order < n)
        {
            order++;
        }
        else
        {
            order = 1;
            cnt++;
        }
    }
    
    return answer;
}