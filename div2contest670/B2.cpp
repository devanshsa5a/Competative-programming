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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (auto &i : a)
            cin >> i;
        sort(a, a + n);
        int x = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > 0)
                x++;
        }
        if (x == 0)
        {
            int p = 1;
            for (int i = 0; i < 5; i++)
            {
                p *= a[n - 1 - i];
            }
            cout << p << endl;
            continue;
        }
        else if (x == 1 or x == 2)
        {
            int p = 1;
            for (int i = 0; i < 4; i++)
                p *= a[i];
            p *= a[n - 1];
            cout << p << endl;
            continue;
        }
        else if (x == 3 or x == 4)
        {
            int pos1 = 1, pos2 = 1;
            for (int i = 0; i < 4; i++)
                pos1 *= a[i];
            pos1 *= a[n - 1];
            pos2 *= a[0], pos2 *= a[1];
            for (int i = 0; i < 3; i++)
                pos2 *= a[n - 1 - i];
            cout << max(pos1, pos2) << endl;
            continue;
        }
        else if (x == 5 or x > 5)
        {
            int pos1 = 1, pos2 = 1, p3 = 1;
            for (int i = 0; i < 4; i++)
                pos1 *= a[i];
            pos1 *= a[n - 1];
            pos2 *= a[0], pos2 *= a[1];
            for (int i = 0; i < 3; i++)
                pos2 *= a[n - 1 -   i];
            for (int i = 0; i < 5; i++)
                p3 *= a[n - 1 - i];
            cout << max(pos1, max(pos2, p3)) << endl;
            continue;
        }
    }
}