#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1010;
ll n, m, q;
vector <vector <int> > A(MM, vector <int> (MM, 0)), B(MM, vector <int> (MM, 0));

void insert(int x1, int y1, int x2, int y2, int c){
	B[x1][y1] += c;
	B[x2 + 1][y1] -= c;
	B[x1][y2 + 1] -= c;
	B[x2 + 1][y2 + 1] += c;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			insert(i, j, i, j, A[i][j]);
		}
	}

	while(q--){
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			B[i][j] = B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1] + B[i][j]; 
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			cout << B[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}

