#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
ll n, m, x;
ll A[MM], B[MM];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;
	for (int i = 0; i < n; ++i){cin >> A[i];}
	for (int i = 0; i < m; ++i){cin >> B[i];}

	for (int i = 0, j = m - 1; i < n; ++i){
		while(j >= 0 && A[i] + B[j] > x){j --;}
		if (j >= 0 && A[i] + B[j] == x){cout << i << " " << j << endl;}
	}

	return 0;
}

