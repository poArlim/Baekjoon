#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int visited[50];
const int MAX = 999999;

int route(int index, string cur, string target, vector<string> &words){
    if(cur == target) return 0;
    if(index >= 0) visited[index] = 1;
    int result = MAX;
    for(int i = 0; i < words.size(); i++){
        if(visited[i] == 0){
            int diffCount = 0;
            for(int j = 0; j < target.size(); j++){
                if(words[i][j] != cur[j]) diffCount++; 
            }
            if(diffCount == 1) result = min(route(i, words[i], target, words) + 1, result);
        }
    }
    if(index >= 0) visited[index] = 0;
    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = route(-1, begin, target, words);
    if(answer >= 999999) answer = 0;
    return answer;
}