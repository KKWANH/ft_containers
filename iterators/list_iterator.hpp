#ifndef						LIST_ITERATOR_HPP
#define						LIST_ITERATOR_HPP

#include					"../templates/type1_or_type2.hpp"

namespace					ft
{
	template				<typename T, typename Node, bool B>
	class					rev_list_iterator;
		
	/**
	* ------------------------------------------------------------- *
	* -------------------- FT::LIST_ITERATOR -------------------- *
	*
	* - Coplien form:
	* (constructor):		Construct list_iterator
	* (destructor):			List_iterator destructor
	* operator=:			Assign content
	*
	* - Operators
	* operators:			Operators for list_iterator
	* non-member operators: Operators for list_iterator
	* ------------------------------------------------------------- *
	*/
		
	/**
	*	@param T			Type of container's elements.
	*	@param Node 		The structure used as nodes in the list.
	*	@param B			Boolean to indicate if it's an iterator / a const iterator.
	*/
	template				<typename T, typename Node, bool B>
	class					list_iterator
	{
		/* ------------------------------------------------------------- */
		/* -------------------------- ALIASES -------------------------- */
		public:
			typedef			long int									difference_type;
			typedef			T											value_type;
			typedef			size_t										size_type;
			typedef 		std::bidirectional_iterator_tag				iterator_category;
			typedef			typename chooseConst<B, T&, const T&>::type	reference;
			typedef			typename chooseConst<B, T*, const T*>::type	pointer;
			typedef			Node*										nodePtr;

		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */			
		private:
			nodePtr			_node;	// A pointer to a node in the list.

		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
			
		public:
			list_iterator(nodePtr node = 0) : _node(node) {}
			list_iterator(const list_iterator<T, Node, false>& copy) { _node = copy.getNode(); }
			~list_iterator() {}

			list_iterator&	operator=(const list_iterator& assign)
			{
				if (this != &assign)
					_node = assign._node;
				return		(*this);
			}

		/* ------------------------------------------------------------- */
		/* --------------------------- GETTERS ------------------------- */
			nodePtr			getNode() const				{ return _node; }

		/* ------------------------------------------------------------- */
		/* ---------------------- OPERATOR OVERLOADS ------------------- */
			reference		operator*() const		 	{ return (_node->content); }
			pointer			operator->() const			{ return (&(_node->content)); }

			list_iterator&	operator++()				{ _node = _node->next; return (*this); }
			list_iterator	operator++(int)				{ list_iterator res(*this); ++(*this); return (res); };
			list_iterator&	operator--()				{ _node = _node->prev; return (*this); }
			list_iterator	operator--(int)				{ list_iterator res(*this); --(*this); return (res); };
			
			
			/* ------------------------------------------------------------- */
			/* --------------- NON-MEMBER OPERATOR OVERLOADS --------------- */ 
			
			bool			operator==(const list_iterator& it) const	{ return (it._node == _node); }
			bool			operator!=(const list_iterator& it) const	{ return (it._node != _node); }
	};
}

#endif