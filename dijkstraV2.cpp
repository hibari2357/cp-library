#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main(){
    int V, E, S; cin >> V >> E >> S;
    vector<vector<int>> cost(V, vector<int>(V, INF));
    vector<bool> used(V);
    vector<int> d(V, INF);

    for(int i=0; i<E; i++){
        int f, t, c; cin >> f >> t >> c;
        cost[f][t] = c;
    }

    d[S] = 0;
    while(1){
        
        int x = -1;
        for(int j=0; j<V; j++){
            if(!used[j] && (x==-1 || d[j]<d[x])) x = j;
        }
        if(x==-1) break;
        used[x] = true;
        for(int j=0; j<V; j++){
            d[j] = min(d[j], d[x] + cost[x][j]);
        }
    }

    for(int i=0; i<V; i++){
        if(d[i]==INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}
