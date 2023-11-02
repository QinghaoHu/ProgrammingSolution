#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
int tc = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

   	cin >>tc;
   	while(tc--){
   		int N=0, K=0;
   		cin >> N >> K;
   		vector <char> cows(N, ' '), res(N, '.');
   		for (char &ele : cows){
   			cin >> ele;
   		}
   		vector <bool> pos(N, 0);
   		vector <bool> Gp (N, 0);
   		vector <bool> Hp (N, 0);
   		int ans = 0;
   		for (int i = 0; i < N; ++i){
   			if (cows[i] == 'G' && Gp[i] == 0){
   				int last_t = min (N - 1, i + K);
   				int jt = 0;
   				for (int j = last_t; j >= 0; --j){
   					if (pos[j] == 0){
   						pos[j] = 1; res[j] = 'G';++ans;
   						jt = j; break;
   					}
   				}
   				for (int j = jt; j <= min(jt + K, N - 1); ++j){
   					Gp[j] = 1;
   				}
   				for (int j = jt; j >= max (jt - K, 0); --j){
   					Gp[j] = 1;
   				}
   			}
   			if (cows[i] == 'H' && Hp[i] == 0){
   				int last_t = min (N - 1, i + K);
   				int jt = 0;
   				for (int j = last_t; j >= 0; --j){
   					if (pos[j] == 0){
   						pos[j] = 1; res[j] = 'H'; ++ans;
   						jt = j; break;
   					}
   				}
   				for (int j = jt; j <= min (jt + K, N - 1); ++j){
   					Hp[j] = 1;
   				}
   				for (int j = jt; j >= max (jt - K, 0); --j){
   					Hp[j] = 1;
   				}
   			}
   		}
   		cout << ans << endl;
   		for (char &i : res){
   			cout << i;
   		}
   		cout << endl;
   	} 

    return 0;
}
