#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, L, H;
struct People
{
    string ID;
    int Virtue_Grade, Talent_Grade, Total_Grade;
    int Type; // 4:sage 3:nobleman 2:foolman 1:smallman
    People(string sid, int vg, int tg)
        : ID(sid), Virtue_Grade(vg), Talent_Grade(tg) {}
    void set_type()
    {
        Total_Grade = Virtue_Grade + Talent_Grade;
        if ((Talent_Grade >= H) && (Virtue_Grade >= H))
            Type = 4;
        else if ((Talent_Grade) < H && (Virtue_Grade >= H))
            Type = 3;
        else if ((Talent_Grade < H) && (Virtue_Grade < H) &&
                 (Virtue_Grade >= Talent_Grade))
            Type = 2;
        else
            Type = 1;
    }
    void show()
    {
        cout << ID << " " << Virtue_Grade << " " << Talent_Grade << endl;
    }
};
vector<People> Popu;
 
bool compare(People p1, People p2)
{
    if (p1.Type != p2.Type)
        return p1.Type > p2.Type;
    else
    {
        if (p1.Total_Grade != p2.Total_Grade)
            return p1.Total_Grade > p2.Total_Grade;
        else
        {
            if (p1.Virtue_Grade != p2.Virtue_Grade)
            {
                return p1.Virtue_Grade > p2.Virtue_Grade;
            }
            else
            {
                return p1.ID < p2.ID;
            }
        }
    }
}
 
int main()
{
    scanf("%d %d %d", &n, &L, &H);
    for (int i = 0; i < n; i++)
    {
        string ID_Number;
        int virtue, talent;
        cin >> ID_Number >> virtue >> talent;
        if (virtue < L || talent < L)
            continue;
        People s(ID_Number, virtue, talent);
        s.set_type();
        Popu.push_back(s);
    }
    sort(Popu.begin(), Popu.end(), compare);
    cout << Popu.size() << endl;
    for (auto iter = Popu.begin(); iter != Popu.end(); iter++)
        iter->show();
    return 0;
}