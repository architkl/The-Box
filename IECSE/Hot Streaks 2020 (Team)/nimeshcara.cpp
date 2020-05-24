#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define vecop(n) vector <int> v(n,0); for(int i=0; i<n; i++) { cin>>v[i]; }

int main() {
    FAST
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;
        ll A[n],i,cnt=1;

        for(int i=0; i<n; i++)
            cin>>A[i];

        if(n==1) {
            cout<<1<<"\n";
            continue;
        }

        for(i=1; i<n; i++){
            if(A[i]>A[i-1])
                A[i] = A[i-1];
            else
                cnt++;
        }

        cout<<cnt<<"\n";
    }
}
