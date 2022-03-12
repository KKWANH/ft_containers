/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:21:38 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/02 00:18:14 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						VECTORITERATOR_hpp
# define						VECTORITERATOR_hpp

namespace						ft
{
	template					<class Typ>
	class						vectorIterator
	{
		public:
			typedef				Typ		value_type;
			typedef				Typ&	reference;
			typedef				Typ*	pointer;
		
		protected:
			pointer				_ptr;
		
		public:
			vectorIterator(void)												{};
			vectorIterator(const vectorIterator &_cpy)							{ *this = _cpy; };
			vectorIterator(pointer _ptr)										{ this->_ptr = _ptr; };
			~vectorIterator(void)												{};

			vectorIterator&				operator=(const vectorIterator &_cpy)			{ this->_ptr = _cpy._ptr; return (*this); };
			vectorIterator&				operator++(void)								{ ++this->_ptr; return (*this); };
			vectorIterator				operator++(int)									{ vectorIterator tmp(*this); operator++(); return (tmp); };
			vectorIterator&				operator--(void)								{ --this->_ptr; return (*this); };
			vectorIterator				operator--(int)									{ vectorIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const vectorIterator &_cpy) const	{ return (this->_ptr == _cpy._ptr); };
			bool						operator!=(const vectorIterator &_cpy) const	{ return (this->_ptr != _cpy._ptr); };
			bool						operator>(const  vectorIterator &_cpy) const	{ return (this->_ptr > _cpy._ptr); };
			bool						operator<(const  vectorIterator &_cpy) const	{ return (this->_ptr < _cpy._ptr); };
			bool						operator>=(const vectorIterator &_cpy) const	{ return (this->_ptr >= _cpy._ptr); };
			bool						operator<=(const vectorIterator &_cpy) const	{ return (this->_ptr <= _cpy._ptr); };
			value_type&					operator*(void)									{ return (*this->_ptr); };
			value_type*					operator->(void)								{ return (this->_ptr); };
			vectorIterator				operator+(int _num)								{ vectorIterator _tmp(*this); _tmp += _num; return (_tmp); };
			vectorIterator&				operator+=(int _num)							{ while (_num < 0) { (*this)--; ++_num; } while (_num > 0) { (*this)++; --_num; } return (*this); };
			vectorIterator				operator-(int _num)								{ vectorIterator _tmp(*this); _tmp -= _num; return (_tmp); };
			vectorIterator&				operator-=(int _num)							{ while (_num < 0) { (*this)++; ++_num; } while (_num > 0) { (*this)--; --_num; } return (*this); };
			value_type&					operator[](int _num)							{ return (*(*this + _num)); };
	};

	template					<class Typ>
	class						reverseVectorIterator : public vectorIterator<Typ>
	{
		public:
			typedef				Typ		value_type;
			typedef				Typ&	reference;
			typedef				Typ*	pointer;
			
			reverseVectorIterator(void)														{};
			reverseVectorIterator(const reverseVectorIterator &_cpy)						{ *this = _cpy; };
			reverseVectorIterator(pointer _ptr)												{ this->_ptr = _ptr; };
			~reverseVectorIterator(void)													{};

			reverseVectorIterator&		operator=(const reverseVectorIterator &_cpy)		{ this->_ptr = _cpy._ptr; return (*this); };
			reverseVectorIterator&		operator++(void)									{ ++this->_ptr; return (*this); };
			reverseVectorIterator		operator++(int)										{ reverseVectorIterator tmp(*this); operator++(); return (tmp); };
			reverseVectorIterator&		operator--(void)									{ --this->_ptr; return (*this); };
			reverseVectorIterator		operator--(int)										{ reverseVectorIterator tmp(*this); operator--(); return (tmp); };
			bool						operator==(const reverseVectorIterator &_cpy) const	{ return (this->_ptr == _cpy._ptr); };
			bool						operator!=(const reverseVectorIterator &_cpy) const	{ return (this->_ptr != _cpy._ptr); };
			bool						operator>(const  reverseVectorIterator &_cpy) const	{ return (this->_ptr > _cpy._ptr); };
			bool						operator<(const  reverseVectorIterator &_cpy) const	{ return (this->_ptr < _cpy._ptr); };
			bool						operator>=(const reverseVectorIterator &_cpy) const	{ return (this->_ptr >= _cpy._ptr); };
			bool						operator<=(const reverseVectorIterator &_cpy) const	{ return (this->_ptr <= _cpy._ptr); };
			value_type&					operator*(void)										{ return (*this->_ptr); };
			value_type*					operator->(void)									{ return (this->_ptr); };
			reverseVectorIterator		operator+(int _num)									{ reverseVectorIterator _tmp(*this); _tmp += _num; return (_tmp); };
			reverseVectorIterator&		operator+=(int _num)								{ while (_num < 0) { (*this)--; ++_num; } while (_num > 0) { (*this)++; --_num; } return (*this); };
			reverseVectorIterator		operator-(int _num)									{ reverseVectorIterator _tmp(*this); _tmp -= _num; return (_tmp); };
			reverseVectorIterator&		operator-=(int _num)								{ while (_num < 0) { (*this)++; ++_num; } while (_num > 0) { (*this)--; --_num; } return (*this); };
			value_type&					operator[](int _num)								{ return (*(*this + _num)); };
	};

	template					<class Typ>
	class						constVectorIterator : public vectorIterator<Typ>
	{
		public:
			typedef				Typ		value_type;
			typedef				Typ&	reference;
			typedef				Typ*	pointer;
			constVectorIterator(void)														{};
			constVectorIterator(const constVectorIterator &_cpy)							{ *this = _cpy; };
			constVectorIterator(pointer _ptr)												{ this->_ptr = _ptr; };
			~constVectorIterator(void)														{};

			constVectorIterator&		operator=(const constVectorIterator &_cpy)			{ this->_ptr = _cpy._ptr; return (*this); };
			value_type&					operator*(void)										{ return (*this->_ptr); };
			value_type&					operator[](int _num)								{ return (*(*this + _num)); };
	};

	template					<class Typ>
	class						constReverseVectorIterator : public reverseVectorIterator<Typ>
	{
		public:
			typedef				Typ		value_type;
			typedef				Typ&	reference;
			typedef				Typ*	pointer;
			constReverseVectorIterator(void)												{};
			constReverseVectorIterator(const constReverseVectorIterator &_cpy)				{ *this = _cpy; };
			constReverseVectorIterator(pointer _ptr)										{ this->_ptr = _ptr; };
			~constReverseVectorIterator(void)												{};

			constReverseVectorIterator&	operator=(const constReverseVectorIterator &_cpy)	{ this->_ptr = _cpy._ptr; return (*this); };
			value_type&					operator*(void)										{ return (*this->_ptr); };
			value_type&					operator[](int _num)								{ return (*(*this + _num)); };
	};
}

# endif