/*
    Aakash Pahwa ( @aakash10399 )

    Hi there! :D

    __gcd(x, y);
    log10(N);
    floor(K);
    pow(10, K);
    
*/


#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;


int modular_exp(int x, unsigned int y, int p){

    int ret = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) 
            ret = (ret*x) % p;
        y = y>>1;
        x = (x*x) % p;   
    }

    return ret; 

}

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    multiset<string> s;
    string str;

    std::cout << std::setprecision(1) << std::fixed;

    int q;
    
    cin >> q;

    while(q--){

        cin >> str;

        s.insert(str);

        if(s.size()%2==1){
            auto itr = s.begin();
            for(int i=0;i<s.size()/2;i++){
                itr++;
            }
            cout << (double)(stoi(*itr)) << endl;
        }
        else{
            auto itr = s.begin();
            for(int i=0;i<s.size()/2 - 1;i++){
                itr++;
            }
            cout << ( (double)stoi(*itr) + (double)stoi(*(++itr)) ) / 2.0 << endl;
        }

    }

}