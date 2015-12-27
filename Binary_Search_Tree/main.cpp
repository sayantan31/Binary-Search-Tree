#include<iostream>
#include "bst.h"

using namespace std;

int main() {

	BTree* myTree1 = new BTree();

	myTree1->insert(20);
	myTree1->insert(10);
	myTree1->insert(30);
	myTree1->insert(5);
	myTree1->insert(15);


	myTree1->iterativePreOrderTraversal();

	return 0;
}
