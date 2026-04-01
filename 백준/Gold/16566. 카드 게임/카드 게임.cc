#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,d[4000000],e[4000001],i;
int f(int a){
    return a==e[a]?e[a]:e[a]=f(e[a]);
}
void u(int a,int b){
    e[f(a)]=e[f(b)];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(;i<m;i++)cin>>d[i];
    for(i=1;i<=n;i++)e[i]=i;
    sort(d,d+m);
    while(k--){
        cin>>i;
        n=f(upper_bound(d,d+m,i)-d);
        cout<<d[n]<<"\n";
        u(n,n+1);
    }
}