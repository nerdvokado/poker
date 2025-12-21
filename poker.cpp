#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int money = 1000;
    int cpu_count;
    vector<int> cpu_money;

    cout << "How many CPU players? ";
    cin >> cpu_count;

    for (int i = 0; i < cpu_count; i++) {
        cpu_money.push_back(1000);
    }

    for (int i = 0; i < cpu_money.size(); i++) {
            cout << cpu_money[i] << " ";
    }

    return 0;
}