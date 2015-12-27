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

	int min_depth = myTree1->minDepth();

	cout << "Depth = " << min_depth << endl;

/*	BTree* myTree2 = new BTree();

        myTree2->insert(5);
        myTree2->insert(3);
        myTree2->insert(8);
        myTree2->insert(2);
        myTree2->insert(1);
        myTree2->insert(7);
        myTree2->insert(4);
*/
//	myTree1->display();


//	myTree1->printLevelOrderTraversal();	

	return 0;
}
