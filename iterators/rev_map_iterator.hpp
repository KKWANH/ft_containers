#ifndef						REV_MAP_ITERATOR_HPP
#define						REV_MAP_ITERATOR_HPP

#include					"../templates/type1_or_type2.hpp"
#include					"map_iterator.hpp"

namespace					ft
{
	/**
	* ------------------------------------------------------------- *
	* -------------------- FT::REV_MAP_ITERATOR ------------------- *
	*
	* - Coplien form:
	* (constructor):		Construct rev_map_iterator
	* (destructor):			Rev_map_iterator destructor
	* operator=:			Assign content
	*
	* - Operators
	* operators:			Operators for rev_map_iterator
	* non-member operators: Operators for rev_map_iterator
	* ------------------------------------------------------------- *
	*/
		
	/**
	*	@param Key			Type of container's key elements.
	*	@param T			Type of container's mapped elements.
	*	@param Compare		The predicate used to sort the binary tree.
	*	@param Node			The structure used as nodes in the binary tree.
	*	@param B			Boolean to indicate if it's an iterator / a const iterator.
	*/
	template				<class Key, class T, class Compare, typename Node, bool B>
	class					rev_map_iterator
	{
		/* ------------------------------------------------------------- */
		/* -------------------------- ALIASES -------------------------- */
		public:
			typedef			Key																key_type;
			typedef			Compare															key_compare;
			typedef			T																mapped_type;
			typedef			ft::pair<const key_type, mapped_type>							value_type;
			typedef			long int														difference_type;
			typedef			size_t															size_type;
			typedef			std::bidirectional_iterator_tag									iterator_category;
			typedef			typename chooseConst<B, value_type&, const value_type&>::type	reference;
			typedef			typename chooseConst<B, value_type*, const value_type*>::type	pointer;
			typedef			Node*															nodePtr;

		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */
		private:
			nodePtr			_node;		// Pointer to a binary tree's node
			nodePtr			_lastElem;	// Pointer to the dummy node of binary tree
			key_compare		_comp;		// Comparison object used to sort the binary tree

		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
		public:
			rev_map_iterator(nodePtr node = 0, nodePtr lastElem = 0, const key_compare& comp = key_compare()) : _node(node), _lastElem(lastElem), _comp(comp) {}
			rev_map_iterator(const rev_map_iterator<Key, T, Compare, Node, false>& copy)
			{
				_node = copy.getNonConstNode();
				_lastElem = copy.getNonConstLastElem();
				_comp = copy.getCompare();
			}
			~rev_map_iterator() {}

			explicit		rev_map_iterator(map_iterator<Key, T, Compare, Node, false> copy)
			{
				--copy;
				_node = copy.getNonConstNode();
				_lastElem = copy.getNonConstLastElem();
				_comp = copy.getCompare();
			}

			rev_map_iterator&
							operator=(const rev_map_iterator& assign)
			{
				if (this != &assign)
				{
					_node = assign._node;
					_lastElem = assign._lastElem;
					_comp = assign._comp;
				}
				return (*this);
			}

		/* ------------------------------------------------------------- */
		/* --------------------------- GETTERS ------------------------- */
			nodePtr			getNonConstNode() const			{ return _node; }
			nodePtr			getNonConstLastElem() const		{ return _lastElem; }
			key_compare		getCompare() const				{ return _comp; }

		/* ------------------------------------------------------------- */
		/* -------------------------- OPERATORS ------------------------ */

			reference		operator*() const				{ return (_node->content); }
			pointer			operator->() const				{ return (&_node->content); }
			rev_map_iterator&
							operator++()
			{
				nodePtr previousNode = _node;
				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (*this);
				}
				while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first))
				{
					if (_node->left && (_node->left == _lastElem || 
							_comp(_node->left->content.first, previousNode->content.first)))
					{
						_node = _node->left;
						
						Node* tmp = 0;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (*this);
			}

			rev_map_iterator
							operator++(int)
			{
				rev_map_iterator res(*this);
				if (_node == _lastElem)
				{
					_node = _lastElem->left;
					return (res);
				}
				while (_node != _lastElem && !_comp(_node->content.first, res->first))
				{
					if (_node->left && (_node->left == _lastElem || _comp(_node->left->content.first, res->first)))
					{
						_node = _node->left;
						
						Node* tmp = 0;
						if (_node != _lastElem && (tmp = searchMaxNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (res);
			}

			rev_map_iterator&
							operator--()
			{
				nodePtr previousNode = _node;
				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (*this);
				}
				while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || _comp(previousNode->content.first, _node->right->content.first)))
					{
						_node = _node->right;
						Node* tmp = 0;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (*this);
			}

			rev_map_iterator
							operator--(int)
			{
				rev_map_iterator res(*this);
				if (_node == _lastElem)
				{
					_node = _lastElem->right;
					return (res);
				}
				while (_node != _lastElem && !_comp(res->first, _node->content.first))
				{
					if (_node->right && (_node->right == _lastElem || 
							_comp(res->first, _node->right->content.first)))
					{
						_node = _node->right;
						Node* tmp = 0;
						if (_node != _lastElem && (tmp = searchMinNode(_node)))
							_node = tmp;
					}
					else
						_node = _node->parent;
				}
				return (res);
			}

			bool			operator==(const rev_map_iterator& it) const	{ return (it._node == _node); }
			bool			operator!=(const rev_map_iterator& it) const	{ return (it._node != _node); }

		/* ----------------- PRIVATE MEMBER FUNCTIONS ------------------ */
		/* ------------------------------------------------------------- */
		private:
			Node*			searchMaxNode(Node *root)
			{
				if (root && root != _lastElem && root->right && root->right != _lastElem)
					return searchMaxNode(root->right);
				return root;
			}

			Node*			searchMinNode(Node *root)
			{
				if (root && root != _lastElem && root->left && root->left != _lastElem)
					return searchMinNode(root->left);
				return root;
			}
	};
}

#endif