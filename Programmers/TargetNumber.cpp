#include <string>
#include <vector>

using namespace std;
int targetNum;
int answer = 0;

void searchNum(vector<int> numbers, int total, int idx) {
    if (idx == numbers.size()) {
        if (total == targetNum) answer++;
        return;
    }
    searchNum(numbers, total + numbers[idx], idx + 1);
    searchNum(numbers, total - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    targetNum = target;
    
    searchNum(numbers, 0, 0);
    
    return answer;
}