/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 00:14:22 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/05 17:53:10 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						VECTOR_HPP
# define						VECTOR_HPP

# include						<iostream>
# include						<memory>
# include						<limits>
# include						"vectorIterator.hpp"
# include						"utils.hpp"

namespace						ft
{
	template					<typename Typ, typename Alc = std::allocator<Typ> >
	class						vector
	{
		public:
			typedef				Typ												value_type;
			typedef				Alc												allocator_type;
			typedef				Typ&											reference;
			typedef				const Typ&										const_reference;
			typedef				Typ*											pointer;
			typedef				const Typ*										const_pointer;
			typedef				ft::vectorIterator<Typ>							iterator;
			typedef				ft::constVectorIterator<Typ>					const_iterator;
			typedef				ft::reverseVectorIterator<Typ>					reverse_iterator;
 			typedef				ft::constReverseVectorIterator<Typ>				const_reverse_iterator;
			typedef				unsigned long									size_type;
		
		private:
			size_type			_container_length;
			size_type			_container_size;
			pointer				_container;
			allocator_type		_allocator;
		
		public:
			explicit			vector(const allocator_type &_alc = allocator_type())
								: _container_length(0), _container_size(0), _container(nullptr), _allocator(_alc)
			{
				_container = _allocator.allocate(0);
			};

			template			<class inputIterator>
			vector(inputIterator _stt, inputIterator _end, const allocator_type &_alc = allocator_type())
								: _container_length(0), _container_size(0), _container(nullptr), _allocator(_alc)
			{
				_container = _allocator.allocate(0);
				assign(_stt, _end);
			};

			vector(size_type _num, const_reference _val = value_type(), const allocator_type& _alc = allocator_type())
								: _container_length(0), _container_size(0), _container(nullptr), _allocator(_alc)
			{
				_container = _allocator.allocate(0);
				assign(_num, _val);
			};

			vector(const vector &_cpy)
								: _container_length(0), _container_size(0), _container(nullptr), _allocator(_cpy._allocator)
			{
				*this = _cpy;
			};

			~vector(void)
			{
				_allocator.deallocate(_container, _container_size);
			}

			vector&				operator=(const vector& _cpy)
			{
				if (_container != 0)
					_allocator.deallocate(_container, _container_size);
				_allocator = _cpy._allocator;
				_container_size = 0;
				_container_length = 0;
				_container = _allocator.allocate(0);
				assign(_cpy.begin(), _cpy.end());
				return			(*this);
			}

			reference			operator[](size_type _num)  					{ return _container[_num]; };
			const_reference		operator[](size_type _num) const				{ return _container[_num]; };
			iterator			begin(void)										{ return iterator(_container); };
			const_iterator		begin(void) const								{ return const_iterator(_container); };
			iterator			end(void)										{ return iterator(_container + _container_length); };
			const_iterator		end(void) const									{ return const_iterator(_container + _container_length); };
			reverse_iterator	rbegin(void)									{ return reverse_iterator(_container + _container_length - 1); };
			reverse_iterator	rend(void)										{ return reverse_iterator(_container - 1); };
			const_reverse_iterator
								rbegin(void) const								{ return const_reverse_iterator(_container + _container_length - 1); };
			const_reverse_iterator
								rend(void) const								{ return const_reverse_iterator(_container - 1); };

			void				reserve(size_type _num)
			{
				if (_num > _container_size)
				{
					size_type	_idx = -1;
					pointer		_tmp;
					_tmp = _allocator.allocate(_num);
					_container_size = _num;
					while (++_idx < _container_length)
						_tmp[_idx] = _container[_idx];
					_allocator.deallocate(_container, _container_size);
					_container = _tmp;
				}
			};

			void				push_back(const value_type& _val)
			{
				if (_container_length + 1 > _container_size)
					reserve(_container_length + 1);
				_container[_container_length++] = _val;
			};

			size_type		size(void) const									{ return _container_length; };
			size_type		capacity(void) const								{ return _container_size; };
			bool			empty(void) const									{ return _container_length == 0; };
			
