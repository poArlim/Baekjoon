#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> participantState;

    for(string name : participant){
        participantState.insert(make_pair(name, 0));
    }
    
    for(string name : participant){
        participantState[name]++;
    }

    for(string name : completion){
        participantState[name]--;
    }

    for(auto pair : participantState){
        if(pair.second > 0) answer = pair.first;
    }

    return answer;
}
