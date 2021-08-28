#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> combination;

    for(vector<string> kinds : clothes){
        combination.insert(make_pair(kinds[1], 0));
    }

    for(vector<string> kinds : clothes){
        combination[kinds[1]]++;
    }

    answer = 1;
    for(pair<string, int> kinds : combination){
        // 해당 종류의 옷을 선택하지 않는 경우 한 가지를 추가해서 모두 곱하면 알아서 다 처리된다.
        answer *= kinds.second + 1;
    }

    // 최소 한 개의 옷은 입어야 하므로 -1 해준다.
    return answer - 1;
}