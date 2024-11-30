#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace treeNS
{
	struct Node 
    {
    	int data;
        Node *left;
        Node *right;
        Node()
        {
        	data = 0;
            left = nullptr;
            right = nullptr;
        }
    };
    class tree
    {
    	private:
        	Node *root;
        public:
        	tree()
            {
            	root = nullptr;
                cout<<"Tree object created"<<endl;
            }
            ~tree()
            {
            	cout<<"Tree object deleted"<<endl;
            }
        	Node* create_node(int data);
            void insert_node(int data);
            void inorder_traversal(Node *node);
            void preorder_traversal(Node *node);
            void postorder_traversal(Node *node);
            Node *get_root_node();
            void inorder_traversal_without_recursion(Node *node);
            void preorder_traversal_without_recursion(Node *node);
            void postorder_traversal_without_recursion(Node *node);
    };
}
