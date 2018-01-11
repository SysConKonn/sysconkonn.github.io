#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX_L 1000006
#define MAX_N 160
#define INF 2147483647
using namespace std;

int N;
char s[MAX_N][100];
int s_[150];
char t[MAX_L];

struct ac {
    int ch[MAX_L][30];
    int val[MAX_L];
    int fail[MAX_L];
    int ifail[MAX_L][30];
    int sz = 1;
    int toti = 0;
    int idx(char c) {return c - 'a';}
    
    void init() {
    	memset(ch, 0, sizeof(ch));
    }
    
    void insert (char* s, int t) {
        int u = 0, len_ = strlen(s);
        for (int i = 0;i < len_; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                ch[u][c] = sz++;
            }
            fail[ch[u][c]] = u;
            u = ch[u][c];
        }
        s_[t] = u;
    }
    
    void getfail() {
        queue<int> Q;
        fail[0] = 0;
        for (int i = 0;i < 26; ++i) {
            if (ch[0][i]) {
                Q.push(ch[0][i]);
            }
        }
        
        while (!Q.empty()) {
            int x = Q.front();Q.pop();
            for (int i = 0;i < 26; ++i) {
                int u = ch[x][i];
                if (!u) continue;
                Q.push(u);
                int v = fail[x];
                while (v && !ch[v][i]) v = fail[v];
                fail[u] = ch[v][i];
                ifail[fail[u]][i] = u;
                //printf("%d %c : %d\n", u, i + 'a' , fail[u]);
            }
        }

	for (int i = 0;i < sz; ++i) printf("%d ", fail[i]);
	printf("\n");
    }
    
    void search (char* t) {
        int len_ = strlen(t);
        int k = 0;
        for (toti = 0; toti < len_; ++toti) {
            int c = idx(t[toti]);
            while (k && !ch[k][c]) k = fail[k];
            k = ch[k][c];
            val[k]++;
        }
    }
    
    int dfs(int x) {
        
        int sum = 0;
        for (int i = 0;i < 26; ++i) if (ifail[x][i]) sum++;
        if (sum == 0) return val[x];
        sum = val[x];
        for (int i = 0;i < 26; ++i) {
            if (!ifail[x][i]) continue;
            sum += dfs(ifail[x][i]);
        }
        return sum;
    }
    
    int find (int u) {
        int res = dfs(u);
        return res;
    }
};
ac aho;
int ans = 0;

int main () {
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        if (N <= 20) aho.init();
        for (int i = 0;i < N; ++i) {
            scanf("%s", s[i]);
            aho.insert(s[i], i);
        }
        aho.getfail();
    
        scanf("%s", t);
        aho.search(t);
    
        int res = 0;
        int _s[150];
        for (int i = 0;i < N; ++i) {
            _s[i] = aho.find(s_[i]);
            res = max(_s[i], res);
        }
        printf("%d\n", res);
        for (int i = 0;i < N; ++i) {
            if (_s[i] == res) printf("%s\n", s[i]);
        }
    }
    
    return 0;
}
