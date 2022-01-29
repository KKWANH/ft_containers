#ifndef						LIST_HPP
#define						LIST_HPP

#include					<cmath>

#include					"../templates/stl_like.hpp"
#include					"../templates/type1_or_type2.hpp"
#include					"../iterators/list_iterator.hpp"
#include					"../iterators/rev_list_iterator.hpp"

namespace					ft
{
	/**
	* ------------------------------------------------------------- *
	* ------------------------- FT::LIST -------------------------- *
	*
	* - Coplien form:			
	* (constructor):		Construct list
	* (destructor):			Destruct list
	* operator=:			Assign list
	*
	* - Iterators:
	* begin:				Return iterator to beginning
	* end:					Return iterator to end
	* rbegin:				Return reverse iterator to reverse beginning
	* rend:					Return reverse iterator to reverse end
	*
	* - Capacity:
	* empty:				Test whether container is empty
	* size:					Return size
	* max_size:				Return maximum size
	*
	* - Element access:
	* front:				Access first element
	* back:					Access last element
	*
	* - Modifiers:
	* assign:				Assign new content to container
	* push_front:			Insert element at beginning
	* pop_front:			Delete first element
	* push_back:			Add element at the end
	* pop_back:				Delete last element
	* insert:				Insert elements
	* erase:				Erase elements
	* swap:					Swap content
	* resize:				Change size
	* clear:				Clear content
	*
	* - Operations:
	* splice:				Transfer elements from list to list
	* remove:				Remove elements with specific value
	* remove_if:			Remove elements fulfilling condition
	* unique:				Remove duplicate values
	* merge:				Merge sorted lists
	* sort:					Sort elements in container
	* reverse:				Reverse the order of elements
	*
	* - Non-member function overloads
	* relational operators: Relational operators for list
	* swap:					Exchanges contents of two lists
	* ------------------------------------------------------------- *
	*/

	/**
	*	@param T			Type of container's elements.
	*	@param Alloc		Object used to manage the vector' storage.
	*/
	template				<typename T, class Alloc = ft::allocator<T> >
	class					list
	{
		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */
		private:
			struct			Node
			{
				T			content;	// Element of the list
				Node*		prev;		// Pointer to previous node
				Node*		next;		// Pointer to next node
			};			
		
		/* ------------------------------------------------------------- */
		/* -------------------------- ALIASES -------------------------- */
		public:
			typedef			T												value_type;
			typedef			Alloc											allocator_type;
			typedef			long int										difference_type;
			typedef			size_t											size_type;
			typedef			T&												reference;
			typedef			const T&										const_reference;
			typedef			T*												pointer;
			typedef			const T*										const_pointer;
			typedef			typename ft::list_iterator<T, Node, false>		iterator;
			typedef			typename ft::list_iterator<T, Node, true>		const_iterator;
			typedef			typename ft::rev_list_iterator<T, Node, false>	reverse_iterator;
			typedef			typename ft::rev_list_iterator<T, Node, true>	const_reverse_iterator;


		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */
		private:
			Node*			_endList;		// Pointer to the neutral element of the circle linked list
			size_type		_size;			// Number of T values inside the list
			Alloc			_allocT;		// Copy of allocator_type object
			ft::allocator<Node>
							_allocNode;		// Node's allocator


		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
		public:
			explicit		list (const allocator_type& alloc = allocator_type())
			:				_size(0),
							_allocT(alloc)
			{
				newEndNode();
			}
			
			explicit		list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			:				_size(0),
							_allocT(alloc)
			{
				newEndNode();
				while (_size < n)
					push_back(val);
			}

			template				<class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			:				_size(0),
							_allocT(alloc)
			{
				newEndNode();
				for (; first != last; ++first)
					push_back(*first);
			}
			
			list (const list& x)
			:				_size(0),
							_allocT(x._allocT),
							_allocNode(x._allocNode)
			{
				newEndNode();
				for (const_iterator it = x.begin(); it != x.end(); ++it)
					push_back(*it);
			}

			~list()
			{
				while (_size > 0)
					pop_back();
				_allocNode.deallocate(_endList, 1);
			}

