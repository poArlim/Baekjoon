#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> numbers;
    
    for(string operation : operations) {
        char op = operation[0];
        int number = stoi(operation.substr(2));
        if(op == 'I') numbers.insert(number);
        else if(numbers.size() == 0) continue;
        else if(number < 0) numbers.erase(numbers.begin());
        else numbers.erase(--numbers.end());
    }

    if(numbers.size() <= 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--numbers.end()));
        answer.push_back(*numbers.begin());
    }
    
    return answer;
}