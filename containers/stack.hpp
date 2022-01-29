#ifndef						STACK_HPP
#define						STACK_HPP

#include					"list.hpp"

namespace					ft
{
	/**
	* ------------------------------------------------------------- *
	* ------------------------ FT::STACK -------------------------- *
	*
	* - Coplien form:
	* (constructor):		Construct stack
	* (destructor):		 	Destruct stack
	* operator=:			Assign content
	*
	* - Member functions:
	* empty:				Test whether container is empty
	* size:					 Return size
	* top:					Access next element
	* push:					 Insert element
	* pop:					Remove top element
	*
	* - Non-member function overloads:
	* relational operators: Relational operators for stack
	* ------------------------------------------------------------- *
	*/

	/**
	*	@param T			Type of container's elements.
	*	@param Container	Container object used internally to store T elements.
	*/
	template				<class T, class Container = ft::list<T> >
	class					stack
	{
		/* ------------------------------------------------------------- */
		/* -------------------------- ALIASES -------------------------- */
		public:
			typedef			T				value_type;
			typedef			Container		container_type;
			typedef			size_t			size_type;

		/* ------------------------------------------------------------- */
		/* ------------------------- ATTRIBUTES ------------------------ */
		private:
			container_type	_ctnr;
		
		/* ------------------------------------------------------------- */
		/* ------------------------ COPLIEN FORM ----------------------- */
		public:
			explicit stack (const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
			stack(const stack& x) : _ctnr(x._ctnr) {}
			~stack() {}

			stack&			operator=(const stack& x)
			{
				stack tmp(x);
				swap(_ctnr, tmp._ctnr);
				return *this;
			}

		/* ------------------------------------------------------------- */
		/* ----------------- MEMBER FUNCTION OVERLOADS ----------------- */
			bool			empty() const					{ return _ctnr.empty(); }
			size_type		size() const					{ return _ctnr.size(); }
			value_type&		top()							{ return _ctnr.back(); }
			const value_type&
							top() const						{ return _ctnr.back(); }
			void			push (const value_type& val)	{ _ctnr.push_back(val); }
			void			pop()							{ _ctnr.pop_back(); }

		/* ------------------------------------------------------------- */
		/* --------------- NON-MEMBER FUNCTION OVERLOADS --------------- */
			friend bool		operator==(const stack& lhs, const stack& rhs)	{ return lhs._ctnr == rhs._ctnr; }
			friend bool		operator!=(const stack& lhs, const stack& rhs)	{ return lhs._ctnr != rhs._ctnr; }
			friend bool		operator<( const stack& lhs, const stack& rhs)	{ return lhs._ctnr < rhs._ctnr; }
			friend bool		operator<=(const stack& lhs, const stack& rhs)	{ return lhs._ctnr <= rhs._ctnr; }
			friend bool		operator>( const stack& lhs, const stack& rhs)	{ return lhs._ctnr > rhs._ctnr; }
			friend bool		operator>=(const stack& lhs, const stack& rhs)	{ return lhs._ctnr >= rhs._ctnr; }

		/* ----------------- PRIVATE MEMBER FUNCTIONS ------------------ */
		/* ------------------------------------------------------------- */
		private:
			template		<typename U>
			void			swap(U& a, U& b)
			{
				U tmp(a);
				a = b;
				b = tmp;
			}
	};		
}

#endif