#include <iostream>
using namespace std;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node *newNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct Node *insert(struct Node *r, int data)
{
    if (r == NULL)
    {
        struct Node *temp = newNode(data);
        return temp;
    }
    if (r->data > data)
        r->left = insert(r->left, data);
    else
        r->right = insert(r->right, data);
    return r;
}

void preOrder(struct Node *r) {
    if (r == NULL) return;
    cout<<r->data<<" ";
    preOrder(r->left);
    preOrder(r->right);
}

void inOrder(struct Node *r) {
    if (r == NULL) return;
    inOrder(r->left);
    cout<<r->data<<" ";
    inOrder(r->right);
}

void postOrder(struct Node *r) {
    if (r == NULL) return;
    postOrder(r->left);
    postOrder(r->right);
    cout<<r->data<<" ";
}

int findSmallestElement(struct Node *r) {
    if(r == NULL) return INT_MAX;
    return min(r->data, min(findSmallestElement(r->left), findSmallestElement(r->right))); 
}

int findLargestElement(struct Node *r) {
    if(r == NULL) return INT_MIN;
    return max(r->data, max(findLargestElement(r->left), findLargestElement(r->right)));
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 13);
    root = insert(root, 9);
    root = insert(root, 12);
    root = insert(root, 8);
    root = insert(root, 11);
    cout<<findLargestElement(root);
    cout<<"hello Thao";
    return 0;
}
