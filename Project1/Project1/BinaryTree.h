#pragma once

#include<string>
#include<vector>

template<class T>
struct BNode
{
	T data;
	BNode* leftNode = NULL;
	BNode* rightNode = NULL;
};

template<class T>
class BinaryTree
{
public:

	BinaryTree();
	virtual ~BinaryTree();

protected:

	void pre_Order(BNode<T> * t);
	void in_Order(BNode<T> * t);
	void post_Order(BNode<T> * t);
	void get_Height(BNode<T> *t, int h);
	void insert(BNode<T>* &t, T &value);
	BNode<T>* find(BNode<T>*t,T value);

	BNode<T>* create(std::vector<T>& vec, int&pos);//前序构造
	BNode<T>* getSuccessor(BNode<T>* &delNode);

public:

	void createBiTree(std::vector<T> vec);
	void preOrder();//前序遍历
	void inOrder();//中序遍历

	void Insert(T t);
	BNode<T>* Find(T t);
	void DelNode(T t);

protected:

	BNode<T> *	root = NULL;
	int			m_nHeight = 0;

};

template<class T>
inline BinaryTree<T>::BinaryTree()
{
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
}


template<class T>
inline void BinaryTree<T>::pre_Order(BNode<T>* t)
{
	if (!t)
		return;
	else
		std::cout << t->data << " ";

	pre_Order(t->leftNode);
	pre_Order(t->rightNode);
}

template<class T>
inline void BinaryTree<T>::in_Order(BNode<T>* t)
{
	if (!t)
		return;
	else
	{
		in_Order(t->leftNode);
		std::cout << t->data << " ";
		in_Order(t->rightNode);
	}
	
}

template<class T>
inline void BinaryTree<T>::post_Order(BNode<T>* t)
{
}

template<class T>
inline BNode<T> * BinaryTree<T>::create(std::vector<T> &vec, int & pos)
{
	pos++;
	BNode<T>*t;
	if (pos>=vec.size())
	{
		return NULL;
	}
	else
	{
		if (vec[pos] == 0)
		{
			t = NULL;
		}
		else
		{
			t = new BNode<T>;
			t->data = vec[pos];
			t->leftNode = create(vec, pos);
			t->rightNode = create(vec, pos);
		}
	}
	return t;
}

template<class T>
inline BNode<T>* BinaryTree<T>::getSuccessor(BNode<T>* &delNode)
{
	BNode<T>* curr = delNode->rightNode;
	BNode<T>* succe = curr;
	BNode<T>* parent = NULL;

	while (curr!=NULL)
	{
		parent = succe;
		succe = curr;
		curr = curr->leftNode;
	}

	if (succe!=delNode->rightNode)
	{
		parent->leftNode = succe->rightNode;
		succe->rightNode = delNode->rightNode;
	}
	return succe;
}

template<class T>
inline void BinaryTree<T>::get_Height(BNode<T>* t, int h)
{

}



//前序遍历创建二叉树
template<class T>
inline void BinaryTree<T>::createBiTree(std::vector<T> vec)
{
	int pos = -1;
	root = create(vec, pos);
}

template<class T>
inline void BinaryTree<T>::preOrder()
{
	pre_Order(root);
}


template<class T>
inline void BinaryTree<T>::inOrder()
{
	in_Order(root);
}

template<class T>
inline void BinaryTree<T>::Insert(T t)
{
	insert(root,t);
}

template<class T>
inline BNode<T>* BinaryTree<T>::Find(T value)
{
	BNode<T> *q = NULL;
	BNode<T> *re = NULL;
	q = root;
	while (q)
	{
		re = q;
		if (q->data == value)
		{
			return(re);
		}
		if (q->data > value)
			q = q->leftNode;
		else
			q = q->rightNode;
	}
	return re;
}

template<class T>
inline void BinaryTree<T>::DelNode(T t)
{
	BNode<T>* current = root;
	BNode<T>* parent = root;
	bool isLeftNode = true;

	if (!current)
		return;


	while (current->data!=t&&current)
	{
		parent = current;

		if (t<current->data)
		{
			isLeftNode = true;
			current = current->leftNode;

		}
		else if(t>current->data)
		{
			isLeftNode = false;
			current = current->rightNode;
		}
	}

	if (!current->leftNode&& !current->rightNode)
	{
		if (current==root)
		{
			delete root;
			root = NULL;
		}
		else if (isLeftNode)
		{
			parent->leftNode = NULL;
		}
		else
		{
			parent->rightNode = NULL;
		}
	}
	else if (current->rightNode ==NULL)
	{
		if (current==root)
		{
			root = root->leftNode;
		}
		else if (isLeftNode)
		{
			parent->leftNode = current->leftNode;
		}
		else
		{
			parent->rightNode = current->rightNode;
		}
	}
	else if (current->leftNode==NULL)
	{
		if (current == root)
		{
			root = root->rightNode;
		}
		else if (isLeftNode)
		{
			parent->leftNode = current->rightNode;
		}
		else
		{
			parent->rightNode = current->rightNode;
		}
	}
	else
	{
		BNode<T>* succedNode = getSuccessor(current);
		if (current==root)
		{
			root = succedNode;
		}
		else if (current==parent->leftNode)
		{
			parent->leftNode = succedNode;
		}
		else
		{
			parent->rightNode = succedNode;
		}

		succedNode->leftNode = current->leftNode;
	}
	
}

template<class T>
inline void BinaryTree<T>::insert(BNode<T>* &t, T &value)
{
	BNode<T>*temp = t;
	if (t ==NULL)
	{
		t = new BNode<T>;
		t->data = value;
	}
	else if(value<temp->data)
	{
		insert(temp->leftNode, value);
	}
	else if(value>temp->data)
	{
		insert(temp->rightNode, value);
	}
}

template<class T>
inline BNode<T>* BinaryTree<T>::find(BNode<T>* t, T value)
{
	while (t)
	{
		if (t->data==value)
		{
			return t;
		}
		else
		{
			if (value>t->data)
			{
				t = t->leftNode;
			}
			else
			{
				t = t->rightNode;
			}
		}
	}
}
