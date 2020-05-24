#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000000
#define vecop(n) vector <int> v(n,0); for(int i=0; i<n; i++) { cin>>v[i]; }

int main() {
    FAST
    ll t;
    cin>>t;

    while(t--) {
        ll n;
        cin>>n;

        ll arr[n][n];
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        }
        int f = 1;
        set <ll> sum;
        ll ele,ele2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] == 1)
                    continue;
                for(int k=0; k<n; k++) {
                    ele = arr[i][k];
                    for(int m=0; m<n; m++) {
                        ele2 = arr[m][j];
                        if(j == k && m == i)
                            continue;
                        sum.insert(ele + ele2);
                    }
                }
                if(sum.find(arr[i][j]) == sum.end()) {
                    f = 0;
                    break;
                }
                sum.clear();
            }
            if(f == 0)
                break;
        }

        if(f == 0)
            cout<<"No\n";
        else
            cout<<"Yes\n";

    }
}
