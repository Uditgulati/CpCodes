#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a[100001];
vector<vector<lli> > v[5];
lli ss[5]; 
lli big = 1e18;
 
void push(int ind, lli valid, lli aa, lli b, lli c)
{
    vector<lli> temp;
    temp.push_back(valid);
    temp.push_back(aa);
    temp.push_back(b);
    temp.push_back(c);
    v[ind].push_back(temp);
}
 
void init(int ind, int aa, int b, int c)
{
    lli p12 = aa * a[0] + b * a[1];
    lli p23 = c * a[2] + b * a[1];
    lli p123 = aa * a[0] + b * a[1] + c * a[2];
    
 
    if(p12 > 0 && p23 > 0 && p123 > 0)
        push(ind, 10, aa * a[0], b * a[1], c * a[2]), ss[ind] = aa * a[0] + b * a[1] + c * a[2];
    else ss[ind] = -1, push(ind, -1, aa * a[0], b * a[1], c * a[2]);
}
 
void print()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "vector " << i << ":  ";
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << "( " << v[i][j][0] << ", " 
                << v[i][j][1] << ", " <<
                v[i][j][2] << ", " << v[i][j][3] << endl;
        }
    }
 
    for(int i = 0; i < 5; i++)
    {
        cout << "sum " << i << " = " << ss[i] << endl;
    }
}
// +-+
// -+-
// -++
// ++-
// +++
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%lld",&a[i]);
        for(int i = 0; i < 5; i++)
        {
            v[i].clear();
            ss[i] = 0;      
        }           
        if(n == 2)
    {
        if(a[0]> a[1])
        {
            printf("%lld %lld\n", a[0], -a[1]);
        }
        else if(a[0] < a[1])
        {
            printf("%lld %lld\n", -a[0], a[1]);
        }
        else printf("%lld %lld\n", a[0], a[1]); 
        continue;
    }
        init(0, 1, -1, 1);
        init(1, -1, 1, -1);
        init(2, -1, 1, 1);
        init(3, 1, 1, -1);
        init(4, 1, 1, 1);
