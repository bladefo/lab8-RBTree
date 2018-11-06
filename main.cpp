#include "rbt.h"
#include <iostream>

using namespace std;

int main()
{
	RBTree t;
	//RBTree::TreeNode* root = new RBTree::TreeNode;

  	t.insert(10);
  	t.insert(15);
  	t.insert(1);
  	t.insert(4);
  	t.insert(9);
  	t.insert(20);

  	cout << "The minimum of the RB tree is " << t.minimum() << endl;
  	cout << "The maximum of the RB tree is " << t.maximum() << endl;

  	cout << "Printing inorder..." << endl;
  	t.inorder();
  	cout << "Printing preorder..." << endl;
  	t.preorder();
  	
	return 0;
}