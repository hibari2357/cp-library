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
//    隣接リスト入力
//    verify用 judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C&lang=jp
    int V; cin >> V;
    struct edge {
        int to, cost;
    };
    vector<vector<edge>> T(V);
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    vector<int> d(V, INF);

    for(int i=0; i<V; i++){
        int from; cin >> from;
        int k; cin >> k;
        T[i].resize(k);
        for(int j=0; j<k; j++)
            cin>> T[i][j].to >> T[i][j].cost;
    }

    Q.push(PII(0, 0));


//  辺が与えられた場合
//  verify用 judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
//    int V, E, S; cin >> V >> E >> S;
//    struct edge {
//        int to, cost;
//    };
//    vector<vector<edge>> T(V);
//    priority_queue<PII, vector<PII>, greater<PII>> Q;
//    vector<int> d(V, INF);
//
//    for(int i=0; i<E; i++){
//        int from, to, cost; cin >> from >> to >> cost;
//        edge e;
//        e.to = to;
//        e.cost = cost;
//        T[from].push_back(e);
//    }
//    Q.push(PII(0, S));

    while(!Q.empty()){
        
        PII p = Q.top();
        int from = p.second;
        int cost = p.first;
        Q.pop();
        
        if(cost > d[from]) continue;
        d[from] = cost;
        for(int i=0; i<T[from].size(); i++){
            edge e = T[from][i];
            if(d[e.to] > d[from] + e.cost){
                Q.push(PII(d[from] + e.cost, e.to));
            }
        }
    }

    for(int i=0; i<V; i++){
        cout << i << " ";
        if(d[i]==INF){
            cout << "INF" << endl;
        }else{
             cout << d[i] << endl;
        }
    }
    return 0;
}
