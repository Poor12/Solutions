#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
 
long long HowMuch(vector<long long> & money, vector<long long> & product)
{
    long long sum = 0;
    sort(money.begin(), money.end());
    sort(product.begin(), product.end());
    int ms=0;
    int me = money.size() - 1;
    int ps = 0;
    int pe = product.size() - 1;
    bool check = true;
    while(check)
    {
        if(ms > me || pe < ps)
        {
            break;
        }
        if(money[me] * product[pe] > 0)
        {
            sum += money[me] * product[pe];
            me--;
            pe--;
        }
       else if(money[ms] * product[ps] > 0)
        {
            sum += money[ms] * product[ps];
            ms++;
            ps++;
        }
        else
            break;
    }
    return sum;
}
 
 
int main()
{
    int nc,np;
    //ifstream cin("test.txt");
 
    while(cin >> nc)
    {
        vector<long long> vc(nc);
        for(int i=0; i<nc; i++)
        {
            cin >> vc[i];
        }
        int np;
        cin >> np;
        vector<long long> vp(np);
        for(int i=0; i<np; i++)
        {
            cin >> vp[i];  
        //    cout << endl;
        }
        cout << HowMuch(vc, vp) << endl;
    }
}