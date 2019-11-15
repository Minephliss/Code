#include <iostream>
#include <queue>
using namespace std;

const int maxn = 200000;
int n;

int bfs(int s, vector<int>* map)
{
    int ans = 0, pos = s;
    bool mark[maxn];
    for (int i = 0; i < n; i++)
        mark[i] = false;

    queue<int> que;
    mark[s] = true;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < (int)map[v].size(); i++) {
            bool ok = true;
            int w = map[v][i];
            if (w == s)
                return ++ans;
            if (!mark[w]) {
                if (v == pos && ok) {
                    ans++;
                    pos = w;
                }
                mark[w] = true;
                que.push(w);
            }
        }
    }
    return -1;
}
void approachA()
{
    int p;
    vector<int> map[maxn];
    for (int i = 0; i < n; i++) {
        cin >> p;
        map[i].push_back(p - 1);
    }

    priority_queue<int, vector<int>, greater<int>> que;
    int val;
    for (int i = 0; i < n; i++) {
        val = bfs(i, map);
        if (val != -1)
            que.push(val);
    }
    cout << que.top();
}

int approachB()
{
    int cnt = 0;
    bool ok = false;
    int poses[maxn];
    int targets[maxn];
    for (int i = 0; i < n; ++i) {
        cin >> targets[i];
        targets[i]--;
        poses[i] = i;
    }
    while(!ok)
    {
        cnt++;
        for (int i = 0; i < n; ++i) {
            poses[i] = targets[poses[i]];
            if(poses[i] == i)
                ok = true;
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    cout << approachB();
}
