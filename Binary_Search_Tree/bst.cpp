#include<iostream>
#include<cstdlib>
#include<deque>
#include "bst.h"
#include<vector>
#include<stack>

using namespace std;

//constructor

BTree::BTree() {
	root = NULL;
}

/*
Insert nodes in a binary tree
*/

void BTree::insert(int x){
	
	insert(root,x);
}


void BTree::insert(TreeNode* node, int x) {

	if(root == NULL) {
		
		root = new TreeNode(x);
	}
	else {
	
		if(x < node->val) {
		
			if(node->left != NULL) {
			
				insert(node->left, x);
			}	
			else {
			
				node->left = new TreeNode(x);
			}
		}
		else {
	
			if(node->right != NULL) {
		
				insert(node->right, x);
			}
			else {
			
				node->right = new TreeNode(x);
			}
		}

	}
}


/*
Display nodes of binary tree in pre-order, post-order and in-order
*/

void BTree::display() {

	display(root);
	cout << endl;
}



void BTree::display(TreeNode* ptr)
{
	if(root != NULL)
	{
		
		cout << ptr->val << " ";
		
		if(ptr->left != NULL)
		{
			display(ptr->left);
		}
	
		//cout << ptr->val << " ";
		
		if(ptr->right != NULL)
		{
			display(ptr->right);
		}

		
		//cout << ptr->val << " ";
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}

/*
Given a binary tree find its height.
*/

int BTree::getHeight() {

	getHeight(root);
}

int BTree::getHeight(TreeNode* node){
	
	if(node == NULL) {
		return 0;
	}

	return max(getHeight(node->left),getHeight(node->right)) + 1;

}

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

bool BTree::isBalanced() {

	return isBalanced(root);
}

bool BTree::isBalanced(TreeNode* node) {

	if(node == NULL) {
	
		return true;
	}

	return isBalanced(node->left) && isBalanced(node->right) && (abs(getHeight(node->left)-getHeight(node->right)) <= 1);
}

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

bool BTree::isSameTree(BTree* tree1, BTree* tree2){

	return isSameTreePrivate(tree1->root,tree2->root);

}

bool BTree::isSameTreePrivate(TreeNode* p, TreeNode* q) {

	if(p==NULL && q==NULL) {
	
		return true;
	}

	if(p==NULL || q==NULL) {
	
		return false;	
	}

	if(p->val == q->val) {
		
		bool left = isSameTreePrivate(p->left,q->left);
		bool right = isSameTreePrivate(q->right,q->right);

		return left && right;	

	}

	return false;
}

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/

void BTree::printLevelByLevel() {
	
	deque<TreeNode *> q1;
	deque<TreeNode *> q2;

	TreeNode* node;
	
	q1.push_back(root);

	while(!q1.empty() || !q2.empty()) {
		while(!q1.empty()) {

			node = q1.at(0);
			q1.pop_front();
			cout << node->val << " ";
				
			if(node->left != NULL) {
			
				q2.push_back(node->left);
			}

			if(node->right != NULL) {
			
				q2.push_back(node->right);
			}		
		}

		cout << endl;

		while(!q2.empty()) {
			
			node = q2.at(0);
			q2.pop_front();
			cout << node->val << " ";

			if(node->left != NULL) {
				q1.push_back(node->left);
			}

			if(node->right != NULL) {
				q1.push_back(node->right);
			}
		}
		
		cout << endl;
	}

}

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
*/

bool BTree::hasPathSum(int sum) {

	return hasPathSum(root,sum);
}

bool BTree::hasPathSum(TreeNode* node, int sum) {

	if(root == NULL) {
		return false;
	}

	if(node->left == NULL && node->right == NULL) {
		return node->val == sum;
	}

	return hasPathSum(node->left,sum-node->val) || hasPathSum(node->right, sum-node->val);
}

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

int BTree::minDepth() {
	
	return minDepth(root);
}

int BTree::minDepth(TreeNode* node) {

	int left_depth = 0;
	int right_depth = 0;
	
	if(root == NULL) {
		return 0;
	}

	if(node->left == NULL && node->right == NULL) {
		
		return 1;
	}

	if(node->left != NULL) {
	
		left_depth = minDepth(node->left);
	}

	if(node->right != NULL) {
	
		right_depth = minDepth(node->right);
	}

	return 1 + min(left_depth,right_depth);
}

/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
*/


BTree::TreeNode* BTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

if(root == NULL) {
            return 0;
        }

        if(root == p || root == q) {
            return root;
        }

        

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        

        if(left != NULL && right != NULL) {
            return root;
        }

        

        if(left == NULL) {
            return right;
        }

        else {
            return left;
        }
}

/*
Level Order traversal in a binary tree
*/

void BTree::printLevelOrderTraversal() {
	
	printLevelOrderTraversal(root);
}	


void BTree::printLevelOrderTraversal(TreeNode* node) {

	if(root == NULL) {
		return;
	}
	deque<TreeNode *> queue;

	queue.push_back(root);

	while(!queue.empty()) {
	
		node = queue.at(0);
		queue.pop_front();
		cout << node->val << " ";

		if(node->left != NULL) {
			queue.push_back(node->left);
		}
	
		if(node->right != NULL) {
			queue.push_back(node->right);
		}
	}

	cout << endl;
}

/*
Given a binary tree, return the preorder traversal of its nodes' values.
*/

void BTree::iterativePreOrderTraversal() {

	if(root == NULL) {
		return;
	}

	stack<TreeNode *> s1;

	s1.push(root);

	while(!s1.empty()) {
	
		TreeNode* node = s1.top();
		s1.pop();
		cout << node->val << " ";

		if(node->right != NULL) {
			s1.push(node->right);
		}
	
		if(node->left != NULL) {
			s1.push(node->left);
		}
	}

	cout << endl;

}
