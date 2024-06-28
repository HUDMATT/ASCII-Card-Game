#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Deck {
protected:
	vector < pair<string, int>> card_values =
	{ {"Spades", 1}, {"Spades", 2}, {"Spades", 3}, {"Spades", 4}, {"Spades", 5}, {"Spades", 6}, {"Spades", 7}, {"Spades", 8}, {"Spades", 9}, {"Spades", 10}, {"Spades", 11}, {"Spades", 12}, {"Spades", 13},
	{"Clubs", 1}, {"Clubs", 2}, {"Clubs", 3}, {"Clubs", 4}, {"Clubs", 5}, {"Clubs", 6}, {"Clubs", 7}, {"Clubs", 8}, {"Clubs", 9}, {"Clubs", 10}, {"Clubs", 11}, {"Clubs", 12}, {"Clubs", 13},
	{"Hearts", 1}, {"Hearts", 2}, {"Hearts", 3}, {"Hearts", 4}, {"Hearts", 5}, {"Hearts", 6}, {"Hearts", 7}, {"Hearts", 8}, {"Hearts", 9}, {"Hearts", 10}, {"Hearts", 11}, {"Hearts", 12}, {"Hearts", 13},
	{"Diamonds", 1}, {"Diamonds", 2}, {"Diamonds", 3}, {"Diamonds", 4}, {"Diamonds", 5}, {"Diamonds", 6}, {"Diamonds", 7}, {"Diamonds", 8}, {"Diamonds", 9}, {"Diamonds", 10}, {"Diamonds", 11}, {"Diamonds", 12}, {"Diamonds", 13} };

public:
	pair<string, int> pick_card() {
		int i = rand() % card_values.size();
		pair<string, int> card = card_values[i];
		card_values.erase(card_values.begin() + i);
		return card;
	}
};

class Player {
protected:
	vector < pair<string, int>> hand;
	int score = 0;
public:
	void display_hand() {
		for (const auto& pair : hand) {
			switch (pair.second) {
			case 1:
				cout << " _____" << endl
					<< "|A .  |" << endl
					<< "| /.\\ |" << endl
					<< "|(_._)|" << endl
					<< "|  |  |" << endl
					<< "|____V|" << endl
					<< pair.first << endl;
				break;
			case 2:
				cout << " _____" << endl
					<< "|2    |" << endl
					<< "|  ^  |" << endl
					<< "|     |" << endl
					<< "|  ^  |" << endl
					<< "|____Z|" << endl
					<< pair.first << endl;
				break;
			case 3:
				cout << " _____" << endl
					<< "|3    |" << endl
					<< "| ^ ^ |" << endl
					<< "|     |" << endl
					<< "|  ^  |" << endl
					<< "|____E|" << endl
					<< pair.first << endl;
				break;
			case 4:
				cout << " _____" << endl
					<< "|4    |" << endl
					<< "| ^ ^ |" << endl
					<< "|     |" << endl
					<< "| ^ ^ |" << endl
					<< "|____h|" << endl
					<< pair.first << endl;
				break;
			case 5:
				cout << " _____" << endl
					<< "|5    |" << endl
					<< "| ^ ^ |" << endl
					<< "|  ^  |" << endl
					<< "| ^ ^ |" << endl
					<< "|____S|" << endl
					<< pair.first << endl;
				break;
			case 6:
				cout << " _____" << endl
					<< "|6    |" << endl
					<< "| ^ ^ |" << endl
					<< "| ^ ^ |" << endl
					<< "| ^ ^ |" << endl
					<< "|____9|" << endl
					<< pair.first << endl;
				break;
			case 7:
				cout << " _____" << endl
					<< "|7    |" << endl
					<< "| ^ ^ |" << endl
					<< "|^ ^ ^|" << endl
					<< "| ^ ^ |" << endl
					<< "|____L|" << endl
					<< pair.first << endl;
				break;
			case 8:
				cout << " _____" << endl
					<< "|8    |" << endl
					<< "|^ ^ ^|" << endl
					<< "| ^ ^ |" << endl
					<< "|^ ^ ^|" << endl
					<< "|____8|" << endl
					<< pair.first << endl;
				break;
			case 9:
				cout << " _____" << endl
					<< "|9    |" << endl
					<< "|^ ^ ^|" << endl
					<< "|^ ^ ^|" << endl
					<< "|^ ^ ^|" << endl
					<< "|____6|" << endl
					<< pair.first << endl;
				break;
			case 10:
				cout << " _____" << endl
					<< "|10 ^ |" << endl
					<< "|^ ^ ^|" << endl
					<< "|^ ^ ^|" << endl
					<< "|^ ^ ^|" << endl
					<< "|___0I|" << endl
					<< pair.first << endl;
				break;
			case 11:
				cout << " _____" << endl
					<< "|J  ww|" << endl
					<< "| ^ {)|" << endl
					<< "|(.)% |" << endl
					<< "| | % |" << endl
					<< "|__%%[|" << endl
					<< pair.first << endl;
				break;
			case 12:
				cout << " _____" << endl
					<< "|Q  ww|" << endl
					<< "| ^ {(|" << endl
					<< "|(.)%%|" << endl
					<< "| |%%%|" << endl
					<< "|_%%%O|" << endl
					<< pair.first << endl;
				break;
			case 13:
				cout << " _____" << endl
					<< "|K  WW|" << endl
					<< "| ^ {)|" << endl
					<< "|(.)%%|" << endl
					<< "| |%%%|" << endl
					<< "|_%%%>|" << endl
					<< pair.first << endl;
				break;
			}
		}
	}
	void pull_card(pair <string, int> card) {
		hand.push_back(card);
	}
	int get_score() {
		return score;
	}
	void adjust_score() {
		score = 0;
		for (int i = 0; i < hand.size(); ++i) {
			score = score + hand[i].second;
		}
	}
};

