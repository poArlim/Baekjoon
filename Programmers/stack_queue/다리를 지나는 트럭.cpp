#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> on_bridge_trucks;   // queue<pair<weight, entering_time>>
    
    int on_bridge_weights = 0;
    int head = 0;
    while(head < truck_weights.size() || !on_bridge_trucks.empty()){
        
        if(!on_bridge_trucks.empty() && answer - on_bridge_trucks.front().second >= bridge_length){
            on_bridge_weights -= on_bridge_trucks.front().first;
            on_bridge_trucks.pop();
        } 
        
        if(head < truck_weights.size() && on_bridge_weights + truck_weights[head] <= weight){
            on_bridge_trucks.push(make_pair(truck_weights[head], answer));
            on_bridge_weights += truck_weights[head];
            head++;
        }
        
        answer++;
    }

    return answer;
}