#include <bits/stdc++.h>
using namespace std;
vector<int>X,Y,Z;
struct F{
    double x,y,z;
    F(){x=y=z=0;}
    F(double xx,double yy,double zz){x = xx,y = yy, z = zz;}
    F(int from,int to){
        x = X[to]-X[from];
        y = Y[to]-Y[from];
        z = Z[to]-Z[from];
    }
    double len()const{
        return sqrt(x*x+y*y+z*z);
    }
    F operator=(const F &f){x = f.x, y = f.y, z = f.z; return *this;}

};
double cos(const F &f1, const F &f2){
    double t = f1.x*f2.x+f1.y*f2.y+f1.z*f2.z;
    return t/f1.len()/f2.len();
}
F cc(const F &f1, const F &f2){
    return F(f1.y*f2.z-f1.z*f2.y,f1.z*f2.x-f1.x*f2.z,f1.x*f2.y-f1.y*f2.x);
}
int main(){
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    X.resize(n);
    Y.resize(n);
    Z.resize(n);
    for(int i=0;i<n;++i){
        cin >> X[i] >> Y[i] >> Z[i];
    }
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int P;
    vector<F>f(n); // i受到的引力波
    cin >> P;
    P--;
    cin >> f[P].x >> f[P].y >> f[P].z;
    vector<double>ans(n,0); // 引力压迫
    vector<bool>vis(n,false);
    queue<int>q;
    q.push(P);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        vis[now] = true;
        bool ok=1;
        if(abs(f[now].x)<=1e-9 && abs(f[now].y)<=1e-9 && abs(f[now].z)<=1e-9) continue;
        for(auto y:g[now]){
            if(vis[y]) continue;
            F nowy(now,y);
            double t = f[now].len() * cos(f[now],nowy) / nowy.len();
            f[y] = F(t*nowy.x,t*nowy.y,t*nowy.z);
            ans[now]+=cc(f[now],f[y]).len();
            ok = 0;
            q.push(y);
        }
        if(ok){
            ans[now] = f[now].len();
        }
    }
    for(int i=0;i<n;++i){
        printf("%.10lf\n",ans[i]);
    }
    return 0;
}