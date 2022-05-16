#ifndef			UTILS_HPP
# define		UTILS_HPP

# include		"iterator.hpp"
# include		<type_traits>

namespace		ft
{

	// --------------------------------------------------------
	// ****** Basic Operator starts
	// : functions
	//   swap(a1, a2) 
	//   max(a1, a2)
	//   min(a1, a2)
	template	<class TE>
	void		swap(
		TE &_arg1,
		TE &_arg2)
	{
		TE _tmp(_arg1);
		_arg1 = _arg2;
		_arg2 = _tmp;
	}

	template	<typename TE>
	TE		max(
		TE _arg1,
		TE _arg2)
	{
		return
			(_arg1 > _arg2) ? _arg1 : _arg2;
	}

	template	<typename TE>
	TE		min(
		TE &_arg1,
		TE &_arg2)
	{
		return
			(_arg1 < _arg2) ? _arg1 : _arg2;
	}
	// ****** Basic Operator ends
	// --------------------------------------------------------

	// ****** Pair starts
	// --------------------------------------------------------
	// : structs
	//   pair<T1, T2>
	// : operators
	//   ==
	//   !=
	//   <
	//   >
	//   <=
	//   >=
	// : functions
	//   make_pair(T1, T2)
	template	<class T1, class T2>
	struct		pair
	{
		typedef T1 type_1st;
		typedef T2 type_2nd;

		type_1st first;
		type_2nd second;

		pair()
		:	first(). second()
		{};

		pair(
			const T1& _arg1,
			const T2& _arg2)
		:	first(_arg1), second(_arg2)
		{};

		template	<class T3, class T4>
		pair(
			const pair<T3, T4>& _arg)
		:	first(_arg.first), second(_arg.second)
		{};

		pair& operator=(const pair& _arg)
		{
			first = _arg.first;
			second = _arg.second;
			return *this;
		};
	};

	template	<class T1, class T2>
	bool		operator==(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return (_arg1.first == _arg2.first) && (_arg1.second == _arg2.second); };

	template	<class T1, class T2>
	bool		operator!=(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return !(_arg1 == _arg2); };

	template	<class T1, class T2>
	bool		operator<(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return (_arg1.first < _arg2.first) || (!(_arg1.first < _arg2.first) && (_arg1.second < _arg2.second)); };

	template	<class T1, class T2>
	bool		operator<=(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return !(_arg2 < _arg1); };

	template	<class T1, class T2>
	bool		operator>(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return (_arg2 < _arg1); };

	template	<class T1, class T2>
	bool		operator>(
		const	pair<T1,T2>& _arg1,
		const	pair<T1,T2>& _arg2)
	{ return !(_arg1 < _arg2); };

	template	<class T1, class T2>
	pair<T1,T2>	make_pair (
		T1		_arg1,
		T2		_arg2)
	{ return pair<T1,T2>(_arg1, _arg2); };
	// ****** Pair ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** enable_if starts
	// : structs
	//	 enable_if<bool, class>
	template	<bool B, class T>
	struct		enable_if
	{};

	template	<class T>
	struct		enable_if<true, T>
	{ typedef T type; };
	// ****** enable_if ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** is_integral starts
	template	<class T>	struct is_integral							: std::false_type {};
	template	<>			struct is_integral<bool>					: std::true_type {};
	template	<>			struct is_integral<char>					: std::true_type {};
	template	<>			struct is_integral<wchar_t>					: std::true_type {};
	template	<>			struct is_integral<char16_t>				: std::true_type {};
	template	<>			struct is_integral<char32_t>				: std::true_type {};
	template	<>			struct is_integral<signed char>				: std::true_type {};
	template	<>			struct is_integral<unsigned char>			: std::true_type {};
	template	<>			struct is_integral<short int>				: std::true_type {};
	template	<>			struct is_integral<int>						: std::true_type {};
	template	<>			struct is_integral<long int>				: std::true_type {};
	template	<>			struct is_integral<long long int>			: std::true_type {};
	template	<>			struct is_integral<unsigned int>			: std::true_type {};
	template	<>			struct is_integral<unsigned short int>		: std::true_type {};
	template	<>			struct is_integral<unsigned long int>		: std::true_type {};
	template	<>			struct is_integral<unsigned long long int>	: std::true_type {};
	// ****** is_integral ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** lexicographical compare starts
	// : functions
	//   lexicographical_compare(Itr1(first, last), Itr2(first, last))
	//   lexicographical_compare(Itr1(first, last), Itr2(first, last), Compare)
	template	<class It1, class It2>
	bool		lexicographical_compare(
		It1		_fst1,	It1		_lst1,
		It2		_fst2,	It2		_lst2)
	{
		for (; (_fst1 != _lst1) && (_fst2 != _lst2); ++_fst1, ++_fst2)
		{
			if (*_fst1 < *_fst2)		return true;
			else if (*_fst2 < *_fst1)	return false;
		}
		return (_fst1 == _lst1) && (_fst2 != _lst2);
	};

	template	<class It1, class It2, class Comp>
	bool		lexicographical_compare(
		It1		_fst1,	It1		_lst1,
		It2		_fst2,	It2		_lst2,
		Comp	_comp)
	{
		for (; (_fst1 != _lst1) && (_fst2 != _lst2); ++_fst1, ++_fst2)
		{
			if (_comp(*_fst1, *_fst2))		return true;
			else if (_comp(*_fst2, *_fst1))	return false;
		}
		return (_fst1 == _lst1) && (_fst2 != _lst2);
	};
	// ****** lexicographical compare ends
	// --------------------------------------------------------

	// --------------------------------------------------------
	// ****** equal starts
	//   equal(Itr1(first, last), Itr2(first))
	//   equal(Itr1(first, last), Itr2(first), BynaryPredicate)
	template	<class It1, class It2>
	bool		equal(
		It1		_fst1,
		It1		_lst1,
		It2		_fst2)
	{
		for (; _fst1 != _lst1; ++_fst1, ++_fst2)
			if (*_fst1 != *_fst2)
				return false;
		return true;
	};

	template	<class It1, class It2, class Pred>
	bool		equal(
		It1		_fst1,
		It1		_lst1,
		It2		_fst2,
		Pred	_pred)
	{
		for (; _fst1 != _lst1; ++_fst1, ++_fst2)
			if (!_pred(*_fst1, *_fst2))
				return false;
		return true;
	};
	// ****** equal ends
	// --------------------------------------------------------
};
#endif