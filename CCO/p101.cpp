#include <bits/stdc++.h>

const int MM = 100;

typedef long long ll;

using namespace std;
int N = 0;
vector <int> relation;
set <int> factor;
vector <int> rkb;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	while(N != 0){
		relation.clear(); relation.resize (MM + 1, 0);
		factor.clear();rkb.clear(); rkb.resize (MM + 1, 0);
		for (int i = 0; i < N; ++i){
			int x, y;
			cin >> x >> y;
			relation[x] = y;
		}
		for (int i = 1; i <= N; ++i){
			bool isV = false;
			int j = i;
			int term = 0;
			while (!isV){
				j = relation[j];
				++term;
				if (j == i){
					isV = true;
				}
			}
			vector <int> sub_rkb(MM + 1, 0);
			bool isF = false;
			int k = 2;
			while(!isF){
				if (term%k == 0){
					term /= k;
					sub_rkb[k]++;
				}	else if (k >= term){
					sub_rkb[term]++;
					isF = true;
				}	else if (term%k != 0){
					++k;
				}
			}
			for (int i = 0; i < MM + 1; ++i){
				if (sub_rkb[i] > rkb[i]){
					rkb[i] = sub_rkb[i];
				}
			}
		}
		int ans = 1;
		for (int i = 0; i < MM + 1; ++i){
			for (int j = 0; j < rkb[i]; ++j){
				ans *= i;
			}
		}
		cout << ans << endl;
		cin >> N;
		
	} 

    return 0;
}
