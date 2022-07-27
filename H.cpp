#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coasts;
    int amount = 0;
    for (int i = 0; i < n; ++i) {
        int ii;
        cin >> ii;
        coasts.push_back(ii);
        amount += ii;
    }
 
    sort(coasts.begin(), coasts.end());
 
    for (int i = coasts.size() - k; i >= 0; i -= k) {
        amount -= coasts[i];
    }
 
    cout << amount;
 
    return 0;
}
