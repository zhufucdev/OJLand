#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100002;

int n, t;
long long ans = 0;
long long dp[MAXN], pret[MAXN] = {0}, preh[MAXN] = {0};
bool check[MAXN];
struct MoonCake
{
    long long t, b, h;
    bool operator<(const MoonCake &other) const {
        return b < other.b;
    }
} cake[MAXN];

void eat()
{
    for (int i = 1; i <= n; ++i)
    {
        preh[i] = preh[i - 1] + cake[i].h;
        pret[i] = pret[i - 1] + cake[i].t;
        check[i] = check[i - 1] && pret[i] <= cake[i].b && pret[i] <= t;
    }
    for (int i = n; i >= 0; --i)
    {
        for (int j = t; j >= cake[i + 1].t; --j)
        {
            dp[j] = max(dp[j], dp[j - cake[i + 1].t] + cake[i + 1].h);
        }
        if (check[i])
        {
            ans = max(ans, dp[min((long long)t, cake[i + 1].b - 1) - pret[i]] + preh[i]);
        }
    }
}

int main()
{

    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> cake[i].t >> cake[i].b >> cake[i].h;
    sort(cake + 1, cake + 1 + n);
    check[0] = true;
    eat();
    cout << ans << endl;
    return 0;
}