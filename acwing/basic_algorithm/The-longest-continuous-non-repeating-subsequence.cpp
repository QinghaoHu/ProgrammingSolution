#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 1e5 + 10;
int a[MM], s[MM]; int n;
int res = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i){cin >> a[i];}

	for (int i = 0, j = 0; i < n; i++){
		s[a[i]]++;

		while(s[a[i]] > 1){
			s[a[j]]--;
			j++;
		}
		res = max (res, i - j + 1);
	}
	cout << res << endl;

	return 0;
}

