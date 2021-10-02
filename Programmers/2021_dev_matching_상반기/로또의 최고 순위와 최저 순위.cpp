#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero_num = 0;
    int match_num = 0;
    for(auto lotto : lottos){
        if(lotto == 0){
            zero_num++;
            continue;
        }
        for(auto num : win_nums){
            if(lotto == num) match_num++;
        }
    }
    
    if(match_num + zero_num >= 6) answer.push_back(1);
    else if(match_num + zero_num == 0) answer.push_back(6);
    else answer.push_back(7 - match_num - zero_num);
    
    if(match_num == 0) answer.push_back(6);
    else answer.push_back(7 - match_num);
    
    return answer;
}