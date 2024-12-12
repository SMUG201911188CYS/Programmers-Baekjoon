#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Pair
{
    int Cost;
    pair<int, int> PairCard;
    
    Pair(int C, pair<int, int> P) : Cost(C), PairCard(P) {}
    
    bool operator<(const Pair Temp) const
    {
        return this->Cost > Temp.Cost;
    }
};

int solution(int coin, vector<int> cards) {
    int answer = 1;
    int N = cards.size();
    int Index = 0;
    
    unordered_map<int, bool> Hand;
    unordered_map<int, int> CardCost;
    priority_queue<Pair> PQ;
    
    for(Index = 0; Index < N / 3; ++Index)
    {
        Hand[cards[Index]] = true;
        
        if(Hand[N + 1 - cards[Index]])
        {
            Pair Temp(0, make_pair(cards[Index], N + 1 - cards[Index]));
            PQ.push(Temp);
        }
    }
    
    for( ; Index < N; ++Index)
    {   
        Hand[cards[Index]] = true;
        CardCost[cards[Index]] += 1;
        
        if(Hand[N + 1 - cards[Index]])
        {
            Pair Temp(CardCost[cards[Index]] + CardCost[N + 1 - cards[Index]], make_pair(cards[Index], N + 1 - cards[Index]));
            PQ.push(Temp);
        }
        
        if(Index % 2 == 1)
        {
            //cout << "Card Throw." << '\n';
            
            if(!PQ.empty())
            {
                Pair Temp = PQ.top();
                PQ.pop();
                
                if(Temp.Cost > coin)
                {
                    //cout << "Not Enough Coin." << '\n';
                    break;
                }
                //cout << "Use Coin : " << Temp.Cost << ", Pair Index : " << Temp.PairCard.first << ", " << Temp.PairCard.second << '\n';
                coin -= Temp.Cost;
                //cout << "Current Coin : " << coin << '\n';
                answer += 1;
            }
            else
            {
                //cout << "Cant Throw Card." << '\n';
                break;
            }
        }
    }
    
    return answer;
}