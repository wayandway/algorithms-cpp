#include <stdio.h>
#include <string.h>
char sa[100004];
char sb[100004];
int a[100004];
int b[100004];
int main(void)
{
    int tc;
    scanf("%d", &tc);
    
    for (register int t = 1; t <= tc; ++t)
    {
        scanf("%s", &sa);
        scanf("%s", &sb);
        register int len = strlen(sa),flag=0;
        register int acnt = 0, bcnt = 0;
        for (register int i = 0; i < len; ++i)
        {
            if (sa[i] == sb[i])
                continue;
            if (sa[i] == 'a')
                a[acnt++] = i;
            else
                b[bcnt++] = i;
        }
        register long long res = 0;
        for (int i = 0; i < acnt; ++i)
            res = res + (a[i] > b[i] ? a[i] - b[i] : b[i] - a[i]);
        printf("#%d %lld\n", t, res);
    }
    return 0;
}