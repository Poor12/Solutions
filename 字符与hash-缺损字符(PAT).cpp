#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;
 
void sen_to_upper(char s[])
{
    int len = strlen(s), i = 0, j = 0;
    for (i = 0; i < len; i++)
    {
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }
    }
}
 
int main()
{
    int ans[128] = {0}, i = 0, j = 0, k = 0;
    char real[83], bre_out[83];
    cin >> real;
    cin >> bre_out;
    sen_to_upper(real);
    sen_to_upper(bre_out);
    k = strlen(real);
    for (i = 0; i < k; i++)
    {
        if (ans[int(real[i])] == 1)
        continue;
        else
        {
            if (strchr(bre_out, real[i]) == NULL)
            {
                cout << real[i];
            }
            ans[int(real[i])] = 1;
        }
    }
    return 0;
} 