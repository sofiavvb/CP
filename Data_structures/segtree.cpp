// Segment Tree
// Build: O(n)
// Update: O(log n)
// Query: O(log n)

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5+10;

// tipo de dado que a segtree vai guardar
typedef int tree;

tree st[MAXN<<2], lazy[MAXN<<2]; 
int vet[MAXN];

#define esq(x) (x<<1)
#define dir(x) (x<<1|1)

// Função de merge: soma, min, max, gcd, etc.
tree merge(tree a, tree b){
    return a + b; // <<<<<< aqui você muda a operação
}

// Valor neutro da operação (0 p/ soma, INF p/ min, -INF p/ max, etc.)
tree neutral(){
    return 0;
}

// Propagação de lazy (se não precisar, pode deixar vazia ou comentar)
void push(int idx, int i, int j){
    if(lazy[idx] == 0) return; // nada a propagar
    st[idx] += (j-i+1) * lazy[idx]; // exemplo: soma em range
    if(i != j){
        lazy[esq(idx)] += lazy[idx];
        lazy[dir(idx)] += lazy[idx];
    }
    lazy[idx] = 0;
}

// build da árvore
void build(int idx, int i, int j){
    if(i == j){
        st[idx] = vet[i];
        return;
    }
    int mid = (i+j)/2;
    build(esq(idx), i, mid);
    build(dir(idx), mid+1, j);
    st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

// atualização pontual
void update(int idx, int i, int j, int pos, tree val){
    if(i == j){
        st[idx] = val;
        return;
    }
    int mid = (i+j)/2;
    if(pos <= mid) update(esq(idx), i, mid, pos, val);
    else update(dir(idx), mid+1, j, pos, val);
    st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

// atualização em range com lazy
void update(int idx, int i, int j, int l, int r, tree val){
    push(idx, i, j);
    if(i > r || j < l) return;
    if(l <= i && j <= r){
        lazy[idx] += val; // acumula no lazy
        push(idx, i, j);
        return;
    }
    int mid = (i+j)/2;
    update(esq(idx), i, mid, l, r, val);
    update(dir(idx), mid+1, j, l, r, val);
    st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

// query em range
// [i, j] é o intervalo do nó atual da segtree idx
// [l, r] é o intervalo da query
tree query(int idx, int i, int j, int l, int r){
    push(idx, i, j);
    if(i > r || j < l) return neutral(); //se os intervalos sao disjuntos
    if(l <= i && j <= r) return st[idx]; 
    int mid = (i+j)/2;
    tree x = query(esq(idx), i, mid, l, r);
    tree y = query(dir(idx), mid+1, j, l, r);
    return merge(x, y);
}

// build(1, 0, n-1); para chamar