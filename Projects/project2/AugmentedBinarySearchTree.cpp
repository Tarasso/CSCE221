#ifndef BinarySearchTree_C
#define BinarySearchTree_C

// Imports
#include <iostream>
#include <cmath>
#include "AugmentedBinarySearchTree.h"

using namespace std;

/**
 * Construct the tree.
 */
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::AugmentedBinarySearchTree() :
root(NULL)
{
	//no code
}


/**
 * Copy constructor.
 */
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::
AugmentedBinarySearchTree(const AugmentedBinarySearchTree<Comparable> & rhs) :
root(NULL)
{
	*this = rhs;
}

/**
 * Destructor for the tree.
 */
template <class Comparable>
AugmentedBinarySearchTree<Comparable>::~AugmentedBinarySearchTree()
{
	makeEmpty();
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::insert(const Comparable & x)
{
	 return insert(x, root);
}

/**
* Remove x from the tree. return 1 on success o.w. return 0
*/
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::remove(const Comparable & x)
{
	return remove(x, root);
}

/**
 * Make the tree logically empty.
 */
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::makeEmpty()
{
	makeEmpty(root);
}


/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
* Does not insert or change m_size of each node if x is a duplicate
*/
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
insert(const Comparable & x, BinaryNode<Comparable> * & t)
{
	int i;
	if (t == NULL) // Creates new node with element x in correct spot
	{
		t = new BinaryNode<Comparable>(x, NULL, NULL, 1);
		return 1;
	}
	else if (x < t->element) // Go left if less than
	{
		i = insert(x, t->left);
	}

	else if (t->element < x) // Go right if greater than
	{
		i = insert(x, t->right);
	}
	else // duplicate
	{
		return 0;
	}


	if(i==0) // if duplicate do nothing
		return 0;
	else // if x was inserted increse m_size of each ancestor
	{
		t->m_size++;
		return 1;
	}

	return -1;
}

/**
 * Internal method to remove from a subtree.
 * x is the item to remove.
 * t is the node that roots the tree.
 * Set the new root.
 * Does not remove node or change m_size of nodes if no node was removed
 */
template <class Comparable>
int AugmentedBinarySearchTree<Comparable>::
remove(const Comparable & x, BinaryNode < Comparable > * & t)
{
	int i;
	if (t == NULL) // node not found
	{
		return 0;
	}
	else if (x < t->element) // Go left if less
	{
		i = remove(x, t->left);
	}

	else if (t->element < x) // Go right if greater
	{
		i = remove(x, t->right);
	}
	else // equal: found node in tree
	{
		if (t->left != NULL && t->right != NULL) // Two children
		{
			t->element = findMin(t->right)->element;
			t->m_size--;
			remove(t->element, t->right);
		}
		else // one child
		{
			BinaryNode <Comparable> *oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
		return 1;
	}

	if(i==0) // if wasnt removed, do nothing
		return 0;
	else // if removed decrement m_size of each ancestor
	{
		t->m_size--;
		return 1;
	}

	return -1;
}


/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <class Comparable>
BinaryNode<Comparable> *
AugmentedBinarySearchTree<Comparable>::findMin(BinaryNode<Comparable> *t) const
{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	return findMin(t->left);
}

/**
 * Internal method to make subtree empty.
 */
template <class Comparable>
void AugmentedBinarySearchTree<Comparable>::
makeEmpty(BinaryNode<Comparable> * & t) const
{
	if (t != NULL)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}


/*
** Boot strap for NthElement
** n is the nth element in the tree
** returns Comparable & (nth element)
*/
template <class Comparable>
const Comparable &
AugmentedBinarySearchTree<Comparable>::NthElement(int n)
{
  if(root == NULL) // handles if tree is empty
		throw NullArgumentException("No nth element for a tree of zero size");
	if(n > root->m_size) // handles if nth element is larger than tree size
	{
		throw ItemNotFound();
	}
	int nodesVisited = 1;
	int* nvPtr = &nodesVisited;
	return NthElement(root,nvPtr,n)->element;
}


/*
** Internal Method for NthElement
** t is the current node to check
** nodesVisited is a pointer to the number of nodes checked
** n is the nth element wanted
** returns the node containing the nth element
*/
template <class Comparable>
BinaryNode<Comparable> *
AugmentedBinarySearchTree<Comparable>::NthElement(BinaryNode<Comparable> *t, int *nodesVisited, int n) const
{
	if(t->left) // if can move left, check left side
	{
		BinaryNode<Comparable> * temp = NthElement(t->left,nodesVisited,n);
		if(temp)
			return temp;
	}
	if(*nodesVisited == n) // check current node
	{
		return t;
	}
	++(*nodesVisited);
	if(t->right) // if can move right, check right side
	{
		BinaryNode<Comparable> * temp = NthElement(t->right,nodesVisited,n);
		if(temp)
			return temp;
	}
	return nullptr;
}

/*
** Boot strap for Rank
** x is the target Comparable to rank
** returns int representing the rank
*/
template <class Comparable>
int
AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x)
{
	if(root == NULL) // handles empty tree
		throw NullArgumentException("The rank for a tree of zero size does not exist");

	int nodesVisited = 0;
	int* nvPtr = &nodesVisited;

	Rank(x,root,nvPtr);

	// Handles is node was not found, either smaller or larger than all nodes currently in tree
	if( (nodesVisited == root->m_size && NthElement(root->m_size) != x)
			|| (nodesVisited == 0 && NthElement(1) != x) )
	{
		throw NodeNotFound(to_string(x));
	}
	return nodesVisited;
}

/*
** Internal method for Rank
** x is the Comparable to rank
** t is the current node to check
** nodesVisited is a pointer the the number of nodes visited
*/
template <class Comparable>
void
AugmentedBinarySearchTree<Comparable>::Rank(const Comparable & x, BinaryNode<Comparable> *t, int *nodesVisited) const
{
	if(t != NULL)
	{
		Rank(x, t->left, nodesVisited); // in order traversal: left, process, right
		// Process
		if(t->element > x) { return; } // Stop counting if already passed where node should have been
		*nodesVisited += 1;
		if(t->element == x) { return; }

		Rank(x,t->right,nodesVisited);
	}
	else // current node t is null
	{
		return;
	}
}

/*
** Method for Median
** returns the Comparable at the median
*/
template <class Comparable>
const Comparable &
AugmentedBinarySearchTree<Comparable>::Median()
{
	if(root == NULL) // handles if tree is empty
		throw NullArgumentException("No median value for a tree of zero size");
	if(root->m_size == 1) // return root if it is the only value
		return root->element;
	int nodesVisited = 1;
	int* nvPtr = &nodesVisited;
	if(root->m_size % 2 == 0) // returns the smaller of the two middles for an even tree
	{
		Comparable & one = NthElement(root, nvPtr, (root->m_size/2)) -> element;
		nodesVisited = 1;
		Comparable & two = NthElement(root, nvPtr, (root->m_size/2)+1) -> element;
		return (one<two)? one : two;
	}
	else // returns the middle of an odd tree
	{
		return NthElement(root, nvPtr, (root->m_size/2)+1) -> element;
	}
}

/*
** Internal helper function to calculate the height of the tree
** t is the node to find the height of
** returns int of the height
*/
template <class Comparable>
int
AugmentedBinarySearchTree<Comparable>::getHeight(BinaryNode<Comparable> *t)
{
	if(t == NULL) { return 0; }
	int leftHeight = getHeight(t->left);
	int rightHeight = getHeight(t->right);
	return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1); // finds the largest of the heights
}

