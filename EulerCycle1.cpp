#include <bits/stdc++.h>

using namespace std ;
set<int>adj[101];
int in_degree[101], out_degree[101];
int n , m ; 
void nhap(){
    cin >> n>> m ;
    for ( int i = 0 ; i < m ; i++){
        int x ; int y ;  cin >> x >> y ;
        adj[x].insert(y);
        out_degree[x] ++ ;
        in_degree[y]++ ;
    }
}
void Euler( int v){
    vector<int> EC ;
    stack<int>st;
    st.push(v);
    while( !st.empty()){
        int x = st.top();
        if ( !adj[x].empty()){
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            out_degree[x] -- ;
        }
        else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    cout << "Euler path is : " ;
    for ( int x : EC){
        cout << x << " " ;
    }
}
bool isEulerpath(){
    int st =0 , en = 0; 
    for ( int i = 1 ; i <= n ; i++){
        if ( out_degree[i] - in_degree[i] == 1){
            st ++ ;
        }
        else if ( in_degree[i] - out_degree[i] == 1){
            en ++ ;
        }
        else if ( in_degree[i] != out_degree[i]){
            return false ;
        }
    }
    return ((st ==1 && en == 1) || (st == 0 && en == 0));
}

int main (){
nhap();
if ( isEulerpath()){
    int start = 1 ;
        for ( int i = 1 ; i <=n ; i++){
            if ( out_degree[i] - in_degree[i] == 1){
                start = i ;
                break ;
            }
        }
        Euler(start);
    }
    else{
        cout <<" the graph does not have an Euler path "<<endl;
    }
}