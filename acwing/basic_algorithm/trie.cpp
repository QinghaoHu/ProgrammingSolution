#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;
const int MM = 100010;
int son[MM][26], cnt[MM], idx;
string str;

void insert(string str)
{   
    int p = 0;
    for (int i = 0; i < (int)str.size(); ++i)
    {
        int u = str[i] - 'a';
        if (!son[p][u])son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; i < (int)str.size(); ++i)
    {
        int u = str[i] - 'a';
        if (!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n --)
    {
        char c1;
        cin >> c1;
        if (c1 == 'I')
        {
            cin >> str;
            insert(str);
        }   else    {
            cin >> str;
            cout << query(str) << endl;
        }
    }

    return 0;
}

作者：QinghaoHu
链接：https://www.acwing.com/activity/content/code/content/7359725/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
