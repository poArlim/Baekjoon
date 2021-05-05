#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> gemList;
    
    for (string gem : gems) {
        gemList.insert(pair<string, int>(gem, 0));
    }
    
    int kinds = gemList.size();
    gemList.clear();
    
    int start = 0;
    int end = 100000;
    int head = 0;
    int tail = 0;
    int flag = 0;
    while (tail < gems.size () && head < gems.size ()) {
        if (flag == 0) {
            if (gemList.find(gems[tail]) == gemList.end()) {
                gemList.insert(pair<string, int>(gems[tail], 1));
            }
            else {
                gemList[gems[tail]] += 1;
            }
        }

        if (gemList.size() == kinds) {
            flag = 1;
            if ((tail - head) < (end - start)) {
                start = head;
                end = tail;
            }
            if (gemList[gems[head]] == 1) gemList.erase(gems[head]);
            else gemList[gems[head]] -= 1;
            head ++;
        }
        else {
            flag = 0;
            tail++;
        }
    }
    
    answer.push_back(start+1);
    answer.push_back(end+1);
    
    return answer;
}