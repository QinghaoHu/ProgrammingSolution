#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 5;
ll a[MM], b[MM];
int n, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i){cin >> a[i];}
	for (int i = 0; i < m; ++i){cin >> b[i];}

	int j = 0, i = 0;
	while (i < n && j < m)
    {
        if (a[i] == b[j]) i ++ ;
        j ++ ;
    }

	if (i == n){
	    cout << "Yes" << endl;
	}   else    {
	    cout << "No" << endl;
	}

	return 0;
}
