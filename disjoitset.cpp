#include<iostream>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *parent = nullptr;
    int rank = 0;
    Node(){}
    Node(T t){
      data = t;
    }
};

template <typename T>
class DisjointSet{
public:
    void makeSet(Node<T>* x){
      x->parent = x;
    }

    Node<T>* find(Node<T>* x) {
      if (x->parent != x) {
        x->parent = find(x->parent);
    }
    return x->parent;
    }

    void setUnion(Node<T> *x, Node<T> *y){
      Node<T> *xRoot = find(x);
    Node<T> *yRoot = find(y);

    if (xRoot == yRoot) return;

    if (xRoot->rank < yRoot->rank) {
        xRoot->parent = yRoot;
    } else if (xRoot->rank > yRoot->rank) {
        yRoot->parent = xRoot;
    } else {
        yRoot->parent = xRoot;
        xRoot->rank++;
    }
    }
};

int main(){
  return 0;
}
