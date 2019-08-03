#include <iostream>
#include <vector>
     
using namespace std;
     
bool qud[10000000];
     
void init()
{
   	for (int i = 0; i < 10000000; i++)
   		qud[i] = 0;
}
     
int main()
{
  	int n, start, end;
   	cin >> n >> start >> end;
     
  	vector <int> A(n);
   	int x, y, z;
   	cin >> A[0] >> x >> y >> z;
     
   	for (int i = 1; i < n; i++)
   		A[i] = (A[i-1] * x + y) % z;//cout << i << " " << A[i] << "\n";}
    /*
   	vector <int> adj[n];
   	for (int i = 0; i < n; i++)
   	{
        //cout << i << "\n";
        adj[i].push_back((n + i - A[i]) % n);
   		for (int j = -A[i]+1; j <= A[i]; j++)
   		{
            if ((n+i+j) % n == (n + i - A[i]) % n)
                break;

            adj[i].push_back((n + i + j) % n);
   		}
   	}*/
/*
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() == 0)
            continue;

        cout << A[i] << "\n";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n\n";
    }*/
     
   	init();
    
   	vector <int> q[2];
   	q[0].push_back(start);
   	q[1].push_back(0);
   	int f = 0, r = 1, cur, flag = 0;
   	for (f; f < r; f++)
   	{
   		cur = q[0][f];
     
   		if (cur == end)
   		{
   			cout << q[1][f];
   			flag = 1;
   			break;
   		}
     
   		for (int i = -A[cur]; i <= A[cur]; i++)
   		{
   			if (qud[(n + cur + i) % n])
   				continue;
    
   			q[0].push_back((n + cur + i) % n);
   			q[1].push_back(q[1][f] + 1);
   			r++;
            qud[(n + cur + i) % n] = 1;
   		}
   	}
    
   	if (!flag)
   		cout << "sad";
    
   	return 0;
}   