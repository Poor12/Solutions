#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int m,n;
    long num;
    vector<long int> v;
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>num;
        v.push_back(num);
    } 
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        v.push_back(num);
    } 
    sort(v.begin(),v.end());
    cout<<v[(v.size()-1)/2];
}