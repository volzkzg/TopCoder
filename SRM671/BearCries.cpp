#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 201;
const long long MOD = 1000000007;

class BearCries
{
public:
	long long dp[N][N / 3 + 1][N / 3 + 1];
	int n;
	string message;

	void add(long long &u, long long v)
	{
		u = (u + v) % MOD;
	}
	
	long long dfs(int pos, int a, int b)
	{
		long long &state = dp[pos][a][b];
		if (state != -1) return state;
		//cout << pos << " " << a << " " << b << endl;
		if (pos == n) {
			if (a == 0 && b == 0)
				state = 1;
			else
				state = 0;
		} else {
			state = 0;
			if (message[pos] == ';') {
				if (b > 0)
					add(state, b * dfs(pos + 1, a, b - 1));
				if (a < n / 3)
					add(state, dfs(pos + 1, a + 1, b));
			} else {
				if (a > 0)
					add(state, a * dfs(pos + 1, a - 1, b + 1));
				if (b > 0)
					add(state, b * dfs(pos + 1, a, b));
			}
		}
		return state;
	}
	
	long long count(string message)
	{
		this->message = message;
		n = message.size();
		memset(dp, -1, sizeof(dp));
		return dfs(0, 0, 0);
	}
};

int main()
{
	string message;
	BearCries test;
	cin >> message;
	cout << test.count(message) << endl;
	return 0;
}
