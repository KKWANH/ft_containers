/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:18:28 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 14:26:23 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						LIST_HPP
# define						LIST_HPP

# include						"listIterator.hpp"
# include						<memory>
# include						<limits>

namespace						ft
{
	template					<class Typ, class Alc=std::allocator<Typ> >
	class						list
	{
		public:
			typedef				Typ												value_type;
			typedef				Alc												allocator_type;
			typedef				Typ&											reference;
			typedef				const Typ&										const_reference;
			typedef				Typ*											pointer;
			typedef				const Typ*										const_pointer;
			typedef				unsigned long									size_type;
			typedef				Node<value_type>*								node;
			typedef				listIterator<value_type>						iterator;
			typedef				constListIterator<value_type>					const_iterator;
			typedef				reverseListIterator<value_type>					reverse_iterator;
			typedef				constReverseListIterator<value_type>			const_reverse_iterator;

		private:
			node				_list_begin;
			node				_list_end;
			allocator_type		_allocator;
			size_t				_length;

			Node<value_type>*	_new_node(value_type _val, Node<value_type>* _prv, Node<value_type>* _nxt)
			{
				node			_nod = new Node<value_type>();
				_nod->_val = _val;
				_nod->_prv = _prv;
				_nod->_nxt = _nxt;
				return			(_nod);
			};

			void				_init_list(void)
			{
				_list_begin = _new_node(value_type(), 0, 0);
				_list_end = _new_node(value_type(), _list_begin, 0);
				_list_begin->_nxt = _list_end;
			};

			template			<typename Num>
			struct				_Smaller
			{
				bool			operator()(const Num& _ar1, const Num& _ar2)
				{
					return		(_ar1 > _ar2);
				};
			};

			template			<typename Num>
			struct				_Equal
			{
				bool			operator()(const Num& _ar1, const Num& _ar2)
				{
					return		(_ar1 == _ar2);
				};
			};
		
		public:
			explicit			list(const allocator_type& _alc = allocator_type())
			:					_list_begin(0),
								_list_end(0),
								_allocator(_alc),
								_length(0)
			{
				_init_list();
			};

			explicit			list(size_type _num, const value_type& _val = value_type(), const allocator_type& _alc = allocator_type())
			:					_list_begin(0),
								_list_end(0),
								_allocator(_alc),
								_length(0)
			{
				_init_list();
				assign(_num, _val);
			};

			template			<typename InputItr>
			list(InputItr _stt, InputItr _end, const allocator_type& _alc = allocator_type())
			:					_list_begin(0),
								_list_end(0),
								_allocator(_alc),
								_length(0)
			{
				_init_list();
				assign(_stt, _end);
			};

			list(const list& _cpy)
			:					_list_begin(0),
								_list_end(0),
								_allocator(_cpy._allocator),
								_length(0)
			{
				_init_list();
				*this = _cpy;
			};

			~list(void)
			{
				clear();
				delete			_list_begin;
				delete			_list_end;
			};

			list&				operator=(const list& _cpy)
			{
				clear();
				assign(_cpy.begin(), _cpy.end());
				_length = _cpy._length;
				return			(*this);
			};

			iterator			begin(void)										{ return (iterator(_list_begin->_nxt)); };
			const_iterator		begin(void) const								{ return (const_iterator(_list_begin->_nxt)); };
			iterator			end(void)										{ return (iterator(_list_end)); };
			const_iterator		end(void) const									{ return (const_iterator(_list_end)); };
			reverse_iterator	rbegin(void)									{ return (reverse_iterator(_list_end->_prv)); };
			const_reverse_iterator
								rbegin(void) const								{ return (const_reverse_iterator(_list_end->_prv)); };
			reverse_iterator	rend(void)										{ return (reverse_iterator(_list_begin)); };
			const_reverse_iterator
								rend(void) const								{ return (const_reverse_iterator(_list_begin)); };
			bool				empty(void) const								{ return (_length == 0); };
			size_type			size(void) const								{ return (_length); };
			size_type			max_size(void) const							{ return (std::numeric_limits<size_type>::max() / (sizeof(Node<Typ>))); };
			reference			front(void)										{ return (_list_begin->_nxt->_val); };
			const_reference		front(void) const								{ return (_list_begin->_nxt->_val); };
			reference			back(void)										{ return (_list_end->_prv->_val); };
			const_reference		back(void) const								{ return (_list_end->_prv->_val); };