			iterator		insert(iterator _pos, const value_type& _val)
			{
				size_type	_idx = 0;
				iterator	_itr = begin();

				while (_itr + _idx != _pos && _idx < _container_length)
					++_idx;
				if (_container_size < _container_length + 1)
					reserve(_container_length + 1);
				size_type	_jdx= _container_size - 1;
				while (_jdx > _idx)
				{
					_container[_jdx] = _container[_jdx - 1];
					--_jdx;
				}
				_container[_idx] = _val;
				++_container_length;
				return			(iterator(&_container[_idx]));
			};

			void			insert(iterator _pos, size_type _num, const value_type& _val)
			{
				while (_num--)
					_pos = insert(_pos, _val);
			};

			template		<class inputIterator>
			void			insert(iterator _pos, inputIterator _stt, inputIterator _end)
			{
				while (_stt != _end)
				{
					_pos = insert(_pos, *_stt) + 1;
					++_stt;
				}
			};

			size_type		max_size(void) const
			{
				return		(std::numeric_limits<size_type>::max() / sizeof(value_type));
			};
			
			reference		at(size_type _num)
			{
				if (_num >= _container_length)
					throw	std::length_error("index out of bounds");
				return		(_container[_num]);
			};

			const_reference	at(size_type _num) const
			{
				if (_num >= _container_length)
					throw	std::length_error("index out of bounds");
				return		(_container[_num]);
			};

			iterator		erase(iterator _pos)
			{
				iterator	_cur = _pos;

				while (_cur + 1 != end())
				{
					*_cur = *(_cur + 1);
					++_cur;
				}
				--_container_length;
				return		(iterator(_pos));
			}; 

			iterator		erase(iterator _stt, iterator _end)
			{
				while (_stt != _end)
				{
					erase(_stt);
					--_end;
				}
				return		(iterator(_stt));
			};

			void			clear(void)
			{
				erase(begin(), end());
			};

			template		<class inputIterator>
			void			assign(inputIterator _stt, inputIterator _end)
			{
				clear();
				insert(begin(), _stt, _end);
			};

			void			assign(size_type _num, const value_type& _val)
			{
				clear();
				insert(begin(), _num, _val);
			};

			reference		front(void)											{ return _container[0]; };
			const_reference	front(void) const									{ return _container[0]; };
			reference		back(void)											{ return _container[_container_length - 1]; };
			const_reference	back(void) const									{ return _container[_container_length - 1]; };

			void			pop_back(void)
			{
				if (_container_length) --_container_length;
			};

			void			resize(size_type _num, value_type _val = value_type())
			{
				while (_num < _container_length)
					pop_back();
				while (_num > _container_length)
					push_back(_val);
			};

			void			swap(vector& _cpy)
			{
				ft::swap(_container, _cpy._container);
				ft::swap(_container_size, _cpy._container_size);
				ft::swap(_container_length, _cpy._container_length);
			};
	};

	template				<class Typ, class Alc>
	void					swap(vector<Typ, Alc>& _ar1, vector<Typ, Alc>& _ar2)
	{
		_ar1.swap(_ar2);
	};

	template				<class Typ, class Alc>
	bool					operator==(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		if (_ar1.size() != _ar2.size())
			return			(false);
		unsigned long		_idx = -1;
		while (++_idx < _ar1.size())
			if (_ar1[_idx] != _ar2[_idx])
				return		(false);
		return				(true);
	};

	template				<class Typ, class Alc>
	bool					operator!=(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		return				(!(_ar1 == _ar2));
	};

	template				<class Typ, class Alc>
	bool					operator<(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		size_t				_idx;
		size_t				_num;

		if (_ar1.size() > _ar2.size())
			_num = _ar2.size();
		else
			_num = _ar1.size();
		_idx = 0;
		while (_idx < _num)
		{
			if (_ar1.at(_idx) != _ar2.at(_idx))
				return		(_ar1.at(_idx) < _ar2.at(_idx));
			++_idx;
		}
		return				(_ar1.size() < _ar2.size());
	};

	template				<class Typ, class Alc>
	bool					operator<=(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		return				(_ar1 < _ar2 || _ar1 == _ar2);
	};

	template				<class Typ, class Alc>
	bool					operator>(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		return				(!(_ar1 <= _ar2));
	};

	template				<class Typ, class Alc>
	bool					operator>=(const vector<Typ, Alc>& _ar1, const vector<Typ, Alc>& _ar2)
	{
		return				(!(_ar1 < _ar2));
	};
};

# endif