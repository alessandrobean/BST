#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node* insertNode(Node* root, int v) {
    Node* n = new Node(v);
    if (!root){
        return n;
    }
    Node* cur = root;
    Node* prev = nullptr;
    while (cur) {
        prev = cur;
        if (v < cur->val) cur = cur->l;
        else cur = cur->r;
    }
    if (v < prev->val) prev->l = n;
    else prev->r = n;
    return root;
}

Node* searchNode(Node* root, int v) {
    Node* cur = root;
    while (cur && cur->val != v) {
        if (v < cur->val) cur = cur->l;
        else cur = cur->r;
    }
    return cur;
}

void inorder(Node* root) {
    Node* cur = root;
    while (cur) {
        if (!cur->l) {
            cout << cur->val << " ";
            cur = cur->r;
        } else {
            Node* p = cur->l;
            while (p->r && p->r != cur) p = p->r;
            if (!p->r) {
                p->r = cur;
                cur = cur->l;
            } else {
                p->r = nullptr;
                cout << cur->val << " ";
                cur = cur->r;
            }
        }
    }
}

void preorder(Node* root) {
    Node* cur = root;
    while (cur) {
        if (!cur->l) {
            cout << cur->val << " ";
            cur = cur->r;
        } else {
            Node* p = cur->l;
            while (p->r && p->r != cur) p = p->r;
            if (!p->r) {
                cout << cur->val << " ";
                p->r = cur;
                cur = cur->l;
            } else {
                p->r = nullptr;
                cur = cur->r;
            }
        }
    }
}

void postorder(Node* root) {
    Node* cur = root;
    Node dummy(0);
    dummy.l = root;
    Node* p = nullptr;
    cur = &dummy;
    while (cur) {
        if (!cur->l) cur = cur->r;
        else {
            p = cur->l;
            while (p->r && p->r != cur) p = p->r;
            if (!p->r) {
                p->r = cur;
                cur = cur->l;
            } else {
                Node* x = cur->l;
                Node* y = p;
                while (x != y) {
                    cout << y->val << " ";
                    Node* t = x;
                    while (t->r != y) t = t->r;
                    y = t;
                }
                cout << x->val << " ";
                p->r = nullptr;
                cur = cur->r;
            }
        }
    }
}

Node* deleteNode(Node* root, int v) {
    Node* cur = root;
    Node* parent = nullptr;

    while (cur && cur->val != v) {
        parent = cur;
        if (v < cur->val) cur = cur->l;
        else cur = cur->r;
    }
    if (!cur) return root;

    if (!cur->l || !cur->r) {
        Node* c = cur->l ? cur->l : cur->r;
        if (!parent) {
            delete cur;
            return c;
        }
        if (parent->l == cur) parent->l = c;
        else parent->r = c;
        delete cur;
    } else {
        Node* succ = cur->r;
        Node* succPar = cur;
        while (succ->l) {
            succPar = succ;
            succ = succ->l;
        }
        cur->val = succ->val;
        if (succPar->l == succ) succPar->l = succ->r;
        else succPar->r = succ->r;
        delete succ;
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insertNode(root, 21);
    root = insertNode(root, 10);
    root = insertNode(root, 39);
    root = insertNode(root, 7);
    root = insertNode(root, 12);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    root = deleteNode(root, 10);

    cout << "Inorder dopo cancellazione: ";
    inorder(root);
    cout << endl;
}
