#include <bits/stdc++.h>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool fncomp(Interval a, Interval b)
{
	return (a.start < b.start);
}
/*
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	bool (*fn_pt)(Interval, Interval) = fncomp;
    set <Interval, bool(*)(Interval, Interval)> myset(intervals.begin(), intervals.end(), fn_pt);
    set <Interval>::iterator it_s, it_e;

    it_s = myset.upper_bound(newInterval.start);
    it_s--;
    if (it_s.end < newInterval.end)
    	it_s++;

    while (it_e != myset.end() && *it_e <= newInterval.end)
    	it_e++;
    it_e--;
    
    Interval add(it_s.start, )
}*/

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int first = newInterval.start, i = 0;

    while (i < intervals.size() && intervals[i].end < newInterval.start)
    	i++;

    if (i == intervals.size())
    {
    	intervals.push_back(newInterval);
    	return intervals;
    }
    
    else
    {
    	int j = i;

		while (j < intervals.size() && intervals[j].start <= newInterval.end)
			j++;

		j--;
    	
    	Interval add(min(intervals[i].start, newInterval.start), max(intervals[j].end, newInterval.end));

    	vector <Interval> ans;
    	for (int k = 0; k < i; k++)
    		ans.push_back(intervals[k]);

    	ans.push_back(add);

    	for (int k = j+1; k < intervals.size(); k++)
    		ans.push_back(intervals[k]);

    	return ans;
    }
}

int main()
{
	int n;
	cin >> n;

	vector <Interval> A(n);
	int u, v;
	for (int i = 0; i < n; i++)
	{
		cin >> u >> v;

		A[i] = Interval(u, v);
	}

	cin >> u >> v;
	Interval add(u, v);

	A = insert(A, add);
	for (auto i : A)
		cout << i.start << " " << i.end << "\n";

	return 0;
}