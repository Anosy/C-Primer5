#include<iostream>
#include<string>

using namespace std;

class TreeNode
{
public:
	TreeNode() :value(""), count(1), left(nullptr), right(nullptr){}
	void CopyTree(void)
	{
		if (left)
		{
			left->CopyTree();
		}
		if (right)
		{
			right->CopyTree();
		}
		count++;
	}
	TreeNode(const TreeNode &tn):value(tn.value), count(1), left(tn.left), right(tn.right)
	{
		if (left)
		{
			left->CopyTree();
		}
		if (right)
		{
			right->CopyTree();
		}
	}

private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree() :root(nullptr) {}
	BinStrTree(const BinStrTree &bst) :root(bst.root)
	{
		root->CopyTree();
	}
	
private:
	TreeNode *root;
};