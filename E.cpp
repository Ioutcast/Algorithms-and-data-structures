#include <iostream>
#include <vector>


std::vector<int> array;
int n, k;

bool check(int dist) {
    int lastCow = array[0];
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (array[i] - lastCow >= dist) {
            lastCow = array[i];
            count++;
        }
    }
    bool  answer;
    if (count >= k){
        answer = true;
    } else {
        answer = false;
    }
    return answer;
}


int main() {
    int succes = 1;
    int fail;
    int dist;
    std::cin >> n >> k;
    array.resize(n);
    int i = 0;
    while(i < n) {
        std::cin >> array[i];
        i++;
    }
    fail = array[n - 1];
    while (fail - succes > 1) {
        dist = (fail + succes) / 2;
        if (check(dist)){ 
            succes = dist;
        }
        else fail = dist;
    }
    std::cout << succes <<std::endl;
    return 0;
}