			template			<typename InputItr>
			void				assign(InputItr _stt, InputItr _end)
			{
				clear();
				while (_stt != _end)
					push_back(*(_stt++));
			};

			void				assign(size_type _num, const value_type& _val)
			{
				clear();
				while (_num--)
					push_back(_val);
			};

			void				push_front(const value_type& _val)
			{
				node			_nod = _new_node(_val, _list_begin, _list_begin->_nxt);
				_list_begin->_nxt->_prv = _nod;
				_list_begin->_nxt = _nod;
				++_length;
			};

			void				pop_front(void)
			{
				node			_nxt = _list_begin->_nxt->_nxt;
				delete			_list_begin->_nxt;
				_list_begin->_nxt = _nxt;
				_nxt->_prv = _list_begin;
				--_length;
			};

			void				push_back(const value_type& _val)
			{
				node			_nod = _new_node(_val, _list_end->_prv, _list_end);
				_list_end->_prv->_nxt = _nod;
				_list_end->_prv = _nod;
				++_length;
			};

			void				pop_back(void)
			{
				node			_bef = _list_end->_prv->_prv;
				delete			_list_end->_prv;
				_bef->_nxt = _list_end;
				_list_end->_prv = _bef;
				--_length;
			};

			iterator			insert(iterator _pos, const value_type& _val)
			{
				if (_pos == begin())
				{
					push_front(_val);
					return		(begin());
				}
				if (_pos == end())
				{
					push_back(_val);
					return		(end());
				}

				node			_aft = _pos.node();
				node			_bef = _aft->_prv;
				node			_nod = _new_node(_val, _bef, _aft);

				_bef->_nxt = _nod;
				_aft->_prv = _nod;
				++_length;

				return			(iterator(_nod));
			};

			void				insert(iterator _pos, size_type _num, const value_type &_val)
			{
				while (_num--)
					_pos = insert(_pos, _val);
			};

			template			<typename InputIterator>
			void				insert(iterator _pos, InputIterator _stt, InputIterator _end)
			{
				while (_stt != _end)
				{
					_pos = insert(_pos, *(_stt++));
					if (_pos != end())
						++_pos;
				}
			};

			iterator			erase(iterator _pos)
			{
				if (_pos == begin())
				{
					pop_front();
					return		(begin());
				}
				if (_pos == end())
				{
					pop_back();
					return		(end());
				}

				node			_nxt = _pos.node()->_nxt;
				node			_prv = _pos.node()->_prv;
				delete			_pos.node();
				_prv->_nxt = _nxt;
				_nxt->_prv = _prv;
				--_length;

				return			(iterator(_nxt));
			};

			iterator			erase(iterator _stt, iterator _end)
			{
				while (_stt != _end)
					erase(_stt++);
				return			(_stt);
			};

			void				swap(list& _cpy)
			{
				ft::swap(_cpy._length, _length);
				ft::swap(_cpy._list_begin, _list_begin);
				ft::swap(_cpy._list_end, _list_end);	
			};
			
			void				resize(size_type _num, value_type _val = value_type())
			{
				while (_num < _length)
					pop_back();
				while (_num > _length)
					push_back(_val);
			};

			void				clear(void)
			{
				node			_cur = _list_begin->_nxt;
			
				while (_cur != _list_end)
				{
					node		_nxt = _cur->_nxt;
					delete		_cur;
					_cur = _nxt;
				}
				_list_begin->_nxt = _list_end;
				_list_end->_prv = _list_begin;
				_length = 0;
			};
			
			void				splice(iterator _pos, list& _cpy)
			{
				splice(_pos, _cpy, _cpy.begin(), _cpy.end());
			};

			void				splice(iterator _pos, list& _cpy, iterator _idx)
			{
				insert(_pos, *_idx);
				_cpy.erase(_idx);
			};
			void				splice(iterator _pos, list& _cpy, iterator _stt, iterator _end)
			{
				insert(_pos, _stt, _end);
				_cpy.erase(_stt, _end);
			};