			list&			operator= (const list& x)
			{
				list copy(x);
				this->swap(copy);
				return *this;
			}


		/* ------------------------------------------------------------- */
		/* ------------------------- ITERATORS ------------------------- */
		public:
			iterator		begin()			{ return !_size ? iterator(_endList) : iterator(_endList->next); }
			const_iterator	begin() const	{ return !_size ? iterator(_endList) : iterator(_endList->next); }
			iterator		end()			{ return iterator(_endList); }
			const_iterator	end() const		{ return const_iterator(_endList); }
			reverse_iterator
							rbegin()		{ return !_size ? reverse_iterator(_endList) : reverse_iterator(_endList->prev); }
			const_reverse_iterator
							rbegin() const	{ return !_size ? const_reverse_iterator(_endList) : const_reverse_iterator(_endList->prev); }
			reverse_iterator
							rend()			{ return reverse_iterator(_endList); }
			const_reverse_iterator
							rend() const	{ return const_reverse_iterator(_endList); }

		/* ------------------------------------------------------------- */
		/* -------------------------- CAPACITY ------------------------- */
		public:
			bool			empty() const	{ return _size == 0; }
			size_type		size() const	{ return _size; }
			size_type		max_size() const
			{
				if (sizeof(value_type) == 1)
					return static_cast<size_type>(pow(2.0, 64.0) / 2.0) - 1;
				return static_cast<size_type>(pow(2.0, 64.0) / static_cast<double>(sizeof(value_type))) - 1;
			}

		/* ------------------------------------------------------------- */
		/* ---------------------- ELEMENTS ACCESS ---------------------- */ 
		public:
			reference		front()			{ return _endList->next->content; }
			const_reference	front() const	{ return _endList->next->content; }
			reference		back()			{ return _endList->prev->content; }
			const_reference back() const	{ return _endList->prev->content; }


		/* ------------------------------------------------------------- */
		/* ------------------------- MODIFIERS ------------------------- */
			template		<class InputIterator>
			void			assign (InputIterator first, InputIterator last)
			{
				size_type i = 0;
				for (iterator it = begin(); first != last; ++it, ++i, ++first)
				{
					if (i >= _size)
						push_back(*first);
					else
					{
						_allocT.destroy(&(*it));
						_allocT.construct(&(*it), *first);
					}
				}
				while (_size > i)
					pop_back();
			}

			void			assign (size_type n, const value_type& val)
			{
				size_type i = 0;
				for (iterator it = begin(); i < n; ++it, ++i)
				{
					if (i >= _size)
						push_back(val);
					else
					{
						_allocT.destroy(&(*it));
						_allocT.construct(&(*it), val);
					}
				}
				while (_size > i)
					pop_back();
			}

			void			push_front (const value_type& val)
			{
				Node* tmp = createNode(val);
				tmp->prev = _endList;
				tmp->next = _endList->next;
				_endList->next->prev = tmp;
				_endList->next = tmp;
				++_size;
			}

			void			pop_front()
			{
				if (_size)
					deleteNode(_endList->next);
			}

			void			push_back (const value_type& val)
			{
				Node* tmp = createNode(val);
				tmp->prev = _endList->prev;
				tmp->next = _endList;
				_endList->prev->next = tmp;
				_endList->prev = tmp;
				++_size;
			}

			void			pop_back()
			{
				if (_size)
					deleteNode(_endList->prev);
			}

			iterator		insert (iterator position, const value_type& val)
			{
				Node* newNode = createNode(val);
				newNode->prev = position.getNode()->prev;
				newNode->next = position.getNode()->prev->next;
				newNode->prev->next = newNode;
				newNode->next->prev = newNode;
				++_size;
				return iterator(--position);
			}

			void			insert (iterator position, size_type n, const value_type& val)
			{
				while (n-- > 0)
					position = insert(position, val);
			}
			
			template		<class InputIterator>
			void			insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
			{
				for (ft::pair<reverse_iterator, reverse_iterator> it(last, first); it.first != it.second; ++it.first)
					position = insert(position, *it.first);
			}

