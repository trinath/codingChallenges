// Author @avtrinath
// TCO Round 1A 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class PingPongQueue{
    public:
        vector <int> whoPlaysNext(vector <int> skills, int n, int k){
            queue<int> winQ;
            int prevwinner, winner, loser, player1 = -1, player2 = -1;
            int playCount[51] = {0};
            int count = 0;

            winner = max(skills[0], skills[1]);
            loser = min(skills[0], skills[1]);
            prevwinner = -1;
            for(int &x: skills) winQ.push(x);
           
            while(count < k){
                if(player1 == -1)
                {
                    player1 = winQ.front();
                    winQ.pop();
                }
                if(player2 == -1)
                {
                    player2 = winQ.front();
                    winQ.pop();
                }          
                winner = max(player1, player2);
                loser = min(player1, player2);
                if(winner == player1){
                    winQ.push(player2);
                    player2 = -1;
                }
                else if(winner == player2){
                    winQ.push(player1);
                    player1 = -1;
                }
                if(winner == prevwinner) playCount[winner]++;
                else playCount[winner] = 1;
                playCount[loser] = 0;
                if(playCount[winner] && playCount[winner]%n == 0){
                    winQ.push(winner);
                    playCount[winner] = 0;
                    if(winner == player1) player1 = -1;
                    else if(winner == player2) player2 = -1;
                }
                prevwinner = winner;
                count++;
            }
            vector<int> v{loser, winner};
            return v;
        } 
};

int main(){
    int n;
    PingPongQueue pq;
    cin >> n;
    vector<int> v(n, 0);
    int i = 0;
    while(n--){
        cin >> v[i];
        i++;
    }
    int m, k;
    cin >> m >> k;
    vector<int> out = pq.whoPlaysNext(v, m, k);
    cout << out[0] << " " << out[1] << endl;
    return 0;
}