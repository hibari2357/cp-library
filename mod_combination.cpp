#define MOD 1000000007

ll power(ll a, ll e){
    if(e==0) return 1;
    if(e%2==0){
        ll r = power(a, e/2);
        return r * r % MOD;
    } else {
        ll r = power(a, e/2);
        return r * r % MOD * a % MOD;
    }
}

ll Inv(ll a){
    return power(a, MOD-2);
}

ll Fact(ll a){
    ll r = 1;
    for(int i=2; i<=a; i++)
        r = r * i % MOD;
    return r;
}


ll Combi(ll a, ll b){
    return Fact(a) % MOD * Inv(Fact(b)) % MOD * Inv(Fact(a-b)) % MOD;
}