			iterator		erase (iterator position)
			{
				return erase(position, position.getNode()->next);
			}

			iterator		erase (iterator first, iterator last)
			{
				for (; first != last;)
					deleteNode((++first).getNode()->prev);
				return last;
			}

			void			swap (list& x)
			{
				swap(_size, x._size);
				swap(_endList, x._endList);
				swap(_allocT, x._allocT);
				swap(_allocNode, x._allocNode);
			}

			void			resize (size_type n, value_type val = value_type())
			{
				while (n > _size)
					push_back(val);
				while (n < _size)
					pop_back();
			}

			void			clear()
			{
				while (_size)
					pop_back();
			}
			
		/* ------------------------------------------------------------- */
		/* ------------------------ OPERATIONS ------------------------- */ 
		public:
			void			splice (iterator position, list& x)
			{
				while (x.size())
					splice(position, x, x.begin());
			}

			void			splice (iterator position, list& x, iterator i)
			{
				Node* tmp = i.getNode();
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
				tmp->prev = position.getNode()->prev;
				tmp->next = position.getNode();
				position.getNode()->prev->next = tmp;
				position.getNode()->prev = tmp;
				--x._size;
				++_size;
			}

			void			splice (iterator position, list& x, iterator first, iterator last)
			{
				if (first == last)
					return;
				if (first.getNode()->next == last.getNode())
					splice(position, x, first);
				else
				{
					size_type rangeSize = 0;
					for (iterator tmp(first); tmp != last; ++tmp)
						++rangeSize;
					iterator lastRangeElem(last.getNode()->prev);
					first.getNode()->prev->next = last.getNode();
					last.getNode()->prev = first.getNode()->prev;
					first.getNode()->prev = position.getNode()->prev;
					lastRangeElem.getNode()->next = position.getNode();
					position.getNode()->prev->next = first.getNode();
					position.getNode()->prev = lastRangeElem.getNode();
					x._size -= rangeSize;
					_size += rangeSize;
				}
			}

			void			remove (const value_type& val)
			{
				for (iterator it = end(); it.getNode()->next != end().getNode();)
				{
					if (it.getNode()->next->content == val)
						deleteNode(it.getNode()->next);
					else
						++it;
				}
			}

			template		<class Predicate>
			void			remove_if (Predicate pred)
			{
				for (iterator it = end(); it.getNode()->next != end().getNode();)
				{
					if (pred(it.getNode()->next->content))
						deleteNode(it.getNode()->next);
					else
						++it;
				}
			}

			void			unique()
			{
				for (iterator it = end(); it.getNode()->next != end().getNode();)
				{
					if (it != end() && *it == it.getNode()->next->content)
						deleteNode(it.getNode()->next);
					else
						++it;
				}
			}

			template		<class BinaryPredicate>
			void			unique (BinaryPredicate binary_pred)
			{
				for (iterator it = end(); it.getNode()->next->next != end().getNode();)
				{
					if (binary_pred(it.getNode()->next->content, it.getNode()->next->next->content))
						deleteNode(it.getNode()->next->next);
					else
						++it;
				}
			}

			void			merge (list& x)
			{
				if (&x == this)
					return ;	
				iterator thisIt = end();
				for (iterator xIt = x.end(); xIt.getNode()->next != x.end().getNode();)
				{
					if (thisIt.getNode()->next == end().getNode() ||
							xIt.getNode()->next->content < thisIt.getNode()->next->content)
					{
						splice(thisIt.getNode()->next, x, xIt.getNode()->next);
						++thisIt;
					}
					else
						++thisIt;
				}
			}
			
			template		<class Compare>
			void			merge (list& x, Compare comp)
			{
				if (&x == this)
					return ;
				iterator thisIt = end();
				for (iterator xIt = x.end(); xIt.getNode()->next != x.end().getNode();)
				{
					if (thisIt.getNode()->next == end().getNode() || comp(xIt.getNode()->next->content, thisIt.getNode()->next->content))
					{
						splice(thisIt.getNode()->next, x, xIt.getNode()->next);
						++thisIt;
					}
					else
						++thisIt;
				}
			}

