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
void update(int *a, int *t, int end, int s, int value)
{
    int d = value - a[s];
    a[s]=value;
    
    int start = 0;
    // cout<<end<<flush;
    int tn = 1;
    t[1] += d;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid >= s)
        {
            tn = 2 * tn;
            end = mid;
        }
        else
        {
            tn = 2 * tn + 1;
            start = mid + 1;
        }

        t[tn] += d;
    }
}
void built_tree(int *a, int *tree, int start, int end, int tn)
{
    if (start == end)
    {
        tree[tn] = a[start];
        return;
    }
    int mid = start + (end - start) / 2;
    built_tree(a, tree, start, mid, 2 * tn);
    built_tree(a, tree, mid + 1, end, 2 * tn + 1);

    tree[tn] = tree[2 * tn] + tree[2 * tn + 1];
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int *tree = new int[2 * n];
        built_tree(a, tree, 0ll, n - 1, 1ll);

        for (int i = 1; i < 2 * n; i++)
            cout << tree[i] << " ";
        cout << endl;
        // update(a,tree,n-1,1ll,1ll);
        // cout<<"what?";
        for (int i = 1; i < 2 * n; i++)
            cout << tree[i] << " ";

        cout << endl;
        cout << getsum(a, tree, 0ll, n - 1, 1ll, 2ll, 1ll);
    }
}