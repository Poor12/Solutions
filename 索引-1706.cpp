#include<iostream>  
#include<fstream>  
#include<string>  
using namespace std;  
char refDes[1024][256];     //refDes[i]为旧文献编号为i的文献内容  
int nmapo[1024];     //新文献编号为i的文献，其旧文献编号为nmapo[i];  
int omapn[1024];     //旧文献编号为i的文献，其新文献编号为omapn[i];  
int newRefId;      //当前文献的新文献编号  
bool isEmptyLine(const string &line)  
{  
    for(int i=0;i!=line.size();i++)  
        if(line[i]!=' ')  
            return false;  
    return true;  
}  
int main()  
{  
    ifstream cin("d://1.txt");  
    char line[256];  
    int oldRefId,i,j,k;  
    newRefId=1;  
    char digs[8];    //临时存储数字字符串  
    memset(nmapo,0,sizeof(nmapo));  
    memset(omapn,0,sizeof(omapn));  
    while(cin.getline(line,256)){  
        oldRefId=0;  
        if(isEmptyLine(line))  
            continue;  
        if(line[0]=='['){                            //文献段落  
            j=1,k=0;  
//          memset(digs,'0',sizeof(digs));  
            while(isdigit(line[j]))  
                digs[k++]=line[j++];  
            digs[k]='/0';  
            oldRefId=atoi(digs);  
              
            strcpy(refDes[oldRefId],line+j+1);  
            strcat(refDes[oldRefId],"/n");  
            while(cin.getline(line,256)){  
                if(isEmptyLine(line))  
                    break;  
                    strcat(refDes[oldRefId],line);  
                    strcat(refDes[oldRefId],"/n");  
            }  
        }  
        else{  
            while(!isEmptyLine(line)){  
                i=0;  
                while(line[i]!='/0'){  
                    if(line[i]!='[') cout<<line[i];  
                    else{  
                        i++;j=0;  
                    //  memset(digs,'0',sizeof(digs));  
                        while(isdigit(line[i])) digs[j++]=line[i++];  
                        digs[j]='/0';  
                        k=atoi(digs);  
                        if(omapn[k]==0){  
                        omapn[k]=newRefId;                        
                        nmapo[newRefId]=k;  
                        newRefId++;  
                        }  
                        cout<<'['<<omapn[k]<<']';  //输出新文献编号  
                    }  
                    i++;  
                }  
                cout<<endl;  
                cin.getline(line,256);  
            }  
            cout<<endl;  
        }  
     }  
    for(i=1;i<newRefId;i++)  
        cout<<'['<<i<<']'<<refDes[nmapo[i]]<<endl;  
    system("pause");  
    return 0;  
}
