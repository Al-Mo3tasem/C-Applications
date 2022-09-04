#include<string>
#include<cstdlib>
#include<iomanip>
#include <cassert>
#include<iostream>
#include<vector>
using namespace std;
struct Node_type
{
	int  Node_item;
	Node_type* R;
	Node_type* L;
};
struct Node_type* newNode(int data)
{
	struct Node_type* temp = new struct Node_type;
	temp->Node_item = data;
	temp->L = temp->R = NULL;
	return temp;
}
class Tree
{
private:
	Node_type* Root=NULL;
	
public:
	

	bool isItEmpty();
	void add_element(int);
	void inorder(Node_type* node);
	void preorder(Node_type* node);
	void postorder(Node_type* node);
	void inorder_Traversal();
	void preorder_Traversal();
	void postorder_Traversal();
	void Flipper(Node_type* node);
	Tree();
	Node_type* get_Root() {
		return Root;
	}
	int flag=0;
	void Reset_flag() {
		flag = 0;
	}
};
Tree::Tree()
{
	Root = NULL;
}
bool Tree::isItEmpty()
{
	return (Root == NULL);
}
void Tree::preorder_Traversal()
{
	preorder(Root);
	cout << endl;
}
void Tree::inorder_Traversal()
{
	inorder(Root);
	cout << endl;
}
void Tree::postorder_Traversal()
{
	postorder(Root);
	cout << endl;
}
void Tree::preorder(Node_type* node)
{
	if (node != NULL)
	{
		cout << node->Node_item << " ";
		preorder(node->L);
		preorder(node->R);
	}
}

void Tree::inorder(Node_type* node)
{
	if (node != NULL)
	{
		inorder(node->L);
		cout << node->Node_item << " ";
		inorder(node->R);
	}
}

void Tree::postorder(Node_type* node)
{
	if (node != NULL)
	{
		postorder(node->L);
		postorder(node->R);
		cout << node->Node_item << " ";
	}
}

void Tree::add_element(int nodeItem)
{
	Node_type* Current_Node;  
	Node_type* Trial_current= NULL; 
	Node_type* New_Node;  

	New_Node = new Node_type;
	assert(New_Node != NULL);
	New_Node->Node_item = nodeItem;
	New_Node->L = NULL;
	New_Node->R = NULL;

	if (Root == NULL)
		Root = New_Node;
	else
	{
		Current_Node = Root;

		while (Current_Node != NULL)
		{
			Trial_current = Current_Node;

			if (Current_Node->Node_item == nodeItem)
			{
				cout << "The inserted item "<< '"'<<nodeItem<<'"'<<" is already in the list! ";
				cout << "Duplicates are not allowed!" << endl;
				return;
			}
			else
				if (Current_Node->Node_item > nodeItem)
					Current_Node = Current_Node->L;
				else
					Current_Node = Current_Node->R;
		}
		if (Trial_current->Node_item > nodeItem)
			Trial_current->L = New_Node;
		else
			Trial_current->R = New_Node;
	}
}
Node_type n2 = { -999900,NULL,NULL };
Node_type* n1=&n2;
void Tree::Flipper(Node_type* node = n1)
{
	if (node == n1 && flag == 0) {
		node = Root;
		flag = 1;
	}
	
	if (node == NULL) {
		if (flag == 0) {
			cout << "No such a node in the tree!" << endl<<"Tree will remain as it is"<<endl;
		}
		return;
	}
	else
	{
		flag = 1;
	    Node_type* temp;
		/*Recursion for each subtree*/
		Flipper(node->L);
		Flipper(node->R);

		/*Lets swap L&R pointers for each single node*/
		temp = node->L;
		node->L = node->R;
		node->R = temp;
	}
}

int main()
{
	//   First, Let's build a tree
	Tree A;
	A.add_element(22);
	A.add_element(19);
	A.add_element(30);
	A.add_element(10);
	A.add_element(20);
	A.add_element(25);
	A.add_element(50);
	A.add_element(6);
	cout << "Our Tree:" <<endl<< "~~~~~~~~~" << endl;
	A.inorder_Traversal();
    //A.postorder_Traversal();
	//A.preorder_Traversal();
	cout << "-----------------------" << endl << endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	// Test case #1 // Flip te tree from the root by not passing a parameter
	cout << "Test Case #1" << endl << "~~~~~~~~~~~~"<<endl;
	A.Flipper();
	A.inorder_Traversal();
	A.Reset_flag();
	// reset the tree:
	A.Flipper();
	A.Reset_flag();
	cout << "-----------------------" << endl << endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	// Test Case #2 // Flip te tree from the left side of the root
	cout << "Test Case #2" << endl << "~~~~~~~~~~~~" << endl;
	A.Flipper(A.get_Root()->L);
	A.inorder_Traversal();
	A.Reset_flag();
	// reset the tree:
	A.Flipper(A.get_Root()->L);
	A.Reset_flag();
	cout << "-----------------------" << endl << endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	// Test Case #3 // Flip te tree from the Right side of the root
	cout << "Test Case #3" << endl << "~~~~~~~~~~~~" << endl;
	A.Flipper(A.get_Root()->R);
	A.inorder_Traversal();
	A.Reset_flag();
	// reset the tree:
	A.Flipper(A.get_Root()->R);
	A.Reset_flag();
	cout << "-----------------------" << endl << endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	// Test Case #4 // Flip te tree from ine of the leaves "Nothing will change"
	cout << "Test Case #4" << endl << "~~~~~~~~~~~~" << endl;
	A.Flipper(A.get_Root()->R->L);
	A.inorder_Traversal();
	A.Reset_flag();
	// reset the tree:
	A.Flipper(A.get_Root()->R->L);
	A.Reset_flag();
	cout << "-----------------------" << endl << endl;
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		// Test Case #5 // Trying to flip the tree from not existing node
	cout << "Test Case #5" << endl << "~~~~~~~~~~~~" << endl;
	A.Flipper(A.get_Root()->L->R->L);
	A.inorder_Traversal();
	A.Reset_flag();
	// reset the tree:
	A.Reset_flag();
	cout << "-----------------------" << endl << endl;

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	return 0;
}






