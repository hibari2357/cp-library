class UnionFind {
public:
    vector<int> Parent;

    UnionFind(int N){
        Parent = vector<int>(N, -1);
    }
    
    int root(int A){
        if(Parent[A] < 0) return A;
        else return Parent[A] = root(Parent[A]);
    }
    
    int size(int A){
        return -Parent[root(A)];
    }
    
    bool unite(int A, int B){
        A = root(A);
        B = root(B);
        if(A==B) return false;
        
        if(size(A) < size(B)) swap(A, B);
        Parent[A] += Parent[B];
        Parent[B] = A;
        return true;
    }
};