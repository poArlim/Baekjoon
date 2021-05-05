#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

long long calculate(vector<long long> numbers, vector<char> operators, char first, char second, char third) {
    for (long long i = 0; i < operators.size(); i++) {
        if (operators[i] == first) {
            if (first == '+') numbers[i] = numbers[i] + numbers[i+1];
            else if (first == '-') numbers[i] = numbers[i] - numbers[i+1];
            else numbers[i] = numbers[i] * numbers[i+1];
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }
    for (long long i = 0; i < operators.size(); i++) {
        if (operators[i] == second) {
            if (second == '+') numbers[i] = numbers[i] + numbers[i+1];
            else if (second == '-') numbers[i] = numbers[i] - numbers[i+1];
            else numbers[i] = numbers[i] * numbers[i+1];
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }
    for (long long i = 0; i < operators.size(); i++) {
        if (operators[i] == third) {
            if (third == '+') numbers[i] = numbers[i] + numbers[i+1];
            else if (third == '-') numbers[i] = numbers[i] - numbers[i+1];
            else numbers[i] = numbers[i] * numbers[i+1];
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }
    return numbers[0];
}

long long solution(string expression) {
    vector<long long> numbers;
    vector<char> operators;
    
    long long answer = 0;
    string number = "";
    
    long long i = 0;
    while (i < expression.size ()) {
        if (isdigit(expression[i])) {
            number += expression[i];
        }
        else {
            numbers.push_back(stoi(number));
            number = "";
            operators.push_back(expression[i]);
        }
        i++;
    }
    numbers.push_back(stoll(number));
    
    long long a, b, c, d, e, f;
    a = abs(calculate(numbers, operators, '+', '-', '*'));
    b = abs(calculate(numbers, operators, '+', '*', '-'));
    c = abs(calculate(numbers, operators, '-', '+', '*'));
    d = abs(calculate(numbers, operators, '-', '*', '+'));
    e = abs(calculate(numbers, operators, '*', '+', '-'));
    f = abs(calculate(numbers, operators, '*', '-', '+'));
    
    answer = max({a, b, c, d, e, f});
        
        
    return answer;
}