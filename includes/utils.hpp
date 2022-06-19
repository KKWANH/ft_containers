#ifndef			ITERATORS_TRAITS_HPP
# define		ITERATORS_TRAITS_HPP

namespace		ft
{
	/*
	** ----------------------------------------------------------------------------------
	** ITERATOR_TRAITS
	*/
	template	<class Itr>
	class		iterator_traits
	{
	public:
		typedef typename Itr::difference_type		difference_type;
		typedef typename Itr::value_type			value_type;
		typedef typename Itr::pointer				pointer;
		typedef typename Itr::reference			reference;
		typedef typename Itr::iterator_category	iterator_category;
	};


	/*
	** ----------------------------------------------------------------------------------
	** ENABLE_IF
	*/
	template	<bool Cond>
	struct		enable_if		{};

	template	<>
	struct		enable_if<true>	{ typedef int type; };

	/*
	** ----------------------------------------------------------------------------------
	** IS_INTEGRAL
	*/
	template	<class T>
	struct		is_integral
	{ static const bool	value = false; };
	
	template <>	struct is_integral<bool>					{ static const bool value = true; };
	template <>	struct is_integral<char>					{ static const bool value = true; };
	template <>	struct is_integral<wchar_t>					{ static const bool value = true; };
	template <>	struct is_integral<signed char>				{ static const bool value = true; };
	template <>	struct is_integral<short int>				{ static const bool value = true; };
	template <>	struct is_integral<int>						{ static const bool value = true; };
	template <>	struct is_integral<long int>				{ static const bool value = true; };
	template <>	struct is_integral<long long int>			{ static const bool value = true; };
	template <>	struct is_integral<unsigned char>			{ static const bool value = true; };
	template <>	struct is_integral<unsigned short int>		{ static const bool value = true; };
	template <>	struct is_integral<unsigned int>			{ static const bool value = true; };
	template <>	struct is_integral<unsigned long int>		{ static const bool value = true; };
	template <>	struct is_integral<unsigned long long int>	{ static const bool value = true; };

	/*
	** ----------------------------------------------------------------------------------
	** LEXICOGRAPHICAL_COMPARE
	*/
	template< class Itr1, class Itr2 >
	bool lexicographical_compare(Itr1 first1, Itr1 last1, Itr2 first2, Itr2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
	
	/*
	** ----------------------------------------------------------------------------------
	** LESS
	*/
	template<class T>
	struct less
	{
		bool operator () (const T& lhs, const T& rhs) const {
			return (lhs < rhs);
		}
	};
	
}

#endif
