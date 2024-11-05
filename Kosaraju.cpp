#include <bits/stdc++.h>

using namespace std;
int const Max = 101;
vector<int> adj[Max];
vector<int> r_adj[Max];
bool used[Max];
stack<int> st;
int n, m;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x); // tao ra Transpose graph / lat nguoc cac cung
    }
}
void dfs1(int u)
{
    used[u] = true;
    for (int v : adj[u])
    {
        if (!used[v])
        {
            dfs1(v);
        }
    }
    cout << u << " ";
    st.push(u);
}
void dfs2(int u)
{
    cout << u << " ";
    used[u] = true;
    for (int v : r_adj[u])
    {
        if (!used[v])
        {
            dfs2(v);
        }
    }
}
void SCC()
{
    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs1(i);
        }
    }
    cout << endl;
    memset(used, false, sizeof(used));
    int cnt = 0;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (!used[s])
        {
            cnt++;
            dfs2(s);
            cout << endl;
        }
    }
    if (cnt == 1)
        cout << " Strong Connected" << endl;
    else
        cout << " Not Strong Connected" << endl;
}

int main()
{
    input();
    SCC();
    return 0;
}