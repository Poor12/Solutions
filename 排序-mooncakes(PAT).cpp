#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
struct Mooncake{
    int inventory; //庫存量
    int all_price;
    double per_price;
    void init(){
        per_price = (all_price * 1.0) / (inventory * 1.0);
    }
    Mooncake() {}
}cake[maxn];
 
bool compare(Mooncake m1, Mooncake m2){
    return m1.per_price > m2.per_price;
}
 
int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    for(int i=0; i<n; i++){
        int num;
        scanf("%d", &num);
        cake[i].inventory = num;
    }
    for(int i=0; i<n; i++){
        int price;
        scanf("%d", &price);
        cake[i].all_price = price;
        cake[i].init();
    }
    sort(cake, cake+n, compare);
    double ans = 0;
    for(int i=0; i<n; i++){
        if(cake[i].inventory < d){
            d -= cake[i].inventory;
            ans += cake[i].all_price;
        }
        else{
            ans += cake[i].per_price * d;
            break;
        }
    }
    printf("%.2f", ans);
    return 0;
}