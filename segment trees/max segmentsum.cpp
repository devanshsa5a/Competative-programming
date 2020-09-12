#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define vc vector<int>
#define F first
#define S second
#define eb emplace_back
struct Data
{

    int sum, pref, suff, ans;
};
vector<Data> t(2e5);

Data combine(Data l, Data r)
{
    Data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
Data make_Data(int val)
{
    Data res;
    res.sum = val;

    res.pref = res.suff = res.ans = val;
    return res;
}

void build(int *a, int v, int tl, int tr)
{
    if (tl == tr)
    {   
        t[v] = make_Data(a[tl]);
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v * 2, tl, tm);
        build(a, v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val)
{
    if (tl == tr)
    {
        t[v] = make_Data(new_val);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
}

Data query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return t[0];
    if (l == tl && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        t[0].ans=t[0].pref=t[0].suff=t[0].sum=INT_MIN;
        int n, m;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        build(a, 1, 0, n - 1);
        cin >> m;
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (a){
                cout << query(1, 0, n - 1, b - 1, c - 1).ans << "\n";
                cout << flush;
            }
            else
            {
                
                update(1, 0, n - 1, b - 1, c);
            }
        }
    }