/*
** Bootstrap for IsPerfect
** returns bool for if tree is perfect or not
*/
template <class Comparable>
bool
AugmentedBinarySearchTree<Comparable>::IsPerfect()
{
	if(root == NULL) // handles empty tree
		throw NullArgumentException("Empty tree cannot be perfect");
	if (root->m_size == 1) // returns true if tree is just the root node
	 	return true;
	queue< BinaryNode<Comparable> *> queueNodes;
	queueNodes.push(root);
	int height = getHeight(root);
	return IsPerfect(queueNodes, height);
}

/*
** Internal for IsPerfect
** q is the queue storing BinaryNodes
** height is the max height of the tree
** returns bool is tree is perfect or not
*/
template <class Comparable>
bool
AugmentedBinarySearchTree<Comparable>::IsPerfect(queue <BinaryNode<Comparable> *> q, int height)
{
	int currentLevel = 1;
	int nodesChecked = 0;
	while(q.empty() == false)
	{
		if(nodesChecked == pow(2,currentLevel)-1) // checks if needs to move down to next level
		{
			currentLevel++;
			if(currentLevel-1 == height)
				break;
		}

		BinaryNode<Comparable> * currentNode = q.front();
		q.pop(); // Remove front node from queue

		// check current node

		if(!currentNode->left && !currentNode->right) // at a leaf
		{
			if(currentLevel != height) // identifies a leaf that is not at the bottom level (not perfect)
				return false;
		}
		else // at an internal node
		{
			if(!(currentNode->left && currentNode->right)) // identifies an internal node that does not have two kids (not perfect)
				return false;
		}

		nodesChecked++;

		//Queue both children of the nodes that was just processed
		q.push(currentNode->left);
		q.push(currentNode->right);

	}

	//finished while, without returning false, tree must be perfect
	return true;
}

/*
** Bootstrap for PrintTree
** numlevels is how many of levels the tree should print
** does not return anything, only prints
*/
template <class Comparable>
void
AugmentedBinarySearchTree<Comparable>::PrintLevels(int numlevels)
{
	if(root == NULL) // creates a dummy node to print as root if tree is empty
	{
		insert(0);
	}
	queue< BinaryNode<Comparable> *> queueNodes;
	queueNodes.push(root);
	PrintLevels(queueNodes, numlevels);
}

