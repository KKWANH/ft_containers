/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:21:38 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/01 22:58:22 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						MAPITERATOR_hpp
# define						MAPITERATOR_hpp

# include						"utils.hpp"
# include						<utility>

namespace						ft
{
	template					<class _ty1, class _ty2>
	class mapIterator
	{
		public:
			typedef				std::pair<_ty1, _ty2>		value_type;
			typedef				std::pair<_ty1, _ty2>&		reference;
			typedef				BNode<_ty1, _ty2>*			pointer;

		protected:
			pointer				_ptr;
		
		private:
			pointer				_successor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_right){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_right) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_right; while (_nxt->_left) _nxt = _nxt->_left; }
				return			_nxt;
			};

			pointer				_predecessor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_left){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_left) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_left; while (_nxt->_right) _nxt = _nxt->_right; }
				return			_nxt;
			};
			
		public:
			mapIterator(void)													: _ptr(0) {};
			mapIterator(const pointer _cpy)										: _ptr(_cpy) {};
			mapIterator(const mapIterator &_cpy)								{ *this = _cpy; };
			
			mapIterator&		operator=(const mapIterator &_cpy)				{ _ptr = _cpy._ptr; return (*this); };
			pointer				node(void)										{ return (_ptr); };
			value_type&			operator*(void)									{ return (_ptr->pair); };
			value_type*			operator->(void)								{ return (&_ptr->pair); };
			bool				operator==(const mapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr == _cpy._ptr); };
			bool				operator!=(const mapIterator<_ty1, _ty2> &_cpy)	{ return (!(*this == _cpy)); };
			bool				operator>(const  mapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr >  _cpy._ptr); };
			bool				operator<(const  mapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr <  _cpy._ptr); };
			bool				operator>=(const mapIterator<_ty1, _ty2> &_cpy) { return (_ptr >= _cpy._ptr); };
			bool				operator<=(const mapIterator<_ty1, _ty2> &_cpy) { return (_ptr <= _cpy._ptr); };
			mapIterator&		operator++(void)								{ _ptr = _successor(_ptr); return (*this); };
			mapIterator			operator++(int)									{ mapIterator _tmp(*this); this->operator++(); return (_tmp); };
			mapIterator&		operator--(void)								{ _ptr = _predecessor(_ptr); return (*this); };
			mapIterator			operator--(int)									{ mapIterator _tmp(*this); this->operator--(); return (_tmp); };
	};
	
	template					<class _ty1, class _ty2>
	class						constMapIterator
	{
		public:
			typedef				std::pair<_ty1, _ty2>		value_type;
			typedef				std::pair<_ty1, _ty2>&		reference;
			typedef				BNode<_ty1, _ty2>*			pointer;

		protected:
			pointer				_ptr;
		
		private:
			pointer				_successor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_right){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_right) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_right; while (_nxt->_left) _nxt = _nxt->_left; }
				return			_nxt;
			};

			pointer				_predecessor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_left){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_left) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_left; while (_nxt->_right) _nxt = _nxt->_right; }
				return			_nxt;
			};

		public:
			constMapIterator(void)														: _ptr(0) {};
			constMapIterator(const pointer _cpy)										: _ptr(_cpy) {};
			constMapIterator(const constMapIterator &_cpy)								{ *this = _cpy; };
			
			constMapIterator&	operator=(const constMapIterator &_cpy)					{ _ptr = _cpy._ptr; return (*this); };
			pointer				node(void)												{ return (_ptr); };
			value_type&			operator*(void)											{ return (_ptr->pair); };
			value_type*			operator->(void)										{ return (&_ptr->pair); };
			bool				operator==(const constMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr == _cpy._ptr); };
			bool				operator!=(const constMapIterator<_ty1, _ty2> &_cpy)	{ return (!(*this == _cpy)); };
			bool				operator>(const  constMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr >  _cpy._ptr); };
			bool				operator<(const  constMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr <  _cpy._ptr); };
			bool				operator>=(const constMapIterator<_ty1, _ty2> &_cpy) 	{ return (_ptr >= _cpy._ptr); };
			bool				operator<=(const constMapIterator<_ty1, _ty2> &_cpy) 	{ return (_ptr <= _cpy._ptr); };
			constMapIterator&	operator++(void)										{ _ptr = _successor(_ptr); return (*this); };
			constMapIterator	operator++(int)											{ constMapIterator _tmp(*this); this->operator++(); return (_tmp); };
			constMapIterator&	operator--(void)										{ _ptr = _predecessor(_ptr); return (*this); };
			constMapIterator	operator--(int)											{ constMapIterator _tmp(*this); this->operator--(); return (_tmp); };

	};

	template					<class _ty1, class _ty2>
	class						reverseMapIterator
	{
		public:
			typedef				std::pair<_ty1, _ty2>		value_type;
			typedef				std::pair<_ty1, _ty2>&		reference;
			typedef				BNode<_ty1, _ty2>*			pointer;

		protected:
			pointer				_ptr;
		
		private:
			pointer				_successor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_right){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_right) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_right; while (_nxt->_left) _nxt = _nxt->_left; }
				return			_nxt;
			};

			pointer				_predecessor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_left){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_left) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_left; while (_nxt->_right) _nxt = _nxt->_right; }
				return			_nxt;
			};

		public:
			reverseMapIterator(void)													: _ptr(0) {};
			reverseMapIterator(const pointer _cpy)										: _ptr(_cpy) {};
			reverseMapIterator(const reverseMapIterator &_cpy)							{ *this = _cpy; };
			
			reverseMapIterator&	operator=(const reverseMapIterator &_cpy)				{ _ptr = _cpy._ptr; return (*this); };
			pointer				node(void)												{ return (_ptr); };
			value_type&			operator*(void)											{ return (_ptr->pair); };
			value_type*			operator->(void)										{ return (&_ptr->pair); };
			bool				operator==(const reverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr == _cpy._ptr); };
			bool				operator!=(const reverseMapIterator<_ty1, _ty2> &_cpy)	{ return (!(*this == _cpy)); };
			bool				operator>(const  reverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr >  _cpy._ptr); };
			bool				operator<(const  reverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr <  _cpy._ptr); };
			bool				operator>=(const reverseMapIterator<_ty1, _ty2> &_cpy) 	{ return (_ptr >= _cpy._ptr); };
			bool				operator<=(const reverseMapIterator<_ty1, _ty2> &_cpy) 	{ return (_ptr <= _cpy._ptr); };
			reverseMapIterator&	operator++(void)										{ _ptr = _successor(_ptr); return (*this); };
			reverseMapIterator	operator++(int)											{ reverseMapIterator _tmp(*this); this->operator++(); return (_tmp); };
			reverseMapIterator&	operator--(void)										{ _ptr = _predecessor(_ptr); return (*this); };
			reverseMapIterator	operator--(int)											{ reverseMapIterator _tmp(*this); this->operator--(); return (_tmp); };

	};

	template					<class _ty1, class _ty2>
	class						constReverseMapIterator
	{
		public:
			typedef				std::pair<_ty1, _ty2>		value_type;
			typedef				std::pair<_ty1, _ty2>&		reference;
			typedef				BNode<_ty1, _ty2>*			pointer;

		protected:
			pointer				_ptr;
		
		private:
			pointer				_successor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_right){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_right) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_right; while (_nxt->_left) _nxt = _nxt->_left; }
				return			_nxt;
			};

			pointer				_predecessor(pointer _ptr)
			{
				pointer			_nxt;
				if (!_ptr->_left){ _nxt = _ptr; while (_nxt->_parent && _nxt == _nxt->_parent->_left) _nxt = _nxt->_parent; _nxt = _nxt->_parent; }
				else			{ _nxt = _ptr->_left; while (_nxt->_right) _nxt = _nxt->_right; }
				return			_nxt;
			};

		public:
			constReverseMapIterator(void)													: _ptr(0) {};
			constReverseMapIterator(const pointer _cpy)										: _ptr(_cpy) {};
			constReverseMapIterator(const constReverseMapIterator &_cpy)					{ *this = _cpy; };
			
			constReverseMapIterator&	operator=(const constReverseMapIterator &_cpy)		{ _ptr = _cpy._ptr; return (*this); };
			pointer				node(void)													{ return (_ptr); };
			value_type&			operator*(void)												{ return (_ptr->pair); };
			value_type*			operator->(void)											{ return (&_ptr->pair); };
			bool				operator==(const constReverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr == _cpy._ptr); };
			bool				operator!=(const constReverseMapIterator<_ty1, _ty2> &_cpy)	{ return (!(*this == _cpy)); };
			bool				operator>(const  constReverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr >  _cpy._ptr); };
			bool				operator<(const  constReverseMapIterator<_ty1, _ty2> &_cpy)	{ return (_ptr <  _cpy._ptr); };
			bool				operator>=(const constReverseMapIterator<_ty1, _ty2> &_cpy) { return (_ptr >= _cpy._ptr); };
			bool				operator<=(const constReverseMapIterator<_ty1, _ty2> &_cpy) { return (_ptr <= _cpy._ptr); };
			constReverseMapIterator&	operator++(void)									{ _ptr = _successor(_ptr); return (*this); };
			constReverseMapIterator		operator++(int)										{ constReverseMapIterator _tmp(*this); this->operator++(); return (_tmp); };
			constReverseMapIterator&	operator--(void)									{ _ptr = _predecessor(_ptr); return (*this); };
			constReverseMapIterator		operator--(int)										{ constReverseMapIterator _tmp(*this); this->operator--(); return (_tmp); };

	};
	
}

# endif