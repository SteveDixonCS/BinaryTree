#include "DataType.h"
#include "BinaryTree.h"
#include <cstddef>
#include <iostream>

BinaryTree::BinaryTree()
{
	root = NULL;
	length = 0;
}

BinaryTree::~BinaryTree()
{

 if(root == NULL)//if no tree to de-construct
 {
	 return;
 }
 else
 {
	Destroy(root);
 }
}
void BinaryTree::Destroy(Node* &tree)
{
	if(tree != NULL)
	{
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}

void BinaryTree::findInsertionPoint(Node* &tree, DataType item)
//Finds insertion location and puts item into tree
{
	if(tree == NULL)
	{//insertion place found
		tree = new Node;
		tree->right = NULL;
		tree->left = NULL;
		tree->key = item;
		length++;
	}
	else if(item.getValue() < tree->key.getValue())
	{
		findInsertionPoint(tree->left, item);//left subtree
	}
	else if(item.getValue() > tree->key.getValue())
	{
		findInsertionPoint(tree->right, item);//right subtree
	}
	else//if equal do not insert
	{
		std::cout<<"ITEM ALREADY IN TREE"<<std::endl<<std::endl;
	}
}

void BinaryTree::insert(DataType &insertKey)
{
	//Calls the recursive function "findInsertionPoint" to insert item into tree
	findInsertionPoint(root,insertKey);
}

void BinaryTree::deleteItemHelper(Node* &tree, DataType deleteKey, bool& notInTree)
{
		if(deleteKey.getValue() < tree->key.getValue() && (!notInTree))
		{
			if(tree->left != NULL)//more search space
				deleteItemHelper(tree->left, deleteKey, notInTree);//look in left subtree
			else
				notInTree = true;
		}
		else if(deleteKey.getValue() > tree->key.getValue() && (!notInTree))
		{
			if(tree->right != NULL)//more search space
				deleteItemHelper(tree->right, deleteKey, notInTree);//look in right subtree
			else
				notInTree = true;
		}
		else if(deleteKey.getValue() == tree->key.getValue() && (!notInTree))//node found
		{
			DataType info;
			Node* temp;
			temp = tree;

			if(tree->left == NULL)//has right child or no children
			{
				tree = tree->right;
				delete temp;
				length--;
			}
			else if(tree->right == NULL)//has left child
			{
				tree = tree->left;
				delete temp;
				length--;
			}
			else//has two children
			{
				//find predecessor
				temp = temp->left;
				while(temp->right != NULL)
				{
					temp = temp->right;
				}
				info = temp->key;//sets info to the DT of the right most node
				tree->key = info;
				if(tree->left != NULL)
				{
					deleteItemHelper(tree->left, info, notInTree);
					length--;
				}
				else
				{
					std::cout<<"ERROR COULD NOT DELETE"<<std::endl;
				}
			}
		}
}

void BinaryTree::deleteItem(DataType &deleteKey)
{
	bool notInTree = false;
	//calls the recursive function to delete item from tree
	deleteItemHelper(root, deleteKey, notInTree);
}

void BinaryTree::retrieve(DataType &item, bool& found)
{
	Node* location = BinaryTree::root;

	while(found == false && location != NULL)
	{
		if(item.getValue() < (location->key).getValue())
		{
			location = location->left;
			if(location != NULL)
			{
				found = ((location->key).getValue() == item.getValue());
			}
			else //no more locations to search therefore not in tree
			{
				break;
			}
		}
		else if(item.getValue() > (location->key).getValue())
		{
			location = location->right;
			if(location != NULL)
			{
				found = ((location->key).getValue() == item.getValue());
			}
			else//no more locations to search therefore not in tree
			{
				break;
			}
		}
	}
	return;
}

void BinaryTree::metaOrder(orderType type,Node* branch) const
{
	//prints each order according to the value given in an enum called orderType
	switch(type)
	{
		case INORDER:
			if(branch != NULL)
			{
				metaOrder(INORDER, branch->left);
				std::cout<< (branch->key).getValue()<< " ";
				metaOrder(INORDER, branch->right);
			}

			break;
		case PREORDER:
			if(branch != NULL)
			{
				std::cout<< (branch->key).getValue()<< " ";
				metaOrder(PREORDER, branch->left);
				metaOrder(PREORDER, branch->right);
			}
			break;
		case POSTORDER:
			if(branch != NULL)
			{
				metaOrder(POSTORDER, branch->left);
				metaOrder(POSTORDER, branch->right);
				std::cout<< (branch->key).getValue()<< " ";
			}
			break;
	}
}

void BinaryTree::preOrder() const
{
	//calls recursive function "metaOrder" with appropriate parameters
	metaOrder(PREORDER,root);
}

void BinaryTree::inOrder() const
{
	//calls recursive function "metaOrder" with appropriate parameters
	metaOrder(INORDER,root);
}

void BinaryTree::postOrder()const
{
	//calls recursive function "metaOrder" with appropriate parameters
	metaOrder(POSTORDER,root);
}

int BinaryTree::getLength()const
{
	//returns length of tree
	return BinaryTree::length;
}
//bonus
void BinaryTree::getSameLevelNonsiblings(DataType &key)
{
	bool found;
	int nodeLevel;

	retrieve(key,found);//check if in tree
	if(found)//if in tree
	{
		nodeLevel = getLevel(root,key,1);
		std::cout<<"LEVEL OF "<<key.getValue()<<" IS: "<< nodeLevel<<std::endl;
		if(nodeLevel >= 2)//level 2 or greater
		{
			printLevel(root, key, nodeLevel);
		}
		else//no need to search for nodes lower that level 2
		{
			std::cout<<"NO SAME LEVEL NON SIBLINGS FOUND"<<std::endl;
		}
	}
	else
	{
		std::cout<<"ITEM NOT IN TREE"<<std::endl;
	}
}
//return level of node
int BinaryTree::getLevel(Node* &tree, DataType item, int level)
{

	if(tree == NULL)//tree is empty
	{
		return 0;
	}

	if(tree->key.getValue() == item.getValue())//found node
	{
		return level;
	}
	//recursive function to find level of node repeatedly checks left subtree and right subtree
	int lowerLevel = getLevel(tree->left, item, level+1);
		if(lowerLevel != 0)//not root
			return lowerLevel;
		return getLevel(tree->right,item,level +1);
}
void BinaryTree::printLevel(Node* &tree, DataType item, int level)
{
	if (tree == NULL || level < 2)//no need to print same level non siblings
		return;

	if (level == 2)
	    {
	        if (tree->left != NULL) //look left
	        {
	        	if((tree->left->key).getValue() == item.getValue())
	        	{
	        		return;
	        	}
	        	else
	        		std::cout<<(tree->left->key).getValue()<<" ";
	        }
	        if (tree->right != NULL)//look right
	        {
	        	if ((tree->right->key).getValue() == item.getValue())
	        	{
	        		return;
	        	}
	        	else
	        		std::cout<<(tree->right->key).getValue()<<" ";
	        }
	    }

	 else if (level > 2)
	    {
		 	 if(tree->left != NULL)
		 	 {
		 		 printLevel(tree->left, item, level-1);
		 	 }
		 	if(tree->right != NULL)
		 	{
		 		printLevel(tree->right, item, level-1);
		 	}
	    }
}
