#ifndef			REVERSE_ITERATOR_HPP
# define		REVERSE_ITERATOR_HPP

# include		"utils.hpp"

namespace		ft
{
	template	<class Itr>
	class		reverse_iterator
	{
	/*
	** ----------------------------------------------------------------------------------
	** TYPES
	*/
	public:
		typedef Itr        													iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type			value_type;
		typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer			pointer;
		typedef typename iterator_traits<iterator_type>::reference			reference;
	private:
		iterator_type	_it;

	public:
		/*
		** ----------------------------------------------------------------------------------
		** CONSTRUCTORS
		*/
		reverse_iterator() {}
		explicit reverse_iterator (iterator_type _itr) : _it(_itr) {}
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& _rev_itr) : _it(_rev_itr.base()) {}

		iterator_type base() const { return this->_it; }
		

		/*
		** ----------------------------------------------------------------------------------
		** OPERATORS: ASSIGNMENT: =, +=, -=
		*/
		template <class Iter>
		reverse_iterator&	operator=(const reverse_iterator<Iter> &_rev_itr)	{ this->_it = _rev_itr.base(); return (*this); }
		reverse_iterator&	operator+=(difference_type _num)					{ this->_it -= _num; return (*this); }
		reverse_iterator&	operator-=(difference_type _num)					{ this->_it += _num; return (*this); }

		/*
		** ----------------------------------------------------------------------------------
		** OPERATORS: MEMBER ACCESS: *, ->
		*/
		reference   		operator*() const									{ iterator_type _tmp = this->_it; return (*--_tmp); }
		pointer				operator->() const									{ return &(operator*()); }
		reference			operator[](difference_type _num) 					{ return (this->_it[-_num-1]); }

		/*
		** ----------------------------------------------------------------------------------
		** OPERATORS: INC/DEC: ++, --
		*/
		reverse_iterator&   operator++() 										{ --this->_it; return (*this); }
		reverse_iterator    operator++(int)										{ reverse_iterator _tmp = *this; --this->_it; return (_tmp); }
		reverse_iterator&   operator--()										{ ++this->_it; return *this; }
		reverse_iterator    operator--(int)										{ reverse_iterator _tmp = *this; ++this->_it; return (_tmp); }

		/*
		** ----------------------------------------------------------------------------------
		** OPERATORS: ARITHMETIC: +, -
		*/
		reverse_iterator	operator+(difference_type _num) const				{ return (reverse_iterator(this->_it - _num)); }
		reverse_iterator	operator-(difference_type _num) const				{ return (reverse_iterator(this->_it + _num)); }
	};

	template	<class Itr>
	reverse_iterator<Itr>
				operator+	(typename reverse_iterator<Itr>::difference_type n, const reverse_iterator<Itr>& rev_it) 
				{ reverse_iterator<Itr> tmp(rev_it); tmp += n; return tmp; }
	template	<class Itr>
	typename reverse_iterator<Itr>::difference_type
				operator-	(const reverse_iterator<Itr>& _ar1, const reverse_iterator<Itr>& _ar2)
				{ return _ar2.base() - _ar1.base(); }
	template	<class It1, class It2>
	typename reverse_iterator<It1>::difference_type
				operator-	(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar2.base() - _ar1.base(); }
	
	template	<class It1, class It2>
	bool		operator==		(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() == _ar2.base(); }
	template	<class It1, class It2>
	bool		operator!=		(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() != _ar2.base(); }
	template	<class It1, class It2>
	bool		operator< 		(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() > _ar2.base(); }
	template	<class It1, class It2>
	bool		operator<=		(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() >= _ar2.base(); }
	template	<class It1, class It2>
	bool		operator>		(const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() < _ar2.base(); }
	template	<class It1, class It2>
	bool		operator>= (const reverse_iterator<It1>& _ar1, const reverse_iterator<It2>& _ar2)
				{ return _ar1.base() <= _ar2.base(); }
}
#endif
