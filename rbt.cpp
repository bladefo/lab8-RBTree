#include "rbt.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void RBTree::insert(int k)
{
	TreeNode* newNode = new TreeNode;
    newNode->key = k;//sets k as key of new node

    if (root == nil)//if the root is nil, we set the new node as the root
    {
    	printf("Inserting %d into empty tree\n", k);
        root = newNode;
        newNode->parent = nil;
    } 
    else//if root is not nil, we set newnode to the left or right of the root
    {
        TreeNode* y = nil;
        TreeNode* x = root;
        while(x != nil)
        {
        	y = x;
          	if( k < x->key )
          	{
            	x = x->left;
          	} 
          	else 
          	{
            	x = x->right;
          	}
        }
        if( k < y->key )
        {
          	printf("Inserting %d on the left of %d\n",k,y->key);
          	y->left = newNode;
        }
        else 
        {
          	printf("Inserting %d on the right of %d\n",k,y->key);
          	y->right = newNode;
        }
        newNode->parent = y;
    }

    newNode->color = RED;
    newNode->left = nil;
    newNode->right = nil;
}

int RBTree::minimum()
{
	minimum(root);
}

int RBTree::minimum(TreeNode* node)
{
	if(node != nil)
	{
		while(node -> left != nil)
		{
			node = node -> left;
		}
	}
	return node -> key;
}

int RBTree::maximum()
{
	maximum(root);
}

int RBTree::maximum(TreeNode* node)
{
	if (node != nil)
	{
		while(node -> right != nil)
		{
			node = node -> right;
		}
	}
	return node -> key;
}

int RBTree::successor()
{
	successor(root);
}

int RBTree::successor(TreeNode* node)
{
	return minimum(node -> right);
}

void RBTree::inorder()
{
	inorder(root);
}

void RBTree::inorder(TreeNode* node)
{
	if(node == nil)
	{
		printf("%d\n", node -> key);
	}
	else
	{
		inorder(node -> left);
		printf("%d\n", node -> key);
		inorder(node -> right);
	}
}

void RBTree::preorder()
{
	preorder(root);
}

void RBTree::preorder(TreeNode* node)
{

	if(node == nil)
	{
		printf("%d\n", node -> key);
	}
	else
	{
		printf("%d\n", node -> key);
		preorder(node -> left);
		preorder(node -> right);
	}
}

void RBTree::deleteNode(TreeNode* node)
{
	TreeNode* oldNode = node;
	TreeNode* newNode = node;

	if(node -> left == nil || node -> right == nil)
	{
		oldNode = node;
	}
	else
	{
		oldNode -> key = successor(node);
	}

	if(oldNode -> left != nil)
	{
		newNode = oldNode -> left;
	}
	else
	{
		newNode = oldNode -> right;
	}

	transplant(oldNode, newNode);
	if(oldNode != newNode)
	{
		node = oldNode;
	}
	delete oldNode;
}

void RBTree::print()
{

}

void RBTree::transplant(TreeNode* oldNode, TreeNode* newNode)
{
	if(newNode != nil)
	{
		newNode -> parent = oldNode -> parent;
	}
	if(oldNode -> parent == nil)
	{
		root = newNode;
	}
	else if(oldNode == oldNode -> parent -> left)
	{
		oldNode -> parent -> left = newNode;
	}
	else
	{
		oldNode -> parent -> right = newNode;
	}
}

void RBTree::rotateLeft(TreeNode* x)
{
	TreeNode* y = x -> right;
	x -> right = y -> left;
	if(y -> left != nil)
	{
		y -> left -> parent = x;
	}
	y -> parent = x -> parent;
	if(x -> parent != nil)
	{
		if(x == x -> parent -> left)
		{
			x -> parent -> left = y;
		}
		else
		{
			x -> parent -> right = y;
		}
	}
	else
	{
		root = y;
	}
	y -> left = x;
	x -> parent = y;
}

void RBTree::rotateRight(TreeNode* x)
{
	TreeNode* y = x -> left;
	x -> left = y -> right;
	if(y -> right != nil)
	{
		y -> right -> parent = x;
	}
	y -> parent = x -> parent;
	if(x -> parent != nil)
	{
		if(x == x -> parent -> right)
		{
			x -> parent -> right = y;
		}
		else
		{
			x -> parent -> left = y;
		}
	}
	else
	{
		root = y;
	}
	y -> right = x;
	x -> parent = y;
}

void RBTree::fixUp(TreeNode* x)
{
	while(x -> color == RED)
	{
		if(x -> parent == x -> parent -> parent -> left)
		{
			TreeNode* y = x -> parent -> parent -> right;
			if(y -> color == RED)
			{
				x -> parent -> color = BLACK;
				y -> color = BLACK;
				x -> parent -> parent -> color = RED;
				x = x -> parent -> parent;
			}
			else
			{
				if(x = x -> parent -> right)
				{
					x = x -> parent;
					rotateLeft(x -> parent -> parent);
				}
			}

			x -> parent -> color = BLACK;
			x -> parent -> parent -> color = RED;
			rotateRight(x -> parent -> parent);
		}
		else
		{
			TreeNode* y = x -> parent -> parent -> left;
			if(y -> color == RED)
			{
				x -> parent -> color = BLACK;
				y -> color = BLACK;
				x -> parent -> parent -> color = RED;
				x = x -> parent -> parent;
			}
			else
			{
				if(x = x -> parent -> left)
				{
					x = x -> parent;
					rotateRight(x -> parent -> parent);
				}
			}

			x -> parent -> color = BLACK;
			x -> parent -> parent -> color = RED;
			rotateLeft(x -> parent -> parent);
		}
	}
}

RBTree::TreeNode* const RBTree::nil = new TreeNode({0, BLACK, nullptr, nullptr, nullptr});