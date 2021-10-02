#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, int> earning;
    unordered_map<string, string> enroll_referral_map;
    
    for(int i = 0; i < enroll.size(); i++){
        earning[enroll[i]] = 0;
        enroll_referral_map[enroll[i]] = referral[i];
    }
    
    for(int i = 0; i < seller.size(); i++){
        string cur_enroll = seller[i];
        string cur_referral = enroll_referral_map[cur_enroll];
        int total_earning = amount[i] * 100;
        
        while(cur_enroll != "-"){
            int earn = total_earning * 0.9;
            if(total_earning % 10 != 0) earn += 1;
            int tax = total_earning - earn;
            
            earning[cur_enroll] += earn;
            cur_enroll = enroll_referral_map[cur_enroll];
            cur_referral = enroll_referral_map[cur_enroll];
            total_earning = tax;
            
            if(tax <= 0) break;
        }
    }
    
    for(int i = 0; i < enroll.size(); i++){
        answer.push_back(earning[enroll[i]]);
    }
    
    return answer;
}