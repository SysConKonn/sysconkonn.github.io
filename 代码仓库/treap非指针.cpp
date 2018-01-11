#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
#define MAX_N 1000010
#define INF 2147483647
#define MOD 999999
using namespace std;
struct point {
  int w, rd, sz, re, l, r;
}p[MAX_N];

int root, ans, tot;

void up (int x) {p[x].sz = p[p[x].l].sz + p[p[x].r].sz + p[x].re;}

void r_rot (int& x) {
  int y = p[x].r;
  p[x].r = p[y].l;
  p[y].l = x;
  p[y].sz = p[x].sz;
  up(x);
  x = y;
}

void l_rot (int& x) {
  int y = p[x].l;
  p[x].l = p[y].r;
  p[y].r = x;
  p[y].sz = p[x].sz;
  up(x);
  x = y;
}

void ins (int x, int& k) {
  //printf("%d %d %d   %d\n", k, p[k].l, p[k].r, x);
  if (k == 0) {
    k = ++tot;
    p[k].w = x;
    p[k].sz = p[k].re = 1;
    p[k].rd = rand();
    //printf("new: %d l:%d r:%d w:%d sz:%d rd:%d\n", k, p[k].l, p[k].r, p[k].w, p[k].sz, p[k].rd);
    return;
  }
  p[k].sz++;
  if (p[k].w == x) p[k].re++;
  else {
    if (x > p[k].w) {
      ins(x, p[k].r);
      if (p[k].rd > p[p[k].r].rd) r_rot(k);
    }
    else if (x < p[k].w) {
      ins(x, p[k].l);
      if (p[k].rd > p[p[k].l].rd) l_rot(k);
    }
  }
}

void del (int x, int& k) {
  if (k == 0) return;
  if (x == p[k].w) {
    if (p[k].re > 1) {p[k].re--, p[k].sz--;return;}
    
    if (p[k].l * p[k].r == 0) k = p[k].l + p[k].r;
    else {
      if (p[p[k].l].rd < p[p[k].r].rd) {
	l_rot(k);
	del(x, k);
      }
      else {
	r_rot(k);
	del(x, k);
      }
    }
  }

  else {
    if (x > p[k].w) {
      p[k].sz--;
      del(x, p[k].r);
    }
    else {
      p[k].sz--;
      del(x, p[k].l);
    }
  }
}

int rank_ (int x, int k) {
  if (k == 0) return 0;
  if (p[k].w == x) return p[p[k].l].sz + 1;
  if (x > p[k].w) return p[p[k].l].sz + rank_(x, p[k].r) + p[k].re;
  if (x <= p[k].w) return rank_(x, p[k].l);
}

int query (int x, int k) {
  if (k == 0) return 0;
  if (x <= p[p[k].l].sz) return query(x, p[k].l);
  else
    if (x > (p[p[k].l].sz + p[k].re))
      return query(x - p[p[k].l].sz - p[k].re, p[k].r);
    else
      return p[k].w;
}

void pre (int x, int k) {
  if (k == 0) return;
  if (p[k].w < x) {
    ans = k;
    pre(x, p[k].r);
  }
  else pre(x, p[k].l);
}

void nxt (int x, int k) {
  if (k == 0) return;
  else if (p[k].w > x) {
    ans = k;
    nxt(x, p[k].l);
  }
  else nxt(x, p[k].r);
}

int main () {
  srand(time(0));
  int op, x, T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &op, &x);
    if (op == 1) {
      ins(x, root);
    }
    else if (op == 2) {
      del(x, root);
    }
    else if (op == 3) {
      printf("%d\n", rank_(x, root));
    }
    else if (op == 4) {
      printf("%d\n", query(x, root));
    }
    else if (op == 5) {
      pre(x, root);
      printf("%d\n", p[ans].w);
    }
    else if (op == 6) {
      nxt(x, root);
      printf("%d\n", p[ans].w);
    }
  }
  return 0;
}
