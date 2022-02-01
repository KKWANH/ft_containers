#ifndef						REV_VECTOR_ITERATOR_HPP
#define 					REV_VECTOR_ITERATOR_HPP

#include					"vector_iterator.hpp"
#include					"../templates/stl_like.hpp"

#define						ADD 1
#define						SUBSTRACT 0

namespace					ft
{
	/**
	* ------------------------------------------------------------- *
	* ------------------ FT::REV_VECTOR_ITERATOR ------------------ *
	*
	* - Coplien form:
	* (constructor):		Construct rev_vector_iterator
	* (destructor):			Rev_vector_iterator destructor
	* operator=:			Assign content
	*
	* - Operators
	* operators:			Operators for rev_vector_iterator
	* non-member operators: Operators for rev_vector_iterator
	* ------------------------------------------------------------- *
	*/
		
	/**
	*	@param T			Type of container's elements.
	*	@param B			Boolean to indicate if it's a const or not vector iterator.
	*/
	template				<typename T, bool B>
	class 					rev_vector_iterator
	{
		/* ------------------------------------------------------------- */
		/* -------------------------- ALIASES -------------------------- */
		public:
			typedef			long int										difference_type;
			typedef			T												value_type;
			typedef			size_t											size_type;
			typedef			std::random_access_iterator_tag					iterator_category;
			typedef			typename chooseConst<B, T&, const T&>::type		reference;
			typedef			typename chooseConst<B, T*, const T*>::type		pointer;
			typedef			T*												elemPtr;

		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */
		private:
			elemPtr			_val;	// A pointer to an element in the vector array

		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
		public:
			rev_vector_iterator(elemPtr val = 0) : _val(val) {}
			rev_vector_iterator(const rev_vector_iterator<T, false>& copy) { _val = copy.getElemPtr(); }
			explicit		rev_vector_iterator(const vector_iterator<T, false>& copy) { _val = copy.getElemPtr() - 1; }
			~rev_vector_iterator() {}

			rev_vector_iterator&
							operator=(const rev_vector_iterator& assign)
			{
				if (this != &assign)
					_val = assign._val;
				return (*this);
			}

		/* ------------------------------------------------------------- */
		/* --------------------------- GETTERS ------------------------- */
			elemPtr			getElemPtr() const			{ return _val; }

		/* ------------------------------------------------------------- */
		/* --------------------- OPERATOR OVERLOADS -------------------- */
			reference		operator*() const			{ return (*_val); }
			pointer			operator->() const			{ return (_val); }
			rev_vector_iterator&
							operator++()				{ --_val; return (*this); }
			rev_vector_iterator&
							operator--()				{ ++_val; return (*this); }
			rev_vector_iterator
							operator++(int)
			{
				rev_vector_iterator res(*this);
				++(*this);
				return (res);
			}
			
			rev_vector_iterator operator--(int)
			{
				rev_vector_iterator res(*this);
				--(*this);
				return (res);
			}
			
			bool operator==(const rev_vector_iterator& it) const	{ return (it._val == _val); }
			bool operator!=(const rev_vector_iterator& it) const	{ return (it._val != _val); }
			bool operator<(const rev_vector_iterator& it) const		{ return (it._val > this->_val); }
			bool operator>(const rev_vector_iterator& it) const		{ return (it._val < this->_val); }
			bool operator<=(const rev_vector_iterator& it) const	{ return (it._val >= this->_val); }
			bool operator>=(const rev_vector_iterator& it) const	{ return (it._val <= this->_val); }
			
			rev_vector_iterator& operator+=(int nb)
			{
				movePtr(this->_val, nb, ADD);
				return (*this);
			}

			rev_vector_iterator operator+(int nb) const
			{
				rev_vector_iterator it(*this);
						
				movePtr(it._val, nb, ADD);
				return (it);
			}
			
			rev_vector_iterator& operator-=(int nb)
			{						
				movePtr(this->_val, nb, SUBSTRACT);
				return (*this);
			}

			rev_vector_iterator operator-(int nb) const
			{
				rev_vector_iterator it(*this);
				
				movePtr(it._val, nb, SUBSTRACT);
				return (it);
			}

			reference operator[](int nb) const
			{
				value_type* tmp(this->_val);

				movePtr(tmp, nb, ADD);
				return (*tmp);
			}

			difference_type operator-(rev_vector_iterator it) const
			{
				return (it._val - this->_val);
			}
			
			friend rev_vector_iterator operator+(int nb, const rev_vector_iterator& it)
			{
				rev_vector_iterator newIt(it);
				return (newIt += nb);
			}

			friend rev_vector_iterator operator-(int nb, const rev_vector_iterator& it)
			{
				rev_vector_iterator newIt(it);
				return (newIt -= nb);
			}

		private:

			void movePtr(elemPtr& val, long nb, bool sign) const
			{
				int mov;
				if (sign == ADD)
					mov = nb > 0 ? mov = -1: mov = 1;
				else
					mov = nb > 0 ? mov = 1: mov = -1;

				if (nb < 0)
					nb *= -1;
				for (; nb > 0; --nb)
					val += mov;
			}
	};
}

#endif