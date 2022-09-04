#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
template<class T>
class BSTNode {
public:
	T val;
	BSTNode* left, * right;
	bool isLeaf() {
		return (this->left == NULL) && (this->right == NULL);
	}
	bool has2child() {
		return this != NULL && left != NULL && right != NULL;
	}
	BSTNode() {
		left = right = NULL;
	}
	BSTNode(T data) {
		val = data;
		left = right = NULL;
	}
	friend ostream& operator<<(ostream& out, const BSTNode& obj) {
		out << obj.val;
		return out;
	}
	~BSTNode() {}
};
template<class T>
class BSTFCI {
	BSTNode<T>* root;
	set<T>v;
public:
	BSTFCI() {
		root = NULL;
	}
	bool empty() { return root == NULL; }
	BSTNode<T>* getRoot() {
		return root;
	}
	T getHead() { return root->val; }
	//function to insert new elements
	BSTNode<T>* insert(BSTNode<T>* root, T el) {
		if (root == NULL) {
			BSTNode<T>* n = new BSTNode<T>(el);
			root = n;
		}
		else if (el < root->val)
			root->left = insert(root->left, el);
		else
			root->right = insert(root->right, el);

		return root;
	}
	//function to insert new elements
	void insert(T el) {
		root = insert(root, el);
	}
	//function to delete element from the tree
	BSTNode<T>* erase(BSTNode<T>* root, T el) {
		if (root == NULL)
			return NULL;
		if (el < root->val)
			root->left = erase(root->left, el);
		else if (el > root->val)
			root->right = erase(root->right, el);
		else {
			if (root->isLeaf()) // leaf BSTNode<T>
				root = NULL;
			else if (!(root->has2child())) {// has one child
				if (root->left) {
					root->val = root->left->val;
					root->left = NULL;
				}
				else {
					root->val = root->right->val;
					root->right = NULL;
				}
			}

			else {	//has two children
				BSTNode<T>* temp = max(root->left);
				root->val = temp->val;
				root->left = erase(root->left, temp->val);
			}
		}
		return root;
	}
	//function to delete element from the tree
	void erase(T el) {
		root = erase(root, el);
	}
	// function to search
	BSTNode<T>* search(T n, BSTNode<T>* root) {
		if (root == NULL)return NULL;
		else if (n == root->val) {
			return root;
		}
		else if (n < root->val) {
			return search(n, root->left);
		}
		else {
			return search(n, root->right);
		}
	}
	bool isfound(T val) {
		BSTNode<T>* temp = search(val, root);
		if (temp == NULL)return 0;
		else return 1;
	}
	// function to get the minimum node in the tree
	BSTNode<T>* min(BSTNode<T>* root) {
		if (empty())return NULL;
		if (root->left == NULL) {
			return root;
		}
		return min(root->left);
	}
	// function to get the minimum value in the tree
	T min() {
		return (min(root))->val;
	}
	// function to get the maximum node in the tree
	BSTNode<T>* max(BSTNode<T>* root) {
		if (empty())return NULL;
		if (root->right == NULL)return root;
		return max(root->right);
	}
	// function to get the maximum value in the tree
	T max() {
		return (max(root))->val;
	}
	// function for printing tree in	 1-pre order	2-in order		3-post order
	void preOrder(BSTNode<T>* root) {// root->left->right
		if (root == NULL)return;
		cout << *root << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	void inOrder(BSTNode<T>* root) {// left->root->right
		if (root == NULL)return;
		inOrder(root->left);
		cout << *root << " ";
		inOrder(root->right);
	}
	void postOrder(BSTNode<T>* root) {
		if (root == NULL)return;
		postOrder(root->left);
		postOrder(root->right);
		cout << *root << " ";

	}
	void print1() {
		preOrder(root);
		cout << endl;
	}
	void print2()
	{
		inOrder(root); cout << endl;
	}
	void print3()
	{
		postOrder(root); cout << endl;
	}
	//helper function to get node height
	int height(BSTNode<T>* root) {
		if (root == NULL)
			return -1;
		else {
			int left_height = height(root->left);
			int right_height = height(root->right);
			return (left_height > right_height ? left_height : right_height) + 1;
		}
	}
	//helper function to get node height
	int height() {
		if (root == NULL)
			return -1;
		return height(root);
	}
	// required function to return tree is balanced or not
	bool isBalanced(BSTNode<T>* root) {
		if (root == NULL)
			return 1;
		int l_height = height(root->left);
		int r_height = height(root->right);
		if (abs(l_height - r_height) <= 1 && isBalanced(root->left) && isBalanced(root->right))
			return 1;

		return 0;
	}
	// required function to return tree is balanced or not
	bool isBalanced() {
		return isBalanced(root);
	}
	// function to print tree elements in Range
	void printRange(int lower, int upper, BSTNode<T>* root) {
		if (root == NULL)
			return;
		if (root->val >= lower && root->val <= upper) {
			v.emplace(root->val);
			printRange(lower, upper, root->left);
			printRange(lower, upper, root->right);
		}
		else if (root->val < lower) {
			printRange(lower, upper, root->right);

		}
		else if (root->val > upper) {
			printRange(lower, upper, root->left);

		}
	}
	// function to print tree elements in Range
	void printRange(int lower, int upper) {
		v.clear();
		printRange(lower, upper, root);
		cout << "[ ";
		for (auto i : v)
			cout << i << " ";
		cout << "]\n";
	}
	BSTNode<T>* Return_node_after_find(T val) {
		BSTNode<T>* temp = search(val, root);
		if (temp == NULL)return 0;
		else return temp;
	}
	~BSTFCI() {}
};
template<class T>
bool Node_subTree(BSTNode<T>* node, BSTNode<T>* node2)
{

	if (node == NULL && node2 == NULL)
		return true;

	if (node == NULL || node2 == NULL)
		return false;

	return (node->val == node2->val &&
		Node_subTree(node->left, node2->left) &&
		Node_subTree(node->right, node2->right));
}
template<class T>
bool is_Sub_Tree(BSTFCI<T>* t1, BSTFCI<T>* t2) {
	if (!(t1->isfound(t2->getRoot()->val)))
		return false;
	if (t2 == NULL)
		return true;
	if (t1 == NULL)
		return false;
	else
		return Node_subTree(t1->Return_node_after_find(t2->getRoot()->val), t2->getRoot());

}

int main() {
	BSTFCI<int> t1, t2, t3, t4, t5,s1,s2,s3,s4,s5;
	cout << "test case #1\n--------------\n";
	t1.insert(5);
	t1.insert(6);
	t1.insert(1);
	t1.insert(10);
	t1.insert(-88);
	t1.insert(-1);
	t1.insert(3);
	t1.insert(8);
	t1.insert(9);
	t1.insert(4);
	t1.insert(7);
	t1.insert(0);
	//t1.print1();
	t1.printRange(0, 800);
	t1.printRange(3, 6);
	t1.printRange(7, 7);
	t1.printRange(1, 3);
	t1.printRange(8, 10);
	cout << (t1.isBalanced() ? "Balanced tree\n" : "Unbalanced tree");
	cout << "\n---------------------------------------\n\n";
	cout << "test case #2\n--------------\n";
	t2.insert(5);
	t2.insert(7);
	t2.insert(6);
	t2.insert(3);
	t2.insert(1);
	t2.insert(4);
	t2.printRange(5, 7);
	t2.printRange(10, 15);
	t2.printRange(1, 7);
	t2.printRange(3, 4);
	t2.printRange(8, 10);
	cout << (t2.isBalanced() ? "Balanced tree\n" : "Unbalanced tree");
	cout << "\n---------------------------------------\n\n";
	cout << "test case #3\n--------------\n";
	t3.insert(1);
	t3.insert(2);
	t3.insert(3);
	t3.insert(4);
	t3.insert(0);
	t3.insert(5);
	t3.insert(8);
	t3.printRange(5, 7);
	t3.printRange(10, 15);
	t3.printRange(1, 7);
	t3.printRange(3, 4);
	t3.printRange(8, 10);
	cout << (t3.isBalanced() ? "Balanced tree\n" : "Unbalanced tree");
	cout << "\n---------------------------------------\n\n";
	cout << "test case #4\n--------------\n";
	t4.insert(10);
	t4.insert(1);
	t4.insert(0);
	t4.insert(8);
	t4.insert(12);
	t4.insert(5);
	t4.insert(6);
	t4.printRange(5, 7);
	t4.printRange(10, 15);
	t4.printRange(1, 4);
	t4.printRange(3, 8);
	t4.printRange(8, 13);
	cout << (t4.isBalanced() ? "Balanced tree\n" : "Unbalanced tree");
	cout << "\n---------------------------------------\n\n";
	cout << "test case #5\n--------------\n";
	t5.insert(3);
	t5.insert(0);
	t5.insert(8);
	t5.insert(7);
	t5.insert(9);
	t5.insert(-1);
	t5.insert(2);
	t5.insert(3);
	t5.insert(8);
	t5.printRange(-5, 7);
	t5.printRange(10, 15);
	t5.printRange(1, 4);
	t5.printRange(2, 8);
	t5.printRange(8, 10);
	cout << (t5.isBalanced() ? "Balanced tree\n" : "Unbalanced tree");
	cout << "\n---------------------------------------\n\n";
	
	cout << "SubTree Test cases:" << endl << "~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Test 1:" <<endl<< "~~~~~~~" << endl;
	s1.insert(10);
	s1.insert(8);
	s1.insert(7);
	s1.insert(9);

	if (is_Sub_Tree(&t1, &s1))
		cout << "it is a sub tree:  True "<<endl<<endl;
	else
		cout << "it is not a sub tree:  False"<<endl<<endl;

	cout << "Test 2:" << endl << "~~~~~~~" << endl;
	s2.insert(3);
	s2.insert(4);
	s2.insert(1);

	if (is_Sub_Tree(&t2, &s2))
		cout << "it is a sub tree:  True " << endl<<endl;
	else
		cout << "it is not a sub tree:  False" << endl << endl;

	cout << "Test 3:" << endl << "~~~~~~~" << endl;
	s3.insert(4);
	s3.insert(3);
	s3.insert(5);

	if (is_Sub_Tree(&t3, &s3))
		cout << "it is a sub tree:  True " << endl << endl;
	else
		cout << "it is not a sub tree:  False" << endl << endl;

	cout << "Test 4:" << endl << "~~~~~~~" << endl;
	s4.insert(10);
	s4.insert(1);
	s4.insert(12);

	if (is_Sub_Tree(&t4, &s4))
		cout << "it is a sub tree:  True " << endl << endl;
	else
		cout << "it is not a sub tree:  False" << endl << endl;

	cout << "Test 5:" << endl << "~~~~~~~" << endl;
	s5.insert(8);
	s5.insert(9);
	s5.insert(7);
	s5.insert(8);
	s5.insert(3);

	if (is_Sub_Tree(&t5, &s5))
		cout << "it is a sub tree:  True " << endl << endl;
	else
		cout << "it is not a sub tree:  False" << endl << endl;
}