//      print();
        for(int i = 3; i < n; i++)
        {
           lli tempsum[5] = {0};
        lli s1, s2;
        lli p23, p123;
        // reaching 0 state from 1, 3
        if(ss[1] > 0) s1 = ss[1] + a[i];
        else s1 = big;
        if(ss[3] > 0) s2 = ss[3] + a[i];
        else s2 = big;
        lli mini; int ind = i - 3;
        if(s1 < s2)
        {
            mini = s1;
            p23 = a[i] + v[1][ind][3];
            p123 = a[i] + v[1][ind][2] + v[1][ind][3];
            if(mini == big || p23 <= 0 || p123 <= 0)    
                push(0,-1, v[1][ind][2], v[1][ind][3], a[i]);
            else push(0, 1, v[1][ind][2], v[1][ind][3], a[i]);
        }  
        else
        {
            mini = s2;
            p23 = a[i] + v[3][ind][3];
            p123 = a[i] + v[3][ind][2] + v[3][ind][3];
            if(mini == big || p23 <= 0 || p123 <= 0)
                push(0, -1, v[3][ind][2], v[3][ind][3], a[i]);
            else push(0, 3, v[3][ind][2], v[3][ind][3], a[i]);
        }
        if(mini == big || p23 <= 0 || p123 <= 0) tempsum[0] = -1;
        else tempsum[0] = mini;

        // reaching 1 state from 0

        if(ss[0] > 0) s1 = ss[0] + -1 * a[i];
        else s1 = big;

        mini = s1;
        p123 = -1 * a[i] + v[0][ind][2] + v[0][ind][3];
        p23 = -1 * a[i] + v[0][ind][3];
        if(mini == big || p123 <= 0 || p23 <= 0)    push(1, -1, v[0][ind][2], v[0][ind][3], -1 * a[i]);
        else push(1, 0, v[0][ind][2], v[0][ind][3], -1 * a[i]);
        
        if(mini == big || p23 <= 0 || p123 <= 0) tempsum[1] = -1;
        else tempsum[1] = mini;

        // reaching 2 state from 0

        if(ss[0] > 0) s1 = ss[0] + a[i];
        else s1 = big;
        mini = s1;
        if(mini == big) push(2, -1, v[0][ind][2], v[0][ind][3], a[i]);
        else push(2, 0, v[0][ind][2], v[0][ind][3], a[i]);
        
        if(mini == big) tempsum[2] = -1;
        else tempsum[2] = mini;


        // reaching 3 state from 2, 4
        if(ss[2] > 0) s1 = ss[2] + -1 * a[i];
        else s1 = big;
        if(ss[4] > 0) s2 = ss[4] + -1 * a[i];
        else s2 = big;
        if(s1 < s2) // 2, 4
        {
            mini = s1;
            p23 = -1 * a[i] + v[2][ind][3];
            p123 = -1 * a[i] + v[2][ind][3] + v[2][ind][2];
            if(mini == big || p23 <= 0 || p123 <= 0)    push(3, -1, v[2][ind][2], v[2][ind][3], -1 * a[i]);
            else push(3, 2, v[2][ind][2], v[2][ind][3], -1 * a[i]);
        }  
        else
        {
            mini = s2;
            p23 = -1 * a[i] + v[4][ind][3];
            p123 = -1 * a[i] + v[4][ind][3] + v[4][ind][2];
            if(mini == big || p23 <= 0 || p123 <= 0)    push(3, -1, v[4][ind][2], v[4][ind][3], -1 * a[i]);
            else push(3, 4, v[4][ind][2], v[4][ind][3], -1 * a[i]);
        }
        if(mini == big || p23 <= 0 || p123 <= 0) tempsum[3] = -1;
        else tempsum[3] = mini;

        // reaching 4 state from 2, 4
        if(ss[2] > 0) s1 = ss[2] + a[i];
        else s1 = big;
        if(ss[4] > 0) s2 = ss[4] + a[i];
        else s2 = big;

        if(s1 < s2) // 2, 4
        {
            mini = s1;
            p23 = a[i] + v[2][ind][3];
            p123 = a[i] + v[2][ind][3] + v[2][ind][2];
            if(mini == big || p23 <= 0 || p123 <= 0)    push(4, -1, v[2][ind][2], v[2][ind][3], a[i]);
            else push(4, 2, v[2][ind][2], v[2][ind][3], a[i]);
        }  
        else
        {
            mini = s2;
            p23 = a[i] + v[4][ind][3];
            p123 = a[i] + v[4][ind][3] + v[4][ind][2];
            if(mini == big || p23 <= 0 || p123 <= 0)    push(4, -1, v[4][ind][2], v[4][ind][3], a[i]);
            else push(4, 4, v[4][ind][2], v[4][ind][3], a[i]);
        }
        //cout << ".................. " << mini << endl;
        if(mini == big || p23 <= 0 || p123 <= 0) tempsum[4] = -1;
        else tempsum[4] = mini;

        // copy the latest sum

        for(int j = 0; j < 5; j++)
        {
            ss[j] = tempsum[j];
        }
        }
 
        int minindex = -1;
        lli minval = 1e18;
        for(int i = 0; i < 5; i++)
        {
            if(ss[i] < minval && ss[i] > 0 && v[i][n - 3][0] >= 0)
            {
                minval = ss[i];
                minindex = i;
            }
        }
        // 0 special
        vector<lli> temp;
        int curind = minindex;
        //cout << "minindex = " << minindex << endl;
        for(int i = n - 3; i >= 0; i--)
        {
        //  cout << "curind = " << curind << endl;
            temp.push_back(v[curind][i][3]);
            if(i == 0)
            {
                temp.push_back(v[curind][i][2]);
                temp.push_back(v[curind][i][1]);
            } 
            curind = v[curind][i][0]; 
        }
        for(int i = n - 1; i >= 0; i--)
        {
            printf("%lld ",temp[i]);
        }
        printf("\n");
    }
    return 0;
} 