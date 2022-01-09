/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:53:31 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 14:19:19 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef						LISTITERATOR_HPP
# define						LISTITERATOR_HPP

# include						"utils.hpp"
# include						"list.hpp"

namespace						ft
{
	template							<class Typ>
	class								listIterator
		{
		public:
			typedef						Typ														value_type;
			typedef						Typ&													reference;
			typedef						Node<Typ>*												pointer;

		protected:
			pointer						_ptr;

		public:
			listIterator(void)																	{};
			listIterator(const listIterator &_cpy)												{ *this = _cpy; };	
			listIterator(pointer _tmp) : _ptr(_tmp)												{};
			~listIterator(void)																	{};
			
			pointer						node(void) const										{ return (_ptr); };
			listIterator&				operator=(const listIterator &_cpy)						{ _ptr = _cpy._ptr; return (*this); };
			listIterator&				operator++(void)										{ _ptr = _ptr->_nxt; return (*this); };
			listIterator				operator++(int)											{ listIterator tmp(*this); operator++(); return (tmp); };
			listIterator&				operator--(void)										{ _ptr = _ptr->_prv; return (*this); };
			listIterator				operator--(int)											{ listIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const listIterator& _cpy) const				{ return (_ptr == _cpy._ptr); };
			bool						operator!=(const listIterator& _cpy) const				{ return (_ptr != _cpy._ptr); };
			bool						operator>(const  listIterator& _cpy) const				{ return (_ptr > _cpy._ptr); };
			bool						operator>=(const listIterator& _cpy) const				{ return (_ptr >= _cpy._ptr); };
			bool						operator<(const  listIterator& _cpy) const				{ return (_ptr < _cpy._ptr); };
			bool						operator<=(const listIterator& _cpy) const				{ return (_ptr <= _cpy._ptr); };
			value_type&					operator*(void)											{ return (_ptr->_val); };
			value_type*					operator->(void)										{ return (_ptr->_val); };
			listIterator				operator+(int _num)										{ listIterator tmp(*this); tmp += _num; return (tmp); };
			listIterator				operator-(int _num)										{ listIterator tmp(*this); tmp -= _num; return (tmp); };
			listIterator&				operator+=(int _num)									{ while (_num < 0) { --(*this); ++_num; } while (_num > 0) { ++(*this); --_num; } return (*this); };
			listIterator&				operator-=(int _num)									{ while (_num < 0) { --(*this); --_num; } while (_num > 0) { ++(*this); ++_num; } return (*this); };
	};

	template							<class Typ>
	class								constListIterator
		{
		public:
			typedef						Typ														value_type;
			typedef						Typ&													reference;
			typedef						Node<Typ>*												pointer;

		protected:
			pointer						_ptr;

		public:
			constListIterator(void)																{};
			constListIterator(const constListIterator &_cpy)									{ *this = _cpy; };	
			constListIterator(pointer _tmp) : _ptr(_tmp)										{};
			~constListIterator(void)															{};
			
			pointer						node(void) const										{ return (_ptr); };
			constListIterator&			operator=(const constListIterator &_cpy)				{ _ptr = _cpy._ptr; return (*this); };
			constListIterator&			operator++(void)										{ _ptr = _ptr->_nxt; return (*this); };
			constListIterator			operator++(int)											{ constListIterator tmp(*this); operator++(); return (tmp); };
			constListIterator&			operator--(void)										{ _ptr = _ptr->_prv; return (*this); };
			constListIterator			operator--(int)											{ constListIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const constListIterator& _cpy) const			{ return (_ptr == _cpy._ptr); };
			bool						operator!=(const constListIterator& _cpy) const			{ return (_ptr != _cpy._ptr); };
			bool						operator>(const  constListIterator& _cpy) const			{ return (_ptr > _cpy._ptr); };
			bool						operator>=(const constListIterator& _cpy) const			{ return (_ptr >= _cpy._ptr); };
			bool						operator<(const  constListIterator& _cpy) const			{ return (_ptr < _cpy._ptr); };
			bool						operator<=(const constListIterator& _cpy) const			{ return (_ptr <= _cpy._ptr); };
			value_type&					operator*(void)											{ return (_ptr->_val); };
			value_type*					operator->(void)										{ return (_ptr->_val); };
			constListIterator			operator+(int _num)										{ constListIterator tmp(*this); tmp += _num; return (tmp); };
			constListIterator			operator-(int _num)										{ constListIterator tmp(*this); tmp -= _num; return (tmp); };
			constListIterator&			operator+=(int _num)									{ while (_num < 0) { --(*this); ++_num; } while (_num > 0) { ++(*this); --_num; } return (*this); };
			constListIterator&			operator-=(int _num)									{ while (_num < 0) { --(*this); --_num; } while (_num > 0) { ++(*this); ++_num; } return (*this); };
	};

