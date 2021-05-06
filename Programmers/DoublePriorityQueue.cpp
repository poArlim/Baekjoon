#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> incNumbers;
    priority_queue<int, vector<int>, less<int>> decNumbers;
    
    int count = 0;
    for (string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            incNumbers.push(num);
            decNumbers.push(num);
            count++;
        }
        else {
            count--;
            if (count == 0) {
                while (!incNumbers.empty()) incNumbers.pop();
                while (!decNumbers.empty()) decNumbers.pop();
            }
            else if (op[2] == '-') {
                if (!incNumbers.empty()) incNumbers.pop();
            }
            else {
                if (!decNumbers.empty()) decNumbers.pop();
            }
        }
    }
    
    if (incNumbers.top() > decNumbers.top() || incNumbers.empty() || decNumbers.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(decNumbers.top());
        answer.push_back(incNumbers.top());
    }
    
    return answer;
}