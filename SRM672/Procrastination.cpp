#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int gap = 100;

class Procrastination
{
public:
	vector<long long> num;
	vector<long long> task;
	map<long long, long long> mp;
	
	long long findFinalAssignee(long long n)
	{
		for (long long i = max(n - gap, 2LL); i <= n + gap; ++i) {
			for (long long j = 2; j <= sqrt(i); ++j) {
				if (i % j == 0) {
					if (i / j >= 2)
						num.push_back(j);
					if (j * j != i)
						num.push_back(i / j);
				}
			}
			mp[i] = i;
			task.push_back(i);
		}
		/*
		for (int j = max(n - gap, 2LL); j <= n + gap; ++j)
			cout << mp[j] << " " ; cout << endl;
		*/
		sort(num.begin(), num.end());
		num.resize(unique(num.begin(), num.end()) - num.begin());
		for (int i = 0; i < (int)num.size(); ++i) {
			long long v = num[i];
			for (int j = 0; j < (int)task.size() - 1; ++j) {
				long long u = task[j];
				long long w = task[j + 1];
				if (u != v && u % v == 0)
					swap(mp[u], mp[w]);
			}
			/*
			cout << v << endl;
			for (int j = max(n - gap, 2LL); j <= n + gap; ++j)
				cout << mp[j] << " " ; cout << endl;
			*/
		}
		return mp[n];
	}
};

int main()
{
	long long n;
	cin >> n;
	Procrastination test;
	cout << test.findFinalAssignee(n) << endl;
	return 0;
}
