#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
int n, ans;
int A[MM], B[MM];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i){cin >> A[i];}
	for (int i = 1; i <= n; ++i){cin >> B[i];}

	for (int i = 1; i <= n; ++i){
		A[i] += A[i - 1]; B[i] += B[i - 1];
		if (A[i] == B[i]){ans = i;}
	}
	cout << ans << endl;

	return 0;
}
