#include <stdio.h>

enum color_t{
  RED, BLACK
};

class RBTree{
  private:
    struct TreeNode {
      int key;
      color_t color;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
    };

    static TreeNode* const nil;

    TreeNode* root = nullptr;

  public:
    /* Fill in with methods */
    RBTree()
    {
        root = nil;
    }

    void insert(int);//works
    void search();

    int minimum();//overloaded
    int minimum(TreeNode*);//works

    int maximum();//overloaded
    int maximum(TreeNode*);

    int successor();
    int successor(TreeNode*);
    
    void inorder();//overloaded
    void inorder(TreeNode*);

    void preorder();
    void preorder(TreeNode*);

    void deleteNode(TreeNode*);
    void print();
    void transplant(TreeNode*, TreeNode*);
      
    void rotateLeft(TreeNode*);//works
    void rotateRight(TreeNode*);//works
    void fixUp(TreeNode*);//works
};