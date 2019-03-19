vector<int> prime;
vector<bool> is_prime;
int eratosthenes(int k){
    is_prime.resize(k+1, 1);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i=2; i<=k; i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j=2*i; j<=k; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return (int)prime.size();
}

void eratosthenes2(int k){
    is_prime.resize(k+1, 1);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i=2; i*i<=k; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=k; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return;
}
