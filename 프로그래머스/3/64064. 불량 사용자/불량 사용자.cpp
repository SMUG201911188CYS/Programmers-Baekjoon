#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int answer;
set<set<string>> answer_list;

void get_permutation(int cnt, int n, vector<vector<string>> correct_id, unordered_map<string, bool> & used_id, set<string> banned_id_set = {})
{
    if(cnt == n)
    {
        answer_list.insert(banned_id_set);
        return;
    }
    
    for(int j = 0; j < correct_id[cnt].size(); j++)
    {
        if(!used_id[correct_id[cnt][j]])
        {
            //cout << "current : " << correct_id[cnt][j] << ", " << "cnt : " << cnt << '\n';
            used_id[correct_id[cnt][j]] = true;
            banned_id_set.insert(correct_id[cnt][j]);
            get_permutation(cnt + 1, n, correct_id, used_id, banned_id_set);
            banned_id_set.erase(correct_id[cnt][j]);
            used_id[correct_id[cnt][j]] = false;
        }
    }
    
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {

    int user_id_size = user_id.size();
    int banned_id_size = banned_id.size();
    
    unordered_map<string, int> temp;
    vector<vector<string>> correct_id(banned_id_size);
    
    for(int i = 0; i < user_id_size; i++)
    {
        for(int j = 0; j < banned_id_size; j++)
        {
            if(user_id[i].length() != banned_id[j].length())
                continue;
            
            int cnt = 0;
            int length = banned_id[j].length();
                
            while(true)
            {
                if(cnt == length)
                    break;
                
                if(banned_id[j][cnt] == '*')
                    cnt++;
                else if(banned_id[j][cnt] == user_id[i][cnt])
                    cnt++;
                else
                    break;
            }
            
            if(cnt == length)
            {
                correct_id[j].push_back(user_id[i]);
                temp[user_id[i]] += 1;
            }
        }
    }
    
    unordered_map<string, bool> used_id;
    get_permutation(0, banned_id_size, correct_id, used_id);
    
    return answer_list.size();
}