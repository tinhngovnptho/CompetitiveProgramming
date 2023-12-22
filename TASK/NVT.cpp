#include <bits/stdc++.h>

using namespace std;

#define MAX_N	1000100

int countDiv[MAX_N]; // countDiv[i] = số ước của số i

void Sieve(int n) {
	countDiv[0] = countDiv[1] = 1;
	for (int i = 2; i <= n; ++i) countDiv[i] = 2;
	for (int i = 2; i * i <= n; i++) {
		countDiv[i*i]++;
		for (int j = i+1; j <= n / i; j++) countDiv[i*j] += 2;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Sieve(MAX_N-1);
}
