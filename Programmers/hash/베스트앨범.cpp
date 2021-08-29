#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<int>> genresMap;
    unordered_map<string, int> genresCount;
    vector<pair<int, int>> uniq_count;

    for(int i = 0; i < genres.size(); i++){
        genresCount[genres[i]] += plays[i];
        uniq_count.push_back(make_pair(i, plays[i]));
    }

    // pair<장르, 장르 총 재생횟수> 를 장르 총 재생횟수의 내림차순으로 정렬
    vector<pair<string, int>> genresCountV(genresCount.begin(), genresCount.end());
	sort(genresCountV.begin(), genresCountV.end(), [](pair<string,int> a, pair<string,int> b){
        return a.second > b.second;
    });

    // pair<고유번호, 재생횟수> 를 재생횟수의 내림차순으로 정렬
	sort(uniq_count.begin(), uniq_count.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    });

    // 장르별로 재생횟수의 내림차순으로 노래 고유번호 삽입.
    for(int i = 0; i < uniq_count.size(); i++){
        genresMap[genres[uniq_count[i].first]].push_back(uniq_count[i].first);
    }

    // 결과출력
    for(int i = 0; i < genresCountV.size(); i++){
        answer.push_back(genresMap[genresCountV[i].first][0]);
        if(genresMap[genresCountV[i].first].size() > 1) answer.push_back(genresMap[genresCountV[i].first][1]);
    }
    
    return answer;
}