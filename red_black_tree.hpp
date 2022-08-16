/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:54:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/16 04:59:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <cstddef>
#include <iostream>

enum COLOR
{
	RED, BLACK
};

template <class Pair, class Allocator>
class Node
{
	public:

		Allocator				allocator;
		Pair					*value;
		Node<Pair, Allocator>	*left;
		Node<Pair, Allocator>	*right;
		Node<Pair, Allocator>	*parent;
		COLOR					color;

		Node<Pair, Allocator>(const Pair & val, Allocator alloc) :
			allocator(alloc),
			left(NULL),
			right(NULL),
			parent(NULL),
			color(RED)
		{
			value = allocator.allocate(1);
			allocator.construct(value, val);
			return ;
		};

		~Node<Pair, Allocator>(void)
		{
			allocator.deallocate(value, 1);
			return ;
		};

		Node<Pair, Allocator> *uncle(void) const
		{
			if (parent == NULL || parent->parent == NULL)
				return NULL;
			if (parent->isOnLeft())
				return (parent->parent->right);
			else
				return (parent->parent->left);
		}

		bool isOnLeft(void) const
		{
			return (this == parent->left);
		}

		Node<Pair, Allocator> *sibling(void) const
		{
			if (parent == NULL)
				return (NULL);
			if (isOnLeft())
				return (parent->right);
			return (parent->left);
		}

		// moves node down and moves given node in its place
		void moveDown(Node<Pair, Allocator> *nParent)
		{
			if (parent != NULL)
			{
				if (isOnLeft())
					parent->left = nParent;
				else
					parent->right = nParent;
			}
			nParent->parent = parent;
			parent = nParent;
		}

		bool hasRedChild() const
		{
			return (left != NULL && left->color == RED) ||
				(right != NULL && right->color == RED);
		}
};

template <class Key, class Pair, class Allocator>
class RBTree
{

	Node<Pair, Allocator>	*root;
	Allocator				_alloc;

	// left rotates the given node
	void leftRotate(Node<Pair, Allocator> *x)
	{
		// new parent will be node's right child
		Node<Pair, Allocator> *nParent = x->right;

		// update root if current node is root
		if (x == root)
			root = nParent;

		x->moveDown(nParent);

		// connect x with new parent's left element
		x->right = nParent->left;
		// connect new parent's left element with node
		// if it is not null
		if (nParent->left != NULL)
			nParent->left->parent = x;

		// connect new parent with x
		nParent->left = x;
	}

	void rightRotate(Node<Pair, Allocator> *x)
	{
		// new parent will be node's left child
		Node<Pair, Allocator> *nParent = x->left;

		// update root if current node is root
		if (x == root)
			root = nParent;

		x->moveDown(nParent);

		// connect x with new parent's right element
		x->left = nParent->right;
		// connect new parent's right element with node
		// if it is not null
		if (nParent->right != NULL)
			nParent->right->parent = x;

		// connect new parent with x
		nParent->right = x;
	}

	void swapColors(Node<Pair, Allocator> *x1, Node<Pair, Allocator> *x2)
	{
		COLOR tmp;
		tmp = x1->color;
		x1->color = x2->color;
		x2->color = tmp;
	}

	void swapValues(Node<Pair, Allocator> *u, Node<Pair, Allocator> *v)
	{
		Pair tmp;
		tmp = ft::make_pair<typename Pair::first_type, typename Pair::second_type>(u->value->first, u->value->second);
		u->value = v->value;
		*(v->value) = tmp;
	}

	// fix red red at given node
	void fixRedRed(Node<Pair, Allocator> *x)
	{
		// if x is root color it black and return
		if (x == root)
		{
			x->color = BLACK;
			return;
		}

		// initialize parent, grandparent, uncle
		Node<Pair, Allocator> *parent = x->parent, *grandparent = parent->parent,
			 *uncle = x->uncle();

		if (parent->color != BLACK)
		{
			if (uncle != NULL && uncle->color == RED)
			{
				// uncle red, perform recoloring and recurse
				parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				fixRedRed(grandparent);
			}
			else
			{
				// Else perform LR, LL, RL, RR
				if (parent->isOnLeft())
				{
					if (x->isOnLeft())
					{
						// for left right
						swapColors(parent, grandparent);
					}
					else
					{
						leftRotate(parent);
						swapColors(x, grandparent);
					}
					// for left left and left right
					rightRotate(grandparent);
				}
				else
				{
					if (x->isOnLeft())
					{
						// for right left
						rightRotate(parent);
						swapColors(x, grandparent);
					}
					else
					{
						swapColors(parent, grandparent);
					}

					// for right right and right left
					leftRotate(grandparent);
				}
			}
		}
	}

	// find node that do not have a left child
	// in the subtree of the given node
	Node<Pair, Allocator> *successor(Node<Pair, Allocator> *x)
	{
		Node<Pair, Allocator> *tmp = x;

		while (tmp->left != NULL)
			tmp = tmp->left;
		return tmp;
	}

	// find node that replaces a deleted node in BST
	Node<Pair, Allocator> *BSTreplace(Node<Pair, Allocator> *x)
	{
		// when node have 2 children
		if (x->left != NULL and x->right != NULL)
			return successor(x->right);

		// when leaf
		if (x->left == NULL and x->right == NULL)
			return NULL;

		// when single child
		if (x->left != NULL)
			return x->left;
		else
			return x->right;
	}

