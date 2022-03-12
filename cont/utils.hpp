/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkim <kkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:06:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/03/12 17:31:50 by kkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						UTILS_HPP
# define						UTILS_HPP

# include						<exception>
# include						<iostream>

namespace						ft
{
	template					<typename _tp1, typename _tp2>
	class						pair
	{
		public:
			/**
			--------------------------------------------------
			- class pair : parameter part.
			--------------------------------------------------
			*/
			_tp1				first;
			_tp2				second;

			/**
			--------------------------------------------------
			- constructor & destructor part
			-
			- const : void
			- const : tp1, tp2
			- const : pair<tp1, tp2>
			- const : diffrent pair<tp3,tp4>
			- dest  : void
			--------------------------------------------------
			*/
			pair(void)
			:	first(), second() { };

			pair(const _tp1& _ar1, const _tp2& _ar2)
			:	first(_ar1), second(_ar2) { };

			pair(const pair<_tp1, _tp2>& _cpy)
			:	first(_cpy.first), second(_cpy.second) { };
			
			template			<typename _tp3, typename _tp4>
			pair(const pair<_tp3, _tp4>& _cpy)
			:	first(_cpy.first), second(_cpy.second) { }

			~pair(void) {};

			/**
			--------------------------------------------------
			- operator assignment
			--------------------------------------------------
			*/
			pair&
				operator=(
				const pair& _assign)
				{
					if (this != &_assign)
					{
						first	= _assign.first;
						second	= _assign.second;
					}
					return (*this);
				}
	};

	template					<class _cl1>
	class						allocator
	{
		public:
			/**
			--------------------------------------------------
			- class pair : parameter part.
			--------------------------------------------------
			*/
			typedef				_cl1			value_type;
			typedef				_cl1*			pointer;
			typedef				_cl1&			reference;
			typedef				const _cl1*		const_pointer;
			typedef				const _cl1&		const_reference;
			typedef 			size_t			size_type;
			typedef				long int		difference_type;

			/**
			--------------------------------------------------
			- constructor & destructor part
			-
			- const : void : throw
			- const : allocator& : throw
			- const : allocator<cl2>& : throw
			- dest  : void : throw
			--------------------------------------------------
			*/
			allocator(
				void)
				throw()
				{};

			allocator(
				const allocator&)
				throw()
				{};
			
			template			<class _cl2>
			allocator(
				const allocator<_cl2>&)
				throw()
				{};
			
			~allocator(void)
				throw()
				{};
			
			/**
			--------------------------------------------------
			- member functions
			- 
			- address : reference : return it as pointer
			- address : const_reference : same
			- allocate : size_type
			- deallocate : pointer, size_type
			- construct : pointer, const _cl1&
			- destroy : pointer
			--------------------------------------------------
			*/
			pointer
				address(
					reference _ref) const
				{	return (&_ref); };
			
			const_pointer
				address(
					const_reference _ref) const
				{	return (&_ref); };
			
			pointer
				allocate(
					size_type _num)
				{
					pointer
						_rst;
					size_t
						_siz = _num * sizeof(value_type);
					
					try
					{	_rst = reinterpret_cast<pointer>(::operator new(_siz)); }
					catch (const std::exception& _exc)
					{	std::cerr << _exc.what() << "\n"; }
					return (_rst);
				}
			
			void
				deallocate(
					pointer _ptr,
					size_type _num)
				{
					(void)_num;
					::operator delete(_ptr);
				}
			
			void
				construct(
					pointer _ptr,
					const _cl1& _tmp)
				{	new((void *)_ptr)_cl1(_tmp); }
			
			void
				destroy(
					pointer _ptr)
				{	_ptr->~_cl1(); }
	};

	template					<class _cl1>
	struct						less
	{
		typedef	_cl1			first_argument_type;
		typedef	_cl1			second_argument_type;
		typedef	bool			result_typ;

		bool
			operator() (
				const _cl1& _ar1,
				const _cl1& _ar2) const
			{	return _ar1<_ar2; }
	};

	template					<class _cl1, class _cl2>
	pair<_cl1, _cl2>
		make_pair(
			_cl1 _ar1,
			_cl1 _ar2) const
		{	return pair<_cl1, _cl2>(_ar1, _ar2); }

	template					<typename _typ>
	void						swap(_typ &_ar1, _typ &_ar2)
	{
		_typ					_tmp = _ar1;
		_ar1 = _ar2;
		_ar2 = _tmp;
	}

	template					<typename _typ>
	struct						Node
	{
		_typ					_val;
		Node					*_prv;
		Node					*_nxt;
	};

	template					<class _key, class _typ>
	struct						BNode
	{
		ft::pair<_key, _typ>	pair;
		BNode					*_left;
		BNode					*_right;
		BNode					*_parent;
		bool					_end;
	};
}

# endif