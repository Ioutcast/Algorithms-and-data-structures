#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Stuff {
    char chars;
    unsigned int weight;
};

bool comp(Stuff l, Stuff r){
    return l.weight > r.weight;
}

int main() {
    std::string sinput;
    std::vector<Stuff> array;
    std::cin >> sinput;
    for (int i = 0; i < 26; i++) {
        Stuff stuff;
        stuff.chars = i + 97;
        std::cin >> stuff.weight;
        array.push_back(stuff);
        sort(array.begin(), array.end(), comp);
    }
    int shift = 0;
    std::string answer = sinput;
    for (Stuff stuff: array) {
        int counter = count(answer.begin(), answer.end(), stuff.chars);
        if (counter >= 2) {
            int pos1 = answer.find(stuff.chars);
            std::swap(answer[shift], answer[pos1]);
            int pos2 = answer.substr(++shift).find(stuff.chars);
            if (pos2 + shift != answer.size() - 1) {
                std::swap(answer[answer.size() - shift],answer[pos2 + shift]);
            }
            }
    }
    std::cout << answer << std::endl;
    return 0;
}