	// deletes the given node
	void deleteNode(Node<Pair, Allocator> *v)
	{
		Node<Pair, Allocator> *u = BSTreplace(v);

		// True when u and v are both black
		bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
		Node<Pair, Allocator> *parent = v->parent;

		if (u == NULL)
		{
			// u is NULL therefore v is leaf
			if (v == root)
			{
				// v is root, making root null
				root = NULL;
			}
			else
			{
				if (uvBlack)
				{
					// u and v both black
					// v is leaf, fix double black at v
					fixDoubleBlack(v);
				}
				else
				{
					// u or v is red
					if (v->sibling() != NULL)
						// sibling is not null, make it red"
						v->sibling()->color = RED;
				}

				// delete v from the tree
				if (v->isOnLeft())
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}
			delete v;
			return;
		}

		if (v->left == NULL or v->right == NULL)
		{
			// v has 1 child
			if (v == root)
			{
				// v is root, assign the valueue of u to v, and delete u
				v->value = u->value;
				v->left = v->right = NULL;
				delete u;
			}
			else
			{
				// Detach v from tree and move u up
				if (v->isOnLeft())
				{
					parent->left = u;
				}
				else
				{
					parent->right = u;
				}
				delete v;
				u->parent = parent;
				if (uvBlack)
				{
					// u and v both black, fix double black at u
					fixDoubleBlack(u);
				}
				else
				{
					// u or v red, color u black
					u->color = BLACK;
				}
			}
			return;
		}

		// v has 2 children, swap valueues with successor and recurse
		swapValues(u, v);
		deleteNode(u);
	}

	void fixDoubleBlack(Node<Pair, Allocator> *x)
	{
		if (x == root)
			// Reached root
			return;

		Node<Pair, Allocator> *sibling = x->sibling(), *parent = x->parent;

		if (sibling == NULL)
		{
			// No sibiling, double black pushed up
			fixDoubleBlack(parent);
		}
		else
		{
			if (sibling->color == RED)
			{
				// Sibling red
				parent->color = RED;
				sibling->color = BLACK;
				if (sibling->isOnLeft())
				{
					// left case
					rightRotate(parent);
				}
				else
				{
					// right case
					leftRotate(parent);
				}
				fixDoubleBlack(x);
			}
			else
			{
				// Sibling black
				if (sibling->hasRedChild())
				{
					// at least 1 red children
					if (sibling->left != NULL and sibling->left->color == RED)
					{
						if (sibling->isOnLeft())
						{
							// left left
							sibling->left->color = sibling->color;
							sibling->color = parent->color;
							rightRotate(parent);
						}
						else
						{
							// right left
							sibling->left->color = parent->color;
							rightRotate(sibling);
							leftRotate(parent);
						}
					}
					else
					{
						if (sibling->isOnLeft())
						{
							// left right
							sibling->right->color = parent->color;
							leftRotate(sibling);
							rightRotate(parent);
						}
						else
						{
							// right right
							sibling->right->color = sibling->color;
							sibling->color = parent->color;
							leftRotate(parent);
						}
					}
					parent->color = BLACK;
				}
				else
				{
					// 2 black children
					sibling->color = RED;
					if (parent->color == BLACK)
						fixDoubleBlack(parent);
					else
						parent->color = BLACK;
				}
			}
		}
	}


	public :
		
		// constructor
		// initialize root
		RBTree(void)
		{
			root = NULL;
		}

		Node<Pair, Allocator> *getRoot(void)
		{
			return (root);
		}

		// searches for given valueue
		// if found returns the node (used for delete)
		// else returns the last node while traversing (used in insert)
		Node<Pair, Allocator> *search(Key n)
		{
			Node<Pair, Allocator> *tmp = root;

			while (tmp != NULL)
			{
				if (n < tmp->value->first)
				{
					if (tmp->left == NULL)
						break;
					else
						tmp = tmp->left;
				}
				else if (n == tmp->value->first)
				{
					break;
				}
				else
				{
					if (tmp->right == NULL)
						break;
					else
						tmp = tmp->right;
				}
			}
			return tmp;
		}

		// inserts the given valueue to tree
		void insert(const Pair & n)
		{
			Node<Pair, Allocator> *newNode = new Node<Pair, Allocator>(n, _alloc);
			
			if (root == NULL)
			{
				// when root is null
				// simply insert valueue at root
				newNode->color = BLACK;
				root = newNode;
			}
			else
			{
				Node<Pair, Allocator> *tmp = search(n.first);

				// not sure here was :
				// if (tmp->value == n)
				if (tmp->value->first == n.first)
				{
					// return if valueue already exists
					return;
				}

				// if valueue is not found, search returns the node
				// where the valueue is to be inserted

				// connect new node to correct node
				newNode->parent = tmp;

				if (n.first < tmp->value->first)
					tmp->left = newNode;
				else
					tmp->right = newNode;

				// fix red red voilaton if exists
				fixRedRed(newNode);
			}
		}

		// utility function that deletes the node with given valueue
		void deleteByVal(typename Pair::first_type n)
		{
			// check if the tree is not empty
			if (root == NULL)
				return;

			// find the node
			Node<Pair, Allocator> *v = search(n);
			if (v->value->first != n)
				return ;

			// delete it
			deleteNode(v);
		}

};


#endif
