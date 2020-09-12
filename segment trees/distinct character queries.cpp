#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define vc vector<int>
#define F first
#define S second
#define eb emplace_back

vector<vector<bool>> tree(4 * 1e5, vector<bool>(26, false));

vector<bool> gettotal(int start, int end, int l, int r, int tn)
{
    if (start > r or end < l)
    {
        return tree[0];
    }
    else if (start >= l and end <= r)
    {
        return tree[tn];
    }

    int mid = start + (end - start) / 2;

    vector<bool> s(26, false);
    vector<bool> s1 = gettotal(start, mid, l, r, 2 * tn);
    vector<bool> s2 = gettotal(mid + 1, end, l, r, 2 * tn + 1);
    
    for (int i = 0; i < 26; i++)
    {
        if (s1[i])
            s[i] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (s2[i])
            s[i] = true;
    }


    return s;
}
void update(int st, int end, int s, char value, int tn)
{

    if (st == end)
    {
        tree[tn] = vector<bool>(26, false);
        tree[tn][value - 'a'] = true;
        return;
    }
    int mid = st + (end - st) / 2;
    if (mid >= s)
    {
        update(st, mid, s, value, 2 * tn);
    }
    else
    {
        update(mid + 1, end, s, value, 2 * tn + 1);
    }

    tree[tn] = vector<bool>(26, false);
    for (int i = 0; i < 26; i++)
    {
        if (tree[2 * tn][i])
            tree[tn][i] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (tree[2 * tn + 1][i])
            tree[tn][i] = true;
    }

}
void built_tree(string &a, int start, int end, int tn)
{
    if (start == end)
    {
        tree[tn][a[start] - 'a'] = true; // <--- here
        return;
    }
    int mid = start + (end - start) / 2;
    built_tree(a, start, mid, 2 * tn);
    built_tree(a, mid + 1, end, 2 * tn + 1);
    for (int i = 0; i < 26; i++)
    {
        if (tree[2 * tn][i])
            tree[tn][i] = true;
    }
    for (int i = 0; i < 26; i++)
    {
        if (tree[2 * tn + 1][i])
            tree[tn][i] = true;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    cin >> s;
    n = s.length();
    cin >> m;
    built_tree(s, 0, n - 1, 1);

    while (m--)
    {
        int a, b, l, r;
        char c;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            update(0, n - 1, b - 1, c, 1);
        }
        else
        {
            cin >> l >> r;
            int c = 0;
            vector<bool> A = gettotal(0, n - 1, l - 1, r - 1, 1);
            for (auto x : A)
            {
                if (x)
                    c++;
            }
            cout << c
                 << "\n";
        }
    }
}
