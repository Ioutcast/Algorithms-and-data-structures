#include <iostream>
#include <unordered_set>
#include <list>
#include <queue>
#include <limits.h>

void solve() {
    int n;
    int k;
    int p;
    int steps = 0;
    std::cin >> n;
    std::list<int> entry[n];
    std::cin>> k;
    std::cin >> p;
    int hist[p];
    while (steps<p){
        std::cin >> hist[steps];
        entry[--hist[steps]].push_back(steps);
        steps++;
    }
    steps=0;
    std::priority_queue<std::pair<int, int>> id;
    std::unordered_set<int> car;
    for (int i = 0; i < p; i++){
        int current = hist[i];
        entry[current].pop_front();

        if (car.find(current) == car.end()){
            if (car.size() >= k) {
                car.erase(id.top().second);
                id.pop();
            }
            steps++;
            car.insert(current);
        }
        if (entry[current].empty()) {
            id.push({INT_MAX, current});
        }
        else {
            id.push({entry[current].front(), current});
        }
    }
    std::cout << steps << std::endl;

}
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    solve();
    return 0;
} 