			void			sort()
			{
				for (iterator it = begin(); it.getNode()->next != end().getNode(); ++it)
				{
					iterator tmp(it);
					for (iterator min(it.getNode()->next); min != end(); ++min)
						if (*min < *tmp)
							tmp = min;
					if (*tmp < *it)
					{
						swap2Nodes(tmp.getNode(), it.getNode());
						it = tmp;
					}
				}
			}

			template		<class Compare>
			void			sort (Compare comp)
			{
				for (iterator it = begin(); it.getNode()->next != end().getNode(); ++it)
				{
					iterator tmp(it);
					for (iterator min(it.getNode()->next); min != end(); ++min)
						if (comp(*min, *tmp))
							tmp = min;
					if (comp(*tmp, *it))
					{
						swap2Nodes(tmp.getNode(), it.getNode());
						it = tmp;
					}
				}
			}

			void			reverse()
			{
				if (_size > 1)
				{
					Node* insertBefore = _endList;
					Node* tmp;
					while (_endList->next != insertBefore)
					{
						tmp = _endList->next;
						_endList->next = tmp->next;
						tmp->next->prev = _endList;
						tmp->next = insertBefore;
						tmp->prev = insertBefore->prev;
						tmp->prev->next = tmp;
						tmp->next->prev = tmp;
						insertBefore = tmp;
					}
				}
			}


		/* ------------------------------------------------------------- */
		/* --------------- NON-MEMBER FUNCTION OVERLOADS --------------- */
		/* ------------------------------------------------------------- */
			friend bool		operator==(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				if (lhs.size() != rhs.size())
					return false;

				for (ft::pair<const_iterator, const_iterator> it(lhs.begin(), rhs.begin());
						it.first != lhs.end(); ++it.first, ++it.second)
					if (*(it.first) != *(it.second))
						return false;
				return true;
			}
			friend bool		operator!=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return !(lhs == rhs); }

			friend bool		operator<(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
			{
				for (ft::pair<const_iterator, const_iterator> it(lhs.begin(), rhs.begin()); it.first != lhs.end() && it.second != rhs.end(); ++it.first, ++it.second)
					if (*(it.first) < *(it.second))
						return true;
				return (lhs.size() < rhs.size());
			}
			friend bool		operator>( const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return rhs < lhs; }
			friend bool		operator<=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return !(rhs < lhs); }
			friend bool		operator>=(const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)	{ return !(lhs < rhs); }

			friend void		swap(list& x, list& y)											{ x.swap(y); }


		/* ------------------------------------------------------------- */
		/* ------------------ PRIVATE MEMBER FUNCTIONS ----------------- */
		private:
			void			newEndNode()
			{
				_endList = _allocNode.allocate(1);
				_endList->next = _endList;
				_endList->prev = _endList;			
			}

			void			deleteNode(Node *toDelete)
			{
				toDelete->prev->next = toDelete->next;
				toDelete->next->prev = toDelete->prev;
				_allocT.destroy(&toDelete->content);
				_allocNode.deallocate(toDelete, 1);
				--_size;
			}

			Node*			createNode(const value_type& val = value_type())
			{
				Node *newNode = _allocNode.allocate(1);
				_allocT.construct(&newNode->content, val);				
				return newNode;
			}

			void			swap2Nodes(Node *a, Node *b)
			{
				if (a->prev == b)
					swap(a, b);
				Node *aPrev = a->prev;
				Node *aNext = a->next;
				if (a->next != b)
				{
					a->prev = b->prev;
					a->next = b->next;
					b->next->prev = a;
					b->prev->next = a;
					b->prev = aPrev;
					b->next = aNext;
					aPrev->next = b;
					aNext->prev = b;
				}
				else
				{
					a->prev = b;
					a->next = b->next;
					b->next->prev = a;
					b->prev = aPrev;
					aPrev->next = b;
					b->next = a;
				}
			}

			template		<typename U>
			void			swap(U& a, U& b)
			{
				U tmp = a;
				a = b;
				b = tmp;
			}
	};
}

#endif