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

bool findValue(struct Node *r, int key) {
  if (r == NULL) return false;
  if (r->data == key) return true;
  if (r->data < key) return findValue(r->right, key);
  return findValue(r->left, key);
}

int countNodes(struct Node *r) {
  if(r == NULL) return 0;
  return 1 + countNodes(r->left) + countNodes(r->right);
}

int countInternalNodes(struct Node *r) {
  if (r == NULL || (r->left == NULL && r->right == NULL)) return 0;
  return 1 + countInternalNodes(r->left) + countInternalNodes(r->right);
}

int getHeight(struct Node *r) {
  if (r == NULL) return 0;
  return 1 + max(getHeight(r->left), getHeight(r->right));
}

struct Node *deleteNode(struct Node *r, int key) {
  if (r == NULL) 
    return r;

  if (r->data > key) 
    r->left = deleteNode(r->left, key);
  else if (r->data < key) 
    r->right = deleteNode(r->right, key);
  else {
    if (r->left == NULL && r->right == NULL) {
      return NULL;
    }
    else if (r->left == NULL) {
      struct Node *temp = r->right;
      free(r);
      return temp;
    }
    else if (r->right == NULL) {
      struct Node *temp = r->left;
      free(r);
      return temp;
    }

    int minValue = findSmallestElement(r->right);

    r->data = minValue;

    r->right = deleteNode(r->right, minValue);
  }

  return r;
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

  inOrder(root);
  cout<<endl;
  deleteNode(root, 10);
  cout<<endl;
  inOrder(root);
  return 0;
}
