#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;
    
    int pos;
    for (pos = 0; pos < s.length(); pos++)
        if (s[pos] == '^')
            break;
    
    ll left = 0, right = 0;
    for (int i = pos-1; i>= 0; i--)
        if (s[i] != '=')
            left += (pos-i) * (s[i]-48);
    
    for (int i = pos+1; i < s.length(); i++)
        if (s[i] != '=')
            right += (i-pos) * (s[i]-48);
    
    if (left > right)
        cout << "left\n";
    
    else if (left == right)
        cout << "balance\n";
    
    else
        cout << "right\n";
    
    return 0;
}