			void				remove(const value_type& _val)
			{
				iterator		_cur = begin();

				while (_cur != end())
				{
					if (*_cur == _val)
						_cur = erase(_cur);
					else
						++_cur;
				}
			};
			template			<class Pred>
			void				remove_if(Pred _prd)
			{
				iterator		_cur = begin();

				while (_cur != end())
				{
					if (_prd(*_cur))
						_cur = erase(_cur);
					else
						++_cur;
				}
			};

			void				unique(void)
			{
				unique(_Equal<value_type>());
			};
			template			<class BinaryPredicate>
			void				unique(BinaryPredicate binary_pred)
			{
				iterator		_prv = begin();
				iterator		_nxt = _prv;

				while (_nxt + 1 != end())
				{
					++_nxt;
					if (binary_pred(*_prv, *_nxt))
					{
						erase(_nxt);
						_nxt = _prv;
					}
					else
						_prv = _nxt;
				}
			};

			void				merge(list& _cpy)
			{
				merge(_cpy, _Smaller<value_type>());
			};
			template			<class Compare>
			void				merge(list& _cpy, Compare _cmp)
			{
				if (&_cpy == this)
					return;
				insert(end(), _cpy.begin(), _cpy.end());
				_cpy.clear();
				sort(_cmp);
			};

			void				sort(void)
			{
				sort(_Smaller<value_type>());
			};
			template			<class Compare>
			void				sort(Compare _cmp)
			{
				iterator		_it1 = begin();
				iterator		_it2;

				while (_it1 + 1 != end())
				{
					_it2 = _it1 + 1;
					while (_it2 != end())
					{
						if (_cmp(*_it1, *_it2))
							ft::swap(*_it1, *_it2);
						++_it2;
					}
					++_it1;
				}
			};

			void				reverse(void)
			{
				list<value_type> _tmp;
				iterator		 _itr = begin();

				while (_itr != end())
					_tmp.push_front(*(_itr++));
				*this = _tmp;
			};
	};

	template					<class Typ, class Alc>
	void						swap(list<Typ, Alc>& _ar1, list<Typ, Alc>& _ar2)
	{
		_ar1.swap(_ar2);
	};

	template					<class Typ>
	bool						operator==(list<Typ> const& _ar1, list<Typ> const& _ar2)
	{
		if (_ar1.size() != _ar2.size())
			return (false);
		typename				list<Typ>::const_iterator _cu1 = _ar1.begin();
		typename				list<Typ>::const_iterator _cu2 = _ar2.begin();
		while (_cu1 != _ar1.end())
			if (*(_cu1++) != *(_cu2++))
				return			(false);
		return					(true);
	};

	template					<class Typ>
	bool						operator!=(list<Typ> const& _ar1, list<Typ> const& _ar2)
	{
		return					(!(_ar1 == _ar2));
	};

	template					<class Typ>
	bool						operator<(list<Typ> const _ar1, list<Typ> const _ar2)
	{
		if (_ar1.size() < _ar2.size())
			return				(true);
		if (_ar1.size() > _ar2.size())
			return				(false);
		
		typename				list<Typ>::const_iterator _cu1 = _ar1.begin();
		typename				list<Typ>::const_iterator _cu2 = _ar2.begin();
		while (_cu1 != _ar1.end())
		{
			if (*_cu1 != *_cu2)
				return			(*_cu1 < *_cu2);
			++_cu1;
			++_cu2;
		}
		return					(false);
	};

	template					<class Typ>
	bool						operator>(list<Typ> const _ar1, list<Typ> const _ar2)
	{
		return					(_ar2 < _ar1);
	};

	template					<class Typ>
	bool						operator<=(list<Typ> const _ar1, list<Typ> const _ar2)
	{
		return					(!(_ar2 < _ar1));
	};

	template					<class Typ>
	bool						operator>=(list<Typ> const _ar1, list<Typ> const _ar2)
	{
		return					(!(_ar1 < _ar2));
	};
};

# endif