链接：https://www.nowcoder.com/questionTerminal/339faec2939744bea5a7c53dfab76052
来源：牛客网

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    char c;
    while((c=cin.get())!='\n')
    {
        s1=s1+c;
    }
    while((c=cin.get())!='\n')
    {
        s2=s2+c;
    }
    string::size_type index;
    string::iterator it=s1.begin();
    for(int i=0;i<s2.length();i++)
    {
        while((index=s1.find(s2[i]))!=string::npos)
        {
            s1.erase(index,1);
        }
    }
    cout<<s1<<endl;
    return 0;
}