int main() {
	srand(time(NULL));
	Deck deck;
	Player player1;
	Player player2;
	Player player3;
	Player player4;
	cout << "This game will have 4 players pick 4 cards, whoever has the highest value cards will win!" << endl
		<< "Player 1, press enter to pick 4 cards" << endl;
	cin.ignore();
	for (int i = 0; i < 4; ++i) {
		player1.pull_card(deck.pick_card());
	}
	cout << "Player 2, press enter to pick 4 cards" << endl;
	cin.ignore();
	for (int i = 0; i < 4; ++i) {
		player2.pull_card(deck.pick_card());
	}
	cout << "Player 3, press enter to pick 4 cards" << endl;
	cin.ignore();
	for (int i = 0; i < 4; ++i) {
		player3.pull_card(deck.pick_card());
	}
	cout << "Player 4, press enter to pick 4 cards" << endl;
	cin.ignore();
	for (int i = 0; i < 4; ++i) {
		player4.pull_card(deck.pick_card());
	}
	cout << "Player 1, press enter to see your deck" << endl;
	cin.ignore();
	cout << "Player 1's Hand:" << endl;
	player1.display_hand();
	player1.adjust_score();
	cout << "Player 1's Score: " << player1.get_score() << endl << endl;
	cout << "Player 2, press enter to see your deck" << endl;
	cin.ignore();
	cout << "Player 2's Hand:" << endl;
	player2.display_hand();
	player2.adjust_score();
	cout << "Player 2's Score: " << player2.get_score() << endl << endl;
	cout << "Player 3, press enter to see your deck" << endl;
	cin.ignore();
	cout << "Player 3's Hand:" << endl;
	player3.display_hand();
	player3.adjust_score();
	cout << "Player 3's Score: " << player3.get_score() << endl << endl;
	cout << "Player 4, press enter to see your deck" << endl;
	cin.ignore();
	cout << "Player 4's Hand:" << endl;
	player4.display_hand();
	player4.adjust_score();
	cout << "Player 4's Score: " << player4.get_score() << endl << endl;
	vector <int> scores = { player1.get_score(), player2.get_score(), player3.get_score(), player4.get_score() };
	auto max = max_element(scores.begin(), scores.end());
	if (distance(scores.begin(), max) == 0) {
		cout << "Player 1 Wins!!!" << endl;
	}
	else if (distance(scores.begin(), max) == 1) {
		cout << "Player 2 Wins!!!" << endl;
	}
	else if (distance(scores.begin(), max) == 2) {
		cout << "Player 3 Wins!!!" << endl;
	}
	else if (distance(scores.begin(), max) == 3) {
		cout << "Player 4 Wins!!!" << endl;
	}
	return 0;
}