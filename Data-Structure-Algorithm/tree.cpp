#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

using NodeRef = shared_ptr<struct Node>;


struct Node
{
	Node() {}
	Node(const string& data) : data(data) { }
	
	string			data;
	vector<NodeRef>	children;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("R1 ���߽�");
	{
		NodeRef node = make_shared<Node>("��������");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("���丮");
			node->children.push_back(leaf);
		}
	}
	{
		NodeRef node = make_shared<Node>("���α׷�����");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("Ŭ��");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("����");
			node->children.push_back(leaf);
		}

		{
			NodeRef node = make_shared<Node>("��Ʈ��");
			root->children.push_back(node);
			{
				NodeRef leaf = make_shared<Node>("���");
				node->children.push_back(leaf);
			}
			{
				NodeRef leaf = make_shared<Node>("ĳ����");
				node->children.push_back(leaf);
			}
		}
	}

	return root;
}

void PrintTree(NodeRef root)
{
	cout << root->data << endl;

	for (NodeRef& child : root->children)
		PrintTree(child);
}

//int main()
//{
//	NodeRef root = CreateTree();
//
//	PrintTree(root);
//}