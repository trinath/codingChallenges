// author: trinath 
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

class Game;
class Player;
class Set;

class Alley{
    public:
        static const int spareBonus = 5;
        static const int spadeBonus = 10;
    private:
        vector<Game*> gameList;
        vector<thread*> threadList;
    public:
        Alley();
        void addGame(int nsets, int nplayers, int triesPerSet);
        ~Alley();
        friend void startThread(void *obj);
    
};

class Game{
    private:
        int sets;
        int triesPerSet;
        vector<Player*> players;
    public:
        Game(int nsets, int nplayers, int ntriesPerSet);
        ~Game();
        void start();
        void stop();
        void play();
        void showBoard();
        void onEvent(char input, char prev, Player *player);        
};

class Player{
    private:
        vector<Set*> sets;
        string board;
        int totalScore;
    public:
        Player(Game *game, int nsets, int triesPerSet);
        ~Player();
        void rollSet(int index, int playerNum);
        string showBoard();
        int getScore();
        void addScore(int score);
        void addBoard(string &s);
};

class Set{
    private:
        vector<int> scores;
        int tries; 
        Game *currentGame;
        Player *currentPlayer;
    public:
        Set(Game *game, Player *player, int ptries);
        ~Set();
        void roll(bool isLast, int playerNum);
};

// Alley Class 
Alley::Alley(){
    threadList.resize(0);
    gameList.resize(0);
}

void startThread(void *obj){
    Game *instance = static_cast<Game*>(obj);
    instance->start();
}

void Alley::addGame(int nsets, int nplayers, int triesPerSet){
    gameList.push_back(new Game(nsets, nplayers, triesPerSet));
    threadList.push_back(new thread(startThread, gameList.back()));
}

Alley::~Alley(){
    for(int i = 0; i < gameList.size(); i++){
        threadList[i]->join();
        delete threadList[i];
        threadList[i] = NULL;
        delete gameList[i];
        gameList[i] = NULL;    
    }
}

// Game Class 
Game::Game(int nsets, int nplayers, int ntriesPerSet){
    sets = nsets;
    players.resize(nplayers);
    for(int i = 0; i < players.size(); i++){
        players[i] = new Player(this, sets, ntriesPerSet);
    }
    triesPerSet = ntriesPerSet; 
}
Game::~Game(){
    stop();
}

void Game::start(){
    play();
}

void Game::stop(){
    for(int i = 0; i < players.size(); i++){
        delete players[i];
        players[i] = NULL;
    }
}

void Game::play(){
    for(int i = 0; i < sets; i++){
        for(int j = 0; j < players.size(); j++){
            players[j]->rollSet(i, j+1);
        }    
    }
    
}
void Game::showBoard(){
    for(Player* iter: players){
        cout << iter->showBoard() << "->" << iter->getScore() << endl;
    }
}
void Game::onEvent(char input, char prev, Player *player){
    string s("");
    s += input;
    int prevScore = prev - '0';
    if(player){
        if(input >= '0' && input <= '9'){
            player->addScore(input-'0');
        } else if (input == '/') {
            player->addScore(Alley::spareBonus + (10 - prevScore));
        } else if (input == '*') {
            player->addScore(Alley::spadeBonus + 10);
        }
        player->addBoard(s);
    }
    showBoard();
}    

// Player
Player::Player(Game *game, int nsets, int triesPerSet){
    sets.resize(nsets);
    for(int i = 0; i < sets.size(); i++){
        sets[i] = new Set(game, this, triesPerSet);
    }
    board = " ";
    totalScore = 0;
}

Player::~Player(){
    for(int i = 0; i < sets.size(); i++){
        delete sets[i];
        sets[i] = NULL;
    }
}

void Player::rollSet(int index, int playerNum){
    bool isLast = index == sets.size() - 1 ? true : false;
    sets[index]->roll(isLast, playerNum);    
}

string Player::showBoard(){
    return board;
}

int Player::getScore(){
    return totalScore;
}

void Player::addScore(int score){
    totalScore += score;
}

void Player::addBoard(string &s){
    board += s;
}

// Set
Set::Set(Game *game, Player *player, int ptries){
    currentGame = game;
    currentPlayer = player;
    tries = ptries;
    scores.resize(tries);
    fill(scores.begin(), scores.end(), 0);
}

Set::~Set(){
    
}

void Set::roll(bool isLast, int playerNum){
    char input, prev = '0';
    for(int i = 0; i < tries; i++){
        cout << "Roll-" << i << " for Player:" << playerNum << endl;
        cin >> input;
        if(input == '*'){
            scores[i] = 10 + Alley::spadeBonus;
        } else if (input == '/'){
            scores[i] = Alley::spareBonus + (10 - (prev - '0'));
        } else {
            scores[i] = input - '0';
        }
        if(input == '*') break;
        if(input == '*' && isLast) {
            isLast = false;
            tries++;
            scores.push_back(0);
        }
        currentGame->onEvent(input, prev, currentPlayer);
        prev = input;      
    }
    if(input == '*'){
        currentGame->onEvent(input, prev, currentPlayer);        
    }
}

// main
int main(){
    Alley a;
    a.addGame(5, 2, 2);
    return 0;
}