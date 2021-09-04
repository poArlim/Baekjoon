#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pair_t;  // pair<price, index>

struct compare{
    bool operator()(pair_t a, pair_t b){
        if(a.first != b.first) return a.first > b.first;
        else a.second > b.second;
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    priority_queue<pair_t, vector<pair_t>, compare> ordered_prices;

    for(int i = 0; i < prices.size(); i++){
        ordered_prices.push(make_pair(prices[i], i));
    }

    for(int i = 0; i < prices.size(); i++){
        
        while(ordered_prices.top().second < i) ordered_prices.pop();

        if(prices[i] <= ordered_prices.top().first) answer.push_back(prices.size() - 1 - i);
        else {
            for(int j = i + 1; j < prices.size(); j++){
                if(prices[j] < prices[i]){
                    answer.push_back(j - i);
                    break;
                }
            }
        }
    }

    return answer;
}