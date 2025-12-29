#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

enum Suit { hearts, diamonds, clubs, spades };
enum Value { two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
    Suit suit;
    Value value;
};

int highestHand(vector<Card>& board, vector<Card>& hole);
int randomInt(int min, int max);

int main() {

    // random seed
    random_device rd;
    mt19937 rng(rd());

    int money = 1000;
    int cpu_count;
    vector<int> cpu_money;

    vector<Card> deck;
    vector<Card> player_cards;
    vector<Card> load_cards;
    vector<vector<Card> > cpu_cards;
    vector<Card> board;

    // creates and adds every card to the list of cards
    for (int s = hearts; s < spades; s++) {
        for (int v = two; v < ace; v++) {
            Card new_card;
            new_card.value = static_cast<Value>(v + 1);
            new_card.suit = static_cast<Suit>(s + 1);
            deck.push_back(new_card);
        }
    }

    // game loop
    while (true) {

        shuffle(deck.begin(), deck.end(), rng);

        string start_game;
        cout << "Would you like to start a game of poker?(yes/no) ";
        cin >> start_game;

        if (start_game == "yes") {
            cout << "How many CPU players? ";
            cin >> cpu_count;

            for (int i = 0; i < cpu_count; i++) {
                cpu_money.push_back(1000);
            }

            // prints out the cpu_money for debugging
            for (int i = 0; i < cpu_money.size(); i++) {
                    cout << cpu_money[i] << " ";
            }

            // deals the cards
            for (int i = 0; i < 2; i++) { player_cards.push_back(deck.back()); deck.pop_back(); }

            for (int i = 0; i < cpu_count; i++) {
                for (int i = 0; i < 2; i++) { load_cards.push_back(deck.back()); deck.pop_back(); }
                cpu_cards.push_back(load_cards);

                load_cards.clear();
            }
            
            // prints out the cpus' cards for debugging and stuff
            for (int i = 0; i < cpu_cards.size(); i++) {
                cout << "[[1st card value: " << static_cast<int>(cpu_cards[i][0].value) << ", ";
                cout << "1st card suit: " << static_cast<int>(cpu_cards[i][0].suit) << "], ";
                cout << "[2nd card value: " << static_cast<int>(cpu_cards[i][1].value) << ", ";
                cout << "2nd card suit: " << static_cast<int>(cpu_cards[i][1].suit) << "]], ";
            }

            // deals out the flop
            for (int i = 0; i < 3; i++) {
                board.push_back(deck.back());
                deck.pop_back();
            }

            // randomly sets the players distance from the dealer
            int player_to_dealer_dist = randomInt(1, cpu_count + 1);

            bool can_check = true;
            string action;

            for (int i = 0; i < cpu_count + 1; i++) {
                if (i == player_to_dealer_dist - 1) {
                    cout << money;
                    if (can_check) { 
                        cout << "What would you like to do? (check/bet/fold) "; 
                    } else { 
                        cout << "What would you like to do? (bet/fold) "; 
                    }

                    cin >> action;
                    if (action == "check") {
                        can_check = false;
                    } else if (action == "fold") {
                        break;
                    } else if (action == "bet") {
                        // aight bet
                    }
                }
            }

        } else if (start_game == "no" || start_game == "naur") {
            cout << "ok";
            break;
        }
    }
    
    return 0;

}

int randomInt(int min, int max) {
    uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}

int highestHand(vector<Card>& board, vector<Card>& hole) {
    
}
