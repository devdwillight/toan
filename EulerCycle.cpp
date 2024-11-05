#include <bits/stdc++.h>

using namespace std;
int n, m;
set<int> adj[101];
int degree[101];
void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }
}
void Euler(int v)
{
    vector<int> EC;
    stack<int> st;
    st.push(v);
    while (!st.empty())
    {
        int x = st.top();
        if (adj[x].size() != 0)
        {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else
        {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for (int x : EC)
    {
        cout << x << " ";
    }
}
bool isEulerpath()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 == 1)
        {
            cnt++;
        }
    }
    // duong di euler
    return (cnt == 0 || cnt == 2); // cnt == n
}

int main()
{
    nhap();
    // Euler(1);
    // Euler Path
    if (isEulerpath())
    {
        bool hasOddDegree = false;

        for (int i = 1; i <= n; i++)
        {
            if (degree[i] % 2 == 1)
            {
                cout << " Has only Euler Path " << endl;
                Euler(i);
                hasOddDegree = true;
                break;
            }
        }
        if (!hasOddDegree)
        {
            cout << "Valild Euler Path and Euler Cycle" << endl;
            for (int i = 1; i <= n; i++)
            {
                if (degree[i] > 0)
                {
                    Euler(i);
                    break;
                }
            }
        }
    }
    else
        cout << "INVALID !" << endl;
    return 0;
}