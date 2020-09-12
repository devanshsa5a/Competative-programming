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
        vc v1, v2;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                v1.eb(a[i]);
            else
                v2.eb(a[i]);
        }
        sort(a, a + n);

        sort(v1.rbegin(), v1.rend());
        sort(v2.rbegin(), v2.rend());

        int l = 0, r = n - 1;
        int start = a[l], end = a[r];
        int c = 4;
        int sum = 1;
        while (c--)
        {
            c--;
            int t1 = a[l] * a[l + 1];
            int t2 = a[r] * a[r - 1];
            if (t1 > t2)
            {
                sum *= t1;
                l = l + 2;
            }
            else
            {
                sum *= t2;
                r = r - 2;
            }
        }
        
        if (a[l] < 0 and a[r] < 0)
        {
            int f = 0;
            for (int i = n - 1; i > r; i--)
            {

                if (a[r] == (-1 * a[i]))
                {
                    sum *= abs(a[l]);
                    f = 1;
                    break;
                }
                else if (a[l] == (-1 * a[i]))
                {
                    sum *= abs(a[r]);
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                if (r < n - 1)
                {
                    sum /= a[r + 1];
                    sum *= (a[l] * a[r]);
                }
                else
                {
                    sum *= a[l];
                }
            }
        }
        else
        {
            a[l] > a[r] ? sum *= a[l] : sum *= a[r];
        }
        cout << sum << "\n";
    }
}