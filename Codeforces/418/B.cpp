#include <cstdio>
#include <cstring>
static const int MAXN = 1e3 + 4;

int n;
int a[MAXN], b[MAXN];
int pa[2][MAXN], pb[2][MAXN];

inline void try_recover(int *a, int *p1, int *p2)
{
    int dup_ct = 0;
    int dup1 = -1, dup2 = -1, absent = -1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == a[j]) dup1 = i, dup2 = j;
    for (absent = 1; absent <= n; ++absent) {
        bool occurred = false;
        for (int i = 0; i < n; ++i) if (a[i] == absent) { occurred = true; break; }
        if (!occurred) break;
    }

    memcpy(p1, a, n * sizeof(int));
    memcpy(p2, a, n * sizeof(int));
    p1[dup1] = absent;
    p2[dup2] = absent;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

    try_recover(a, pa[0], pa[1]);
    try_recover(b, pb[0], pb[1]);
    int *ans = NULL;
    if (memcmp(pa[0], pb[0], n * sizeof(int)) == 0 || memcmp(pa[0], pb[1], n * sizeof(int)) == 0)
        ans = pa[0];
    else ans = pa[1];

    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
