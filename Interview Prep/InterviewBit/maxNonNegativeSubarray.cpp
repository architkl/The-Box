#include <bits/stdc++.h>

using namespace std;

vector<int> maxset(vector<int> &A) {
    int start = 0, end = -1, i = 0, j = 0;
    long long int sum = 0, temp = 0;
    while (j < A.size())
    {
        if (A[j] < 0)
        {
            i = j+1;
            j++;
            temp = 0;
        }
        
        else if (temp+A[j] > sum)
        {
            start = i;
            end = j;
            temp += A[j];
            sum = temp;
            j++;
        }
        
        else if (temp + A[j] == sum && j-i > end-start)
        {
            start = i;
            end = j;
            temp += A[j];
            j++;
        }

        else
        {
            temp += A[j];
            j++;
        }
    }
    
    vector <int> ret(end-start+1);
    for (int p = start; p <= end; p++)
        ret[p-start] = A[p];
    
    return ret;
}

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> b(maxset(a));
    for (auto i : b)
        cout << i << " ";
    cout << "\n";

    return 0;
}