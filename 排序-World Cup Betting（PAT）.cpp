#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
    char in[]={'W','T','L'};
    vector<float> first(3);
    vector<float> second(3);
    vector<float> third(3);
    for(int i=0;i<3;++i){
        cin>>first[i];
    }
    for(int i=0;i<3;++i){
        cin>>second[i];
    }
    for(int i=0;i<3;++i){
        cin>>third[i];
    }
    float max1=0,max2=0,max3=0;int index1,index2,index3;
    for(int i=0;i<3;i++){
        if(first[i]>max1){
            max1=first[i];
            index1=i;
        }
    }
     for(int i=0;i<3;i++){
        if(second[i]>max2){
            max2=second[i];
            index2=i;
        }
    }
     for(int i=0;i<3;i++){
        if(third[i]>max3){
            max3=third[i];
            index3=i;
        }
    }
    float value=(first[index1]*second[index2]*third[index3]*0.65-1)*2;
    cout<<in[index1]<<' '<<in[index2]<<' '<<in[index3]<<' '<< setiosflags(ios::fixed)<<setprecision(2)<<value;
}