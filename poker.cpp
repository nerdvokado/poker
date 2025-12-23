#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    //get random seed
    random_device rd;
    mt19937 rng(rd());

    // holds the money for the player and the cpu players
    int money = 1000;
    int cpu_count;
    vector<int> cpu_money;

    vector<string> card_dictionary = {"1h", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "11h", "12h", "13h", 
        "1d", "2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "11d", "12d", "13d", 
        "1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "11s", "12s", "13s", 
        "1c", "2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "11c", "12c", "13c"};
    
    // holds and loads the cards for the player and cpu players
    vector<string> deck = card_dictionary;
    shuffle(deck.begin(), deck.end(), rng);
    vector<string> player_cards;
    vector<string> load_cards;
    vector<vector<string> > cpu_cards;

    // start a game of poker
    string start_game;
    cout << "Would you like to start a game of poker?(yes/no) ";
    cin >> start_game;

    if (start_game == "yes") {
        cout << "How many CPU players? ";
        cin >> cpu_count;

        for (int i = 0; i < cpu_count; i++) {
            cpu_money.push_back(1000);
        }

        for (int i = 0; i < cpu_money.size(); i++) {
                cout << cpu_money[i] << " ";
        }

        // deals the player's cards
        for (int i = 0; i < 2; i++) { player_cards.push_back(deck.back()); deck.pop_back(); }

        // deals the cpus' cards
        for (int i = 0; i < cpu_count; i++) {
            for (int i = 0; i < 2; i++) { load_cards.push_back(deck.back()); deck.pop_back(); }
            cpu_cards.push_back(load_cards);

            // clears the load_cards vector
            load_cards.clear();
        }
        for (int i = 0; i < cpu_cards.size(); i++) {
            cout << cpu_cards[i][0] << " ";
            cout << cpu_cards[i][1] << " ";
        }
    }

    return 0;

}