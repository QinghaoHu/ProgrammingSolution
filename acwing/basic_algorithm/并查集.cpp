#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 100010;
int P[MM];

int find(int x)
{
    if(P[x] != x)
    {
        P[x] = find(P[x]);
    //  x = P[x];
    }
    return P[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        P[i] = i;
    }

    while(m --)
    {
        char a;
        cin >> a;
        if (a == 'M')
        {
            int x, y;
            cin >> x >> y;
            P[find(x)] = find(y);
        } else
        {
            int x, y;
            cin >> x >> y;
            if (find(x) == find(y)){cout << "Yes" << endl;}
            else {cout << "No" << endl;}
        }
    }

    return 0;
}

作者：QinghaoHu
链接：https://www.acwing.com/activity/content/code/content/7364204/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
