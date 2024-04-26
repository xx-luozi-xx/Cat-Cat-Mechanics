#include <iostream>
#include <math.h>
using namespace std;
const int MAX_SIZE = 100+30;

struct Vec3{
    double x, y, z;
    Vec3()=default;
    Vec3(double x, double y, double z):x(x),y(y),z(z){}
    Vec3(const Vec3& p1, const Vec3& p2):
        x(p2.x-p1.x),y(p2.y-p1.y),z(p2.z-p1.z){}
    double len(){return sqrt(x*x+y*y+z*z);}
    double len2(){return x*x+y*y+z*z;}
    Vec3 X(const Vec3& rhs){
        return {
            y*rhs.z-z*rhs.y,
            z*rhs.x-x*rhs.z,
            x*rhs.y-y*rhs.x
        };
    }
    double cdot(const Vec3& rhs){
        return x*rhs.x+y*rhs.y+z*rhs.z;
    }
    Vec3 times(double num){
        return {num*x, num*y, num*z};
    }
}F, pos[MAX_SIZE];
double S[MAX_SIZE];

void dooo(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> pos[i].x >> pos[i].y >> pos[i].z;
    }
    for(int i = 1; i <= n-1; ++i){
        int a, b;
        cin >> a >> b;
    }
    int x;
    cin >> x >> F.x >> F.y >> F.z;
    for(int i = 2; i <= n; ++i){
            Vec3 Pq(pos[1], pos[i]);
            Vec3 next_f = Pq.times(F.cdot(Pq)/Pq.len2());
            S[1] += F.X(next_f).len();
            S[i] = next_f.len();
    }
    for(int i = 1; i <= n; ++i){
        printf("%lf\n", S[i]);
        // cout << S[i] << '\n';
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        for(int i = 0; i < MAX_SIZE; ++i){
            S[i] = 0;
        }
        dooo();
    }
    return 0;
}

