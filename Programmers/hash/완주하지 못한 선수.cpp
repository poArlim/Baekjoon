#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> participantState;

    for(string name : participant){
        participantState.insert(make_pair(name, 1));
    }

    for(string name : participant){
        participantState[name] = 0;
    }

    for(auto pair : participantState){
        if(pair.second == 1) answer = pair.first; 
    }

    return answer;
}