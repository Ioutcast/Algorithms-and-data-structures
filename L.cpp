#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void add_back(deque<int> &deq, int val){
    // Если в наше число, на которое сдвигаемся, будет меньше чем все остальные в очереди
    // то мы должны их будем удалить, так как наше число будет считаться минимальным,
    // в другом случае перед ним сохранится минимальное число для позции 'окна'.
    // Пример логики ниже кода.
    while (!deq.empty() && deq.back() > val){
        deq.pop_back();
    }
    // Добавляем в конец очереди наше число, на которое мы передвинулись.
    deq.push_back(val);
}

    // Данная функция нужна для того, чтобы удалять число, с которого мы здвинулись.
void del_front(deque<int> &deq, int val){
    if (deq.front() == val){
        deq.pop_front();
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Работа программы:
    deque<int> deq;
    
    // Ищем для 'окна' в начальном положении длины k, минимальное число в нем. 
    int i = 0;
    for (; i < k; i++){
        add_back(deq, arr[i]);
    }
    cout << deq.front() << ' ';

    // Двигаясь вправо ищем для всех остальных расположений 'окна' длиной k минимальное число в нем
    // Двигаться мы будем N - K раз.
    for (; i < n; i++){
        del_front(deq, arr[i - k]);
        add_back(deq, arr[i]);
        cout << deq.front() << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
