#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    string str_a = to_string(a);
    string str_b = to_string(b);
    return str_a + str_b > str_b + str_a;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(int number : numbers) answer += to_string(number);
    if(answer[0] == '0') return "0";
    return answer;
}