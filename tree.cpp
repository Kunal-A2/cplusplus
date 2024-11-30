#include "tree.h"

namespace treeNS
{
    Node* tree::get_root_node() 
    {
    	return root;
    }
    Node* tree::create_node(int data)
    {
    	Node *node = new Node();
        node->data = data;
        return node;
    }
    void tree::insert_node(int data)
    {
    	if(root == nullptr)
        {
        	root = tree::create_node(data);
            cout<<"First Node added root->data = "<<root->data<<endl;
        }
        else
        {
        	Node *n_ptr = root;
            while(n_ptr != nullptr)
            {
            	if (n_ptr->data > data)
                {
                    if(n_ptr->left != nullptr)
                    {
                        n_ptr = n_ptr->left;
                    }
                    else
                    {
                        n_ptr->left = tree::create_node(data);
                        break;   
                    }
                }
                if (n_ptr->data <= data)
                {
                    if(n_ptr->right != nullptr)
                    {
                        n_ptr = n_ptr->right;
                    }
                    else
                    {
                        n_ptr->right = tree::create_node(data);
                        break;   
                    }
                }
            }	
        }
    }
    void tree::inorder_traversal(Node *node)
    {
        if(node == nullptr)
        	return;
        tree::inorder_traversal(node->left);
        cout<<" "<<node->data;
        tree::inorder_traversal(node->right);
    }
    void tree::preorder_traversal(Node *node)
    {
    	if(node == nullptr)
        	return;
        cout<<" "<<node->data;
        tree::preorder_traversal(node->left);
        tree::preorder_traversal(node->right);
    }
    void tree::postorder_traversal(Node *node)
    {
    	if(node == nullptr)
        	return;
        tree::postorder_traversal(node->left);
        tree::postorder_traversal(node->right);
        cout<<" "<<node->data;
    }
    void tree::inorder_traversal_without_recursion(Node *node)
    {
    	stack<Node*> s_obj;
        Node *current= node;
        cout<<"Inorder WR: ";
        while(current != nullptr ||  !s_obj.empty() )
        {
        	while(current != nullptr)
            {
            	s_obj.push(current);
            	current = current->left;
            }
            current = s_obj.top();
            s_obj.pop();
            cout<<" "<<current->data;
            current = current->right;
        }
        cout<<endl;
    }
    void tree::preorder_traversal_without_recursion(Node *node)
    {
    	stack<Node*> s_obj; 
        Node *current = node;
        cout<<"Preorder WR: ";
        while(current != nullptr ||  !s_obj.empty() )
        {
        
        	while(current != nullptr)
            {
            	cout<<" "<<current->data;
                if(current->right != nullptr)
                {
                	s_obj.push(current->right);
                }
            	current = current->left;
            }
            if(!s_obj.empty())
            {
            	current = s_obj.top();
            	s_obj.pop();
            }
        }
        cout<<endl;
    }
    void tree::postorder_traversal_without_recursion(Node *node)
    {
    	// 20, 10, 30, 60, 70, 50 , 40
        stack<Node*> s_obj;
    	Node* current = node;
        stack<Node*> s1;
        stack<Node*> s2;
        s1.push(root);
        Node* lastVistitedNode = nullptr;
        
    	cout<<"Postorder WR, using single stack: ";
        while(current != nullptr || !s_obj.empty())
        {
        	if(current != nullptr)
            {
            	s_obj.push(current);
                current = current->left;
            }
            else
            {
            	Node* temp = s_obj.top();
                if(temp->right != nullptr && lastVistitedNode != temp->right)
                {
                    current = temp->right;
                }
                else
                {
                    cout<<temp->data<<" ";
                    lastVistitedNode = temp;
                    s_obj.pop();
                }
            }
        }
        cout<<endl;
        
        cout<<"Postorder WR, using two stack: ";
        while(!s1.empty())
        {
        	Node *temp = s1.top();
        	s2.push(temp);
            s1.pop();
            if(temp->left)
            	s1.push(temp->left);
            if(temp->right)
            	s1.push(temp->right);
        }
        while(!s2.empty())
        {
        	cout<<" "<<s2.top()->data;
            s2.pop();
        }
        cout<<endl;
    }
}