#include <cstdio>
using namespace std;
 
struct money
{
    int galleon, knut, sickle;
public:
    money() {}
    money(int g, int s, int k): galleon(g), knut(k), sickle(s){}
public:
    money operator+(const money &m) const{
        money s;
        s.knut = knut + m.knut;
        s.sickle = sickle + m.sickle;
        s.galleon = galleon + m.galleon;
        s.sickle += (s.knut / 29);
        s.knut = s.knut % 29;
        s.galleon += (s.sickle / 17);
        s.sickle = s.sickle % 17;
        return s;
    }
};
 
int main(){
    int g, s, k;
    scanf("%d.%d.%d", &g, &s, &k);
    money m1(g, s, k);
    scanf("%d.%d.%d", &g, &s, &k);
    money m2(g, s, k);
    money m = m1 + m2;
    printf("%d.%d.%d\n", m.galleon, m.sickle, m.knut);
    return 0;
}
