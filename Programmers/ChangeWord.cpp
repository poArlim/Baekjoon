#include <string>
#include <vector>
#include <queue>

using namespace std;

int route (string prevWord, string curWord, string target, int count, vector<string> &words) {
    if (curWord == target) return count;
    else if (count == words.size()) return 0;
    
    int result = 10000;
    for (string s : words) {
        if (s == prevWord || s == curWord) continue;
        int diff = 0;
        for (int i = 0; i < s.length(); i++){
            if (curWord[i] != s[i]) diff++;
        }
        if (diff == 1) {
            int temp = route (curWord, s, target, count + 1, words);
            if (temp == 0) continue;
            else result = min(result, temp);
        } 
    }
    if (result == 10000) result = 0;
    return result;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = route ("", begin, target, 0, words);
    
    return answer;
}