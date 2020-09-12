#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector<int>
#define F first
#define S second
#define eb emplace_back

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}

int nCrModPFermat(int n, int r, int p)
{

    if (r == 0)
        return 1;

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modInverse(fac[r], p) % p *
            modInverse(fac[n - r], p) % p) %
           p;
}
/*
// dsu started 
int a[1000000],b[1000000];
    int find(int x){
        if(b[x]==x) return x;
        b[x]= find(b[x]);
      return b[x];
    }
    void uniona(int x,int y){
        x=find(x);
        y=find(y);
        if (x!=y) {
            a[y]<a[x] ? b[x]=b[y]:b[y]=b[x];
        }
    }
//cut from here
int n,k;
    cin>>n>>k;
     
   
     for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=i;
    }
     for(int i=1;i<=k;i++){
    int t1,t2;
    cin>>t1>>t2;// basic code for dsu
    uniona(t1,t2);
//dsu ends
*/
int getsum(int *a, int *t, int start, int end, int l, int r, int tn)
{
    if (l > r)
        swap(l, r);
    if (start > r or end < l)
        return 0;
    else if (start >= l and end <= r)
        return t[tn];

    // cout<<"hello\n"    ;

    int mid = start + (end - start) / 2;

    return getsum(a, t, start, mid, l, r, 2 * tn) + getsum(a, t, mid + 1, end, l, r, 2 * tn + 1);
}
void update(int *a, int *t, int st, int end, int s, int value, int tn, bool f)
{

    if (st == end)
    {
    
        t[tn] = value;
        return;
    }
    int mid = st + (end - st) / 2;
    if (mid >= s)
    {
        update(a, t, st, mid, s, value, 2 * tn, !f);
    }
    else
    {
        update(a, t, mid + 1, end, s, value, 2 * tn+1, !f);
    }

    if (f)
        t[tn] = (t[2 * tn] | t[2 * tn + 1]);
    else
        t[tn] = (t[2 * tn] ^ t[2 * tn + 1]);
}
void built_tree(int *a, int *tree, int start, int end, int tn, bool f)
{
    // cout << tn << endl;
    if (start == end)
    {
        // cout << tn << " --> " << a[start]<<" ";
        tree[tn] = a[start];
        return;
    }
    int mid = start + (end - start) / 2;
    built_tree(a, tree, start, mid, 2 * tn, !f);
    built_tree(a, tree, mid + 1, end, 2 * tn + 1, !f);
    if (f)
        tree[tn] = (tree[2 * tn] | tree[2 * tn + 1]);
    else
        tree[tn] = (tree[2 * tn] ^ tree[2 * tn + 1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    // cin>>t;
    t = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int size = 1 << n;
        // cout<<size<<" ";
        int a[size] = {0};
        

        for (int i = 0; i < size; i++)
        {
            cin >> a[i];
            // cout << a[i] << " " << flush;
        }
        // for (int i = 0; i < size; i++)

        int *tree = new int[2 * size];
        built_tree(a, tree, 0ll, size - 1, 1ll, n % 2);
        // cout<<tree[1]<< " ";
        while (m--)
        {
            int p, b;
            cin >> p >> b;
            // cout<<p<<b;
            update(a, tree, 0ll, size - 1, p - 1, b, 1ll, n % 2);
            cout << tree[1] << endl;
            // for(int i=1;i<2*size;i++) cout<<tree[i]<<" ";
            // update(a, tree, 0ll, size - 1, p - 1, a[p-1], 1ll, n % 2);
        }
    }
}