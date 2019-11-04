#include <iostream>
#define P 1000000007
using namespace std;

long long ave;
int N;
int A[5001];

void prt(int * A, int n){
    for (int i = 0; i < n; ++i)
        cout << A[i] << ' ';
    cout << endl;
}

void solve(int * A, int cur, int sum){
//    ave = (ave % P + sum % P) % P;
    prt(A, cur);
    for(int i = 0; i < N - sum; i++){
        if(cur == 0 || i > A[cur - 1])
    }
}

int main(){
    solve();
}
