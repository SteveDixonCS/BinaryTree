
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include "DataType.h"

struct Node{
	DataType key;
	Node* left;
	Node* right;
};

class BinaryTree{

	public:
		BinaryTree();
		~BinaryTree();
		void insert(DataType &key);
		void deleteItem(DataType &key);
		void retrieve(DataType &item, bool& found);
		void preOrder() const;
		void inOrder() const;
		void postOrder() const;
		int getLength()const;
		//bonus
		void getSameLevelNonsiblings(DataType &key);
		//added functions and variables
		enum orderType
				{
					INORDER, PREORDER, POSTORDER
				};
		void Destroy(Node* &tree);
		void findInsertionPoint(Node* &tree, DataType item);
		void metaOrder(orderType type,Node* branch) const;
		void deleteItemHelper(Node* &tree, DataType deleteKey, bool& notInTree);
		int getLevel(Node* &tree, DataType item, int level);
		void printLevel(Node* &tree, DataType item, int level);


	private:
		Node* root;
		int length;
};
#endif





/* BINARYTREE_H_ */
