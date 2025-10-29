#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *l, *r;
    Node(int v)
    {
        val = v;
        l = nullptr;
        r = nullptr;
    }
    Node(Node* other){
        val = other->val;
        l = other->l;
        r = other->r;
    }
    Node(Node &other){
        val = other.val;
        l = other.l;
        r = other.r;
    }
    
};
struct head{
    Node 
}
bool push(Node *root,Node *first){

}
int main()
{
    Node root(21);
    Node first(39);
    root.r = &first;

}