// author trinath src interviewbit
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution{
    public:
        int maxPointsInLine(vector<int> x, vector<int> y){
            int result = 1, xdelta, ydelta, gcf, maxPoints = 0, curPoints, equalPoints;
            map< pair<int,int>, int > umap;
            for(int i = 0; i < x.size(); i++){
                umap.clear();
                curPoints = 0;
                equalPoints = 1;
                for(int j = i+1; j < x.size(); j++){
                    xdelta = x[j] - x[i];
                    ydelta = y[j] - y[i];
                    if(xdelta == 0 && ydelta == 0){
                        equalPoints++;
                        continue;
                    } else if(xdelta == 0){
                        umap[make_pair(0, 1)]++;
                        curPoints = max(curPoints, umap[make_pair(0, 1)]);
                    } else if(ydelta == 0){ 
                        umap[make_pair(1, 0)]++;
                        curPoints = max(curPoints, umap[make_pair(1, 0)]);
                    } else {
                        if(xdelta < 0){
                            xdelta = -1 * xdelta;
                            ydelta = -1 * ydelta;
                        }
                        gcf = __gcd(abs(xdelta), abs(ydelta));
                        umap[make_pair(xdelta/gcf, ydelta/gcf)]++;
                        curPoints = max(curPoints, umap[make_pair(xdelta/gcf, ydelta/gcf)]);
                    }
                }
                maxPoints = max(maxPoints, curPoints + equalPoints);
            }
            return maxPoints;
        }
};

int main(){
    Solution s;
    int i, n;
    cin >> n;
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << s.maxPointsInLine(x, y) << endl;
    return 0;
}