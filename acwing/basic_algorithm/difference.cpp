#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
int n, m;
vector <int> a(MM, 0), b(MM, 0);

void add(int l, int r, int c){
	b[l] += c;
	b[r + 1] -= c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for (int i = 0; i <= n; ++i){add(i, i, a[i]);}

	while(m--){
		int l, r, c;
		cin >> l >> r >> c;
		add(l, r, c);
	}
	for (int i = 1; i <= n; ++i){b[i] += b[i - 1];}

	for (int i = 1; i <= n; ++i){cout << b[i] << " ";}
	cout << endl;

	return 0;
}

