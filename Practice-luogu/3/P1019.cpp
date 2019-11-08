#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int n;
char start;
string words[21];
string adj[21][21];
int edgeto[21][2];

void connect (int a, int b)
{
    string s1 = words[a];
    string s2 = words[b];
    int minl = min(s1.length(), s2.length());
    for(int i = 1; i < minl; i++)
    {
        bool ok = true;
        for(int j = s1.length() - i, k = 0; j < s1.length(); j++, k++)
            if(s1[j] != s2[k])    { ok = false; break;}
        if(ok)
        {
            char str[i + 1];
            for(int j = 0; j < i; j++)
                str[j] = s2[j];
            str[i] = '\0';
            adj[a][b] = str;
        }
    }
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
        {
            if(j == i)  continue;
            connect(i, j);
            connect(j, i);
        }
    cin >> start;
}

void judge(int &i)
{
    if(edgeto[i][1] != -1)
    {
        i = edgeto[i][1];
        edgeto[i][1] = -1;
    }
    else
        i = edgeto[i][0];
}

string combine(int e)
{
    string ans;
    stack<int> stk;
    for(int i = e; i != -1; judge(i))
        stk.push(i);
    ans += words[stk.top()];
    int s = stk.top();
    stk.pop();
    while(!stk.empty())
    {
        int tar = stk.top();
        stk.pop();
        ans.erase(ans.length() - adj[s][tar].length(), adj[s][tar].length());
        ans += words[tar];
        s = tar;
    }
    return ans;
}

void dfs(int s, int* marked, string& ans)
{
    marked[s]++;
    for(int i = 0; i < n; i++)
    {
        bool ok = false;
        if(adj[s][i] != "" && marked[i] < 2)
        {
            ok = true;
            if(edgeto[i][0] != -1)
                edgeto[i][1] = s;
            else
                edgeto[i][0] = s;
            
            dfs(i, marked, ans);
        }
        if(!ok)
        {
            string res = combine(s);
            if(res.length() > ans.length())
                ans = res;
            else if(res.length() == ans.length())
                ans = min(res, ans);
        }
    }
}

void solve()
{
    string ans;

    int marked[21];
    for(int i = 0; i < n; i++)
    {
        if(words[i][0] == start)
        {
            for(int i = 0; i < n; i++)
            {
                marked[i] = 0;
                for(int j = 0; j < 2; j++)
                    edgeto[i][j] = -1;
            }
            dfs(i, marked, ans);
        }
    }

    cout << ans;
}

int main()
{
    read();
    solve();
    return 0;
}