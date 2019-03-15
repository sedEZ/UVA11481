#include<iostream>
#define MOD 1000000007
#define T 1002
using namespace std;

long long P[T],C[T][T];
long long DP[T];

void P_init(){
    P[0]=1;
    for(int i=1;i<T;i++)
        P[i] = (P[i-1]*i)%MOD;
}

void C_init(){
    for(int i=0;i<T;i++){
        C[i][0] = C[i][i]=1;
        for(int j=1;j<=i;j++){
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
}

void DP_init(){
    DP[0]=1;DP[1]=0;DP[2]=1;
    for(int i=3;i<T;i++){
        DP[i]=(i-1)*((DP[i-1]+DP[i-2])%MOD)%MOD;
    }
}

long long diff_arrangement(int N,int K,int M){
    long long sum=0;

    for(int i=0;i<=N-K;i++)
        sum= (sum + C[N-K][i]*DP[N-M-i]%MOD)%MOD;
    return sum*C[K][M];

}

int main(){
    int caseNum;

    cin>>caseNum;
    P_init();
    C_init();
    DP_init();
    for(int i=1;i<=caseNum;i++){
        int N,K,M;
        cin>>N>>K>>M;

        long long result = diff_arrangement(N,K,M);

        cout<<"Case "<<i<<": "<<result%MOD<<endl;
    }

    return 0;
}
