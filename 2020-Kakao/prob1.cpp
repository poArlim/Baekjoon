#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int coord[10][2] = {{3,1}, {0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
        
    int left_x = 0;
    int left_y = 3;
    int right_x = 2;
    int right_y = 3;
    
    for (int number : numbers) {
        if (number == 1 or number == 4 or number == 7) {
            left_x = coord[number][1];
            left_y = coord[number][0];
            answer += "L";
        }
        else if (number == 3 or number == 6 or number == 9) {
            right_x = coord[number][1];
            right_y = coord[number][0];
            answer += "R";
        }
        else {
            int next_x = coord[number][1];
            int next_y = coord[number][0];
            int dist_x = abs(next_x - left_x) + abs(next_y - left_y);
            int dist_y = abs(next_x - right_x) + abs(next_y - right_y);
            
            if (dist_x == dist_y) {
                if (hand == "left") {
                    left_x = coord[number][1];
                    left_y = coord[number][0];
                    answer += "L";
                }
                else {
                    right_x = coord[number][1];
                    right_y = coord[number][0];
                    answer += "R";
                }
            }
            else {
                if (dist_x < dist_y) {
                    left_x = coord[number][1];
                    left_y = coord[number][0];
                    answer += "L";
                }
                else {
                    right_x = coord[number][1];
                    right_y = coord[number][0];
                    answer += "R";
                }
            }
        }
    }
    return answer;
}