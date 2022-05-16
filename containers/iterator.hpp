#ifndef			ITERATOR_HPP
# define		ITERATOR_HPP

# include		"utils.hpp"

namespace		ft
{
	// --------------------------------------------------------
	// ****** Iterator traits starts
	// : structs
	//   iterator_traits<ITR>
	//   iterator_traits<T*>
	//   iterator_traits<const T*>
	template	<class ITR>
	struct 		iterator_traits
	{
		typedef	typename ITR::difference_type		difference_type;
		typedef	typename ITR::value_type			value_type;
		typedef	typename ITR::pointer				pointer;
		typedef	typename ITR::reference				reference;
		typedef	typename ITR::iterator_category		iterator_category;
	};

	template	<class T>
	struct 		iterator_traits<T*>
	{
		typedef	std::ptrdiff_t						difference_type;
		typedef	T									value_type;
		typedef	T*									pointer;
		typedef	T& 									reference;
		typedef	std::random_access_iterator_tag		iterator_category;
	};

	template	<class T>
	struct 		iterator_traits<const T*>
	{
		typedef std::ptrdiff_t  					difference_type;
		typedef T               					value_type;
		typedef const T*        					pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
	// ****** Iterator traits ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** Reverse iterator starts
	// : class
	//   reverse_iterator<ITR>
	//   - defines
	//	   iterator_type
	//	   iterator_category
	//	   value_type
	//	   difference_type
	//	   pointer
	//	   reference
	//   - privates
	//	   base_iterator
	//   - constructors
	//	   reverse_iterator()
	//	   reverse_iterator(iterator_type) - explicit
	//	   reverse_iterator(const reverse_iterator<T>&) - copy
	//   - functions
	//	   base()
	//	 - operators
	//	   *
	//	   ->
	//	   []
	//	   +
	//	   ++(2)
	//	   +=
	//	   -
	//	   --(2)
	//	   -=
	template	<class ITR>
	class 		reverse_iterator
	{
	public:
		typedef	ITR																iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category		iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef typename iterator_traits<iterator_type>::reference				reference;

	private:
		iterator_type	base_iterator;

	public:
		reverse_iterator()
		: base_iterator() {};

		explicit reverse_iterator(iterator_type _itr)
		: base_iterator(_itr) {};

		template <class T>
		reverse_iterator(const reverse_iterator<T>& _itr)
		: base_iterator(_itr.base()) {};

		iterator_type base() const
		{ return base_iterator; };

		reference operator*() const
		{ return *(base_iterator - 1); };

		pointer operator->() const
		{ return &(operator*()); };

		reference operator[] (difference_type _n) const
		{ return base()[ - n - 1] };
		
		reverse_iterator operator+ (difference_type _n) const
		{ return reverse_iterator(base_iterator - _n); };

		reverse_iterator& operator++ ()
		{ base_iterator--; return *this; };

		reverse_iterator operator++ (int)
		{ reverse_iterator tmp(*this); base_iterator--; return tmp; };

		reverse_iterator operator+= (difference_type _n) const
		{ base_iterator -= _n; return *this; };

		reverse_iterator operator- (difference_type _n) const
		{ return reverse_iterator(base_iterator + _n); };

		reverse_iterator& operator-- ()
		{ base_iterator++; return *this; };

		reverse_iterator operator-- (int)
		{ reverse_iterator tmp(*this); base_iterator++; return tmp; };

		reverse_iterator operator-= (difference_type _n) const
		{ base_iterator += _n; return *this; };
	};
	// ****** Reverse iterator ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** Iterator operator starts
	// : operators
	//   ==
	//   !=
	//   <
	//   >
	//   <=
	//   >=
	//   +
	//   -
	template	<class ITR>
	bool		operator== (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(_itr1.base() == _itr2.base());
	};

	template	<class ITR>
	bool		operator!= (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(_itr1.base() != _itr2.base());
	};

	template	<class ITR>
	bool		operator< (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(itr1.base() > _itr2.base());
	};

	template	<class ITR>
	bool		operator> (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(itr1.base() < _itr2.base());
	};

	template	<class ITR>
	bool		operator<= (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(itr1.base() >= _itr2.base());
	};

	template	<class ITR>
	bool		operator>= (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(itr1.base() <= _itr2.base());
	};

	template	<class ITR>
	reverse_iterator<ITR> operator+ (
		typename reverse_iterator<ITR>::difference_type _num,
		const	 reverse_iterator<ITR>& _rv_itr)
	{
		return	reverse_iterator<ITR>(_rv_itr + _num);
	};

	template	<class ITR>
	typename	reverse_iterator<ITR>::difference_type operator- (
		const	reverse_iterator<ITR>& _itr1,
		const	reverse_iterator<ITR>& _itr2)
	{
		return	(_itr1.base() - _itr2.base());
	};
	// ****** Iterator operator ends
	// --------------------------------------------------------
};

#endif