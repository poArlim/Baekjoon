#include <string>
#include <vector>

using namespace std;

int search(vector<int> numbers, int index, int value, int target){
    if(index == numbers.size()){
        if(value == target) return 1;
        else return 0;
    }
    return search(numbers, index + 1, value + numbers[index], target) + search(numbers, index + 1, value - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = search(numbers, 0, 0, target);
    return answer;
}