/*
** Internal for PrintTree
** q is the queue that holds BinaryNodes
** levels is the number of levels to be printed
** does not return anything, only prints
*/
template <class Comparable>
void
AugmentedBinarySearchTree<Comparable>::PrintLevels(queue <BinaryNode<Comparable> *> q, int levels)
{
	int currentLevel = 1;
	int nodesPrinted = 0;
	int nodesPerLine = 0;
	cout << endl << "Level 0:" << endl;
	while(q.empty() == false)
	{
		if(nodesPrinted == pow(2,currentLevel)-1) // checks if needs to move down to next level
		{
			cout << endl << endl;
			currentLevel++;
			nodesPerLine = 0;
			if(currentLevel-1 == levels) // stop if done printing all required levels
				break;
			cout << "Level " << currentLevel-1 << ":" << endl; // else begin printing next level
		}
		BinaryNode<Comparable> * currentNode = q.front();
		q.pop();
		// Print info about current node
		if(currentNode == root) // prints info about root
		{
			if(currentNode->element == NULL) // case of dummy root
				cout << "(NULL, NULL, NULL) ";
			else
				cout << "(" << root->element << ", " << root->m_size << ", NULL)";
		}

		else if(!currentNode->element) // prints info about dummy node
		{
			if(!getParent(currentNode)->element) // if dummy node has dummy parent
				cout << "(NULL, NULL, NULL) ";
			else // if dummy node has real parent
				cout << "(NULL, NULL, " << getParent(currentNode)->element << ") ";
		}

		else // prints info about regular nodes
			cout << "(" << currentNode->element << ", " << currentNode->m_size << ", " << getParent(currentNode)->element << ") ";

		nodesPrinted++;
		nodesPerLine++;

		// moves down a line if 6 nodes have already been printed on a line
		if(nodesPerLine == 6)
		{
			cout << endl;
			nodesPerLine = 0;
		}

		// Queue information about children of current node
		if(currentLevel != levels)
		{
			if(currentNode->left != NULL) // queues left child if not null
			{
				q.push(currentNode->left);
			}
			else // if left child is null queue dummy node
		  {
				BinaryNode<Comparable> * nullNode = new BinaryNode<Comparable>(0,NULL,NULL); // i think 0 is okay
				q.push(nullNode);
				currentNode -> left = nullNode;
			}
			if(currentNode->right != NULL) // queues right child if not null
			{
				q.push(currentNode->right);
			}
			else // if right child is null queue dummy node
		  {
				BinaryNode<Comparable> * nullNode = new BinaryNode<Comparable>(0,NULL,NULL); // i think 0 is okay
				q.push(nullNode);
				currentNode -> right = nullNode;
			}
		}
	}
	cout << endl;
}

/*
** Bootstrap for RemoveResidue
** returns how many dummy nodes were removed
*/
template <class Comparable>
int
AugmentedBinarySearchTree<Comparable>::RemoveResidue()
{
	int nodesDeleted = 0;
	int* ndPtr = &nodesDeleted;
	RemoveResidue(root, ndPtr);
	if(root->element == NULL) // deletes root if it was a dummy node
	{
		delete root;
		nodesDeleted++;
	}
	return nodesDeleted;
}

/*
** Internal for RemoveResidue
** t is the reference to a pointer of the current node
** deletions is a pointer to the number of nodes deleted so far
** does not return anything
*/
template <class Comparable>
void
AugmentedBinarySearchTree<Comparable>::RemoveResidue(BinaryNode<Comparable> * & t, int *deletions)
{
	if (t != NULL)
	{
		RemoveResidue(t->left,deletions); // removes to left
		if(t->left)
		{
			if(t->left->element == NULL) // delete and reset parent pointer if dummy node
			{
				delete t->left;
				t->left = NULL;
				(*deletions) += 1;
			}
		}
		RemoveResidue(t->right,deletions); // removes ro right
		if(t->right)
		{
			if(t->right->element == NULL) // delete and reset parent pointer if dummy node
			{
				delete t->right;
				t->right = NULL;
				(*deletions) += 1;
			}
		}

	}
}

/**
 * Internal method to return the parent of a node.
 * target is a child of the parent node wanted
 * returns a pointer to the parent node
 */
template <class Comparable>
BinaryNode<Comparable> * AugmentedBinarySearchTree<Comparable>::getParent(BinaryNode<Comparable> *target)
{
	return getParent(root,NULL,target);
}

/**
 * Internal method to return the parent of a node.
 * t is the current node
 * parent is the parent of the current node
 * target is the child of the node wanted
 */
template <class Comparable>
BinaryNode<Comparable> * AugmentedBinarySearchTree<Comparable>::getParent(BinaryNode<Comparable> *t, BinaryNode<Comparable> *parent, BinaryNode<Comparable> *target)
{
	if(t->left) // get parent to the left
	{
		BinaryNode<Comparable> * temp = getParent(t->left,t,target);
		if(temp)
			return temp;
	}
	if(t == target) // if current node is the target, return its parent 
	{
		return parent;
	}
	if(t->right) // get parent to the right
	{
		BinaryNode<Comparable> * temp = getParent(t->right,t,target);
		if(temp)
			return temp;
	}
	return nullptr;
}


#endif
