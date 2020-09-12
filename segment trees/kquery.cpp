#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define vc vector<int>
#define F first
#define S second
#define eb emplace_back





vector<vector<int>> tree(4 * 30000, vector<int>());










int gettotal(int start, int end, int l, int r, int val, int tn)
{
    if (start > r or end < l)
    {
        return 0;
    }
    else if (start >= l and end <= r)
    {
        int sz = tree[tn].size();
        vector<int>::iterator it = upper_bound(tree[tn].begin(), tree[tn].end(), val);
        return sz - (it - tree[tn].begin());
    }

    int mid = start + (end - start) / 2;

    return gettotal(start, mid, l, r, val, 2 * tn) + gettotal(mid + 1, end, l, r, val, 2 * tn + 1);
}

void built_tree(int *a, int start, int end, int tn)
{
    if (start == end)
    {
        tree[tn].emplace_back(a[start]);
        return;
    }
    int mid = start + (end - start) / 2;
    built_tree(a, start, mid, 2 * tn);
    built_tree(a, mid + 1, end, 2 * tn + 1);

    merge(tree[tn * 2].begin(), tree[tn * 2].end(), tree[tn * 2 + 1].begin(), tree[tn * 2 + 1].end(),
          back_inserter(tree[tn]));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        /* code */
    }

    built_tree(a, 0, n - 1, 1);
    cin>>m;
    while (m--)
    {
        int a, b, k, r;

        cin >> a >> b >> k;
        cout<<gettotal(0, n - 1, a - 1, b - 1, k, 1)<<

        // cout << c
          "\n";
    }

}
