#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
 
char alpha[16];
int visit[16];
int L, C;
 
void check() {
    char str[16];
    int vowel = 0, idx = 0;
 
    for (int i = 0; i < C; i++) {
        if (visit[i]) {
            str[idx] = alpha[i];
            idx++;
            if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') 
                vowel++;
        }
    }
    str[L] = '\0';
    
    if (vowel && L - vowel >= 2) printf("%s\n", str);
}
 
int select(int idx, int cnt) {
    if (cnt == L) {
        check();
        return 0;
    }
 
    if (idx == C) return 0;
 
    visit[idx] = 1;
    select(idx + 1, cnt + 1);
 
    visit[idx] = 0;
    select(idx + 1, cnt);
 
    return 0;
}
 
int main() {
    
    scanf("%d %d", &L, &C);
 
    for (int i = 0; i < C; i++)
        scanf(" %c", &alpha[i]);
    
    sort(alpha, alpha + C);
 
    for (int i = 0; i <= C - L; i++) {
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        select(i + 1, 1);
    }
 
    return 0;
}