	template							<class Typ>
	class								reverseListIterator
		{
		public:
			typedef						Typ													value_type;
			typedef						Typ&												reference;
			typedef						Node<Typ>*											pointer;

		protected:
			pointer						_ptr;

		public:
			reverseListIterator(void)															{};
			reverseListIterator(const reverseListIterator &_cpy)								{ *this = _cpy; };	
			reverseListIterator(pointer _tmp) : _ptr(_tmp)										{};
			~reverseListIterator(void)															{};
			
			pointer						node(void) const										{ return (_ptr); };
			reverseListIterator&		operator=(const reverseListIterator &_cpy)				{ _ptr = _cpy._ptr; return (*this); };
			reverseListIterator&		operator++(void)										{ _ptr = _ptr->_nxt; return (*this); };
			reverseListIterator			operator++(int)											{ reverseListIterator tmp(*this); operator++(); return (tmp); };
			reverseListIterator&		operator--(void)										{ _ptr = _ptr->_prv; return (*this); };
			reverseListIterator			operator--(int)											{ reverseListIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const reverseListIterator& _cpy) const		{ return (_ptr == _cpy._ptr); };
			bool						operator!=(const reverseListIterator& _cpy) const		{ return (_ptr != _cpy._ptr); };
			bool						operator>(const  reverseListIterator& _cpy) const		{ return (_ptr > _cpy._ptr); };
			bool						operator>=(const reverseListIterator& _cpy) const		{ return (_ptr >= _cpy._ptr); };
			bool						operator<(const  reverseListIterator& _cpy) const		{ return (_ptr < _cpy._ptr); };
			bool						operator<=(const reverseListIterator& _cpy) const		{ return (_ptr <= _cpy._ptr); };
			value_type&					operator*(void)											{ return (_ptr->_val); };
			value_type*					operator->(void)										{ return (_ptr->_val); };
			reverseListIterator			operator+(int _num)										{ reverseListIterator tmp(*this); tmp += _num; return (tmp); };
			reverseListIterator			operator-(int _num)										{ reverseListIterator tmp(*this); tmp -= _num; return (tmp); };
			reverseListIterator&		operator+=(int _num)									{ while (_num < 0) { --(*this); ++_num; } while (_num > 0) { ++(*this); --_num; } return (*this); };
			reverseListIterator&		operator-=(int _num)									{ while (_num < 0) { --(*this); --_num; } while (_num > 0) { ++(*this); ++_num; } return (*this); };
	};
	
	template							<class Typ>
	class								constReverseListIterator
		{
		public:
			typedef						Typ														value_type;
			typedef						Typ&													reference;
			typedef						Node<Typ>*												pointer;

		protected:
			pointer						_ptr;

		public:
			constReverseListIterator(void)														{};
			constReverseListIterator(const constReverseListIterator &_cpy)						{ *this = _cpy; };	
			constReverseListIterator(pointer _tmp) : _ptr(_tmp)									{};
			~constReverseListIterator(void)														{};
			
			pointer						node(void) const										{ return (_ptr); };
			constReverseListIterator&	operator=(const constReverseListIterator &_cpy)			{ _ptr = _cpy._ptr; return (*this); };
			constReverseListIterator&	operator++(void)										{ _ptr = _ptr->_nxt; return (*this); };
			constReverseListIterator	operator++(int)											{ constReverseListIterator tmp(*this); operator++(); return (tmp); };
			constReverseListIterator&	operator--(void)										{ _ptr = _ptr->_prv; return (*this); };
			constReverseListIterator	operator--(int)											{ constReverseListIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const constReverseListIterator& _cpy) const	{ return (_ptr == _cpy._ptr); };
			bool						operator!=(const constReverseListIterator& _cpy) const	{ return (_ptr != _cpy._ptr); };
			bool						operator>(const  constReverseListIterator& _cpy) const	{ return (_ptr > _cpy._ptr); };
			bool						operator>=(const constReverseListIterator& _cpy) const	{ return (_ptr >= _cpy._ptr); };
			bool						operator<(const  constReverseListIterator& _cpy) const	{ return (_ptr < _cpy._ptr); };
			bool						operator<=(const constReverseListIterator& _cpy) const	{ return (_ptr <= _cpy._ptr); };
			value_type&					operator*(void)											{ return (_ptr->_val); };
			value_type*					operator->(void)										{ return (_ptr->_val); };
			constReverseListIterator	operator+(int _num)										{ constReverseListIterator tmp(*this); tmp += _num; return (tmp); };
			constReverseListIterator	operator-(int _num)										{ constReverseListIterator tmp(*this); tmp -= _num; return (tmp); };
			constReverseListIterator&	operator+=(int _num)									{ while (_num < 0) { --(*this); ++_num; } while (_num > 0) { ++(*this); --_num; } return (*this); };
			constReverseListIterator&	operator-=(int _num)									{ while (_num < 0) { --(*this); --_num; } while (_num > 0) { ++(*this); ++_num; } return (*this); };
	};
};


# endif