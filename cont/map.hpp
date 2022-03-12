/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkim <kkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:19:57 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/03/12 17:33:01 by kkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						MAP_HPP
# define						MAP_HPP

# include						<memory>
# include						<functional>
# include						<limits>
# include						<utility>
# include						"mapIterator.hpp"

namespace						ft
{
	template					<class key, class typ, class cmp=ft::less<key>, class alc = ft::allocator<ft::pair<const key, typ> > >
	class						map
	{
		public:
			typedef				key												key_type;
			typedef				typ												mapped_type;
			typedef				ft::pair<const key_type, mapped_type>			value_type;
			typedef				alc												allocator_type;
			typedef				cmp												key_compare;
			typedef				typ&											reference;
			typedef				typ*											pointer;
			typedef				const typ&										const_reference;
			typedef				const typ*										const_pointer;
			typedef				unsigned long									size_type;
			typedef				BNode<key_type, mapped_type>*					node;
			typedef				mapIterator<key_type, mapped_type>				iterator;
			typedef				reverseMapIterator<key_type, mapped_type>		reverse_iterator;
			typedef				constMapIterator<key_type, mapped_type>			const_iterator;
			typedef				constReverseMapIterator<key_type, mapped_type>	const_reverse_iterator;
			
			class				value_compare
			{
				friend class	map;
				protected:
					cmp			_com;
					value_compare
								(cmp _tmp) : _com(_tmp) {}
					
				public:
					typedef		bool											result_type;
					typedef		value_type										first_argument_type;
					typedef		value_type										second_argument_type;
					bool		operator() (const value_type& _ar1, const value_type& _ar2) const
					{
						return		_com(_ar1.first, _ar2.first);
					}
			};

		private:
			allocator_type		_alc;
			key_compare			_cmp;
			node				_rot;
			size_type			_len;

			void				_debug_tree(node _nod)
			{
				if (!_nod) return ;
				_debug_tree(_nod->_left);
				if (_nod->_parent && !_nod->_end)
					std::cout << _nod->pair.first << "=" << _nod->pair.second << std::endl;
				_debug_tree(_nod->_right);
			};

			node				_new_node(key_type _key, mapped_type _val, node _par, bool _end = false)
			{
				node 			_tmp = new BNode<key_type, mapped_type>();
				_tmp->pair = ft::make_pair(_key, _val);
				_tmp->_left = 0;
				_tmp->_right = 0;
				_tmp->_parent = _par;
				_tmp->_end = _end;
				return			(_tmp);
			};

			void				_free_tree(node _nod)
			{
				if (_nod->_right)
					_free_tree(_nod->_right);
				if (_nod->_left)
					_free_tree(_nod->_left);
				delete			_nod;
			};

			node				_insert_node(node _nod, key_type _key, mapped_type _val, bool _end = false)
			{
				if (_nod->_end)
				{
					if (!_nod->_left)
					{
						_nod->_left = _new_node(_key, _val, _nod, _end);
						return	(_nod->_left);
					}
					return		(_insert_node(_nod->_left, _key, _val));
				}
				if (_key < _nod->pair.first && !_end)
				{
					if (!_nod->_left)
					{
						_nod->_left = _new_node(_key, _val, _nod, _end);
						return	(_nod->_left);
					}
					else
						return	(_insert_node(_nod->_left, _key, _val));
				}
				else
				{
					if (!_nod->_right)
					{
						_nod->_right = _new_node(_key, _val, _nod, _end);
						return	(_nod->_right);
					}
					else
						return	(_insert_node(_nod->_right, _key, _val));
				}
			};

			node				_find(node _nod, key_type _key) const
			{
				node			_tmp;
				if (!_nod->_end && _nod->pair.first == _key && _nod->_parent)
					return		(_nod);
				if (_nod->_right)
					if ((_tmp = _find(_nod->_right, _key)))
						return	(_tmp);
				if (_nod->_left)
					if ((_tmp = _find(_nod->_left, _key)))
						return	(_tmp);
				return			(0);
			};

			void				_delete_node(node _nod)
			{
				node			_par = _nod->_parent;
				if (!_nod->_left && !_nod->_right)
				{
					if (_par->_right == _nod)
						_par->_right = 0;
					else
						_par->_left = 0;
					delete		(_nod);
					return;
				}
				if (_nod->_right && !_nod->_left)
				{
					if (_par->_right == _nod)
						_par->_right = _nod->_right;
					else
						_par->_left = _nod->_right;
					_nod->_right->_parent = _par;
					delete		(_nod);
					return;
				}
				if (_nod->_right && !_nod->_left)
				{
					if (_par->_right == _nod)
						_par->_right = _nod->_left;
					else
						_par->_left = _nod->_left;
					_nod->_left->_parent = _par;
					delete		(_par);
					return;
				}
				node			_nxt = (++iterator(_nod)).node();
				if (!_nxt)
					_nxt = (--iterator(_nod)).node();
				ft::swap(_nxt->pair, _nod->pair);
				_delete_node(_nxt);
			};

			void				_init_tree(void)
			{
				_rot = _new_node(key_type(), mapped_type(), 0);
				_rot->_right = _new_node(key_type(), mapped_type(), _rot, true);
				_len = 0;
			};

			node				_end(void) const
			{
				return			(_rot->_right);
			};

		public:
			explicit			map(const key_compare &_com = key_compare(), const allocator_type &_alc = allocator_type())
								: _alc(_alc), _cmp(_com)
			{
				_init_tree();
			};

			template			<class inputIterator>
			map(inputIterator _ar1, inputIterator _ar2, const key_compare &_com = key_compare(), const allocator_type &_alc = allocator_type())
								: _alc(_alc), _cmp(_com)
			{
				_init_tree();
				insert(_ar1, _ar2);
			};

			map(const map &_cpy)
								: _alc(_cpy._alc), _cmp(_cpy._cmp)
			{
				_init_tree();
				*this = _cpy;
			};

			~map(void)
			{
				_free_tree(_rot);
			};

			map&				operator=(const map<key, typ> &_cpy)
			{
				clear();
				insert(_cpy.begin(), _cpy.end());
				return			(*this);
			};

			iterator			begin(void)
			{
				node			_nod = _rot;
				if (!_nod->_left && !_nod->_right)
					return (end());
				if (!_nod->_left && _nod->_right)
					_nod = _nod->_right;
				while (_nod->_left)
					_nod = _nod->_left;
				return			(iterator(_nod));
			};

			const_iterator		begin(void) const
			{
				node			_nod = _rot;
				if (!_nod->_left && !_nod->_right)
					return		(end());
				if (!_nod->_left && _nod->_right)
					_nod = _nod->_right;
				while (_nod->_left)
					_nod = _nod->_left;
				return			(const_iterator(_nod));
			};

			iterator			end(void)
			{
				return			(iterator(_end()));
			};

			const_iterator		end(void) const
			{
				return			(const_iterator(_end()));
			};

			reverse_iterator	rbegin(void)
			{
				iterator		_idx = end();
				--_idx;
				return			(reverse_iterator(_idx.node()));
			};

			const_reverse_iterator
								rbegin(void) const
			{
				const_iterator	_idx = end();
				--_idx;
				return			(const_reverse_iterator(_idx.node()));
			};

			reverse_iterator	rend(void)
			{
				return			(reverse_iterator(_rot));
			};

			const_reverse_iterator
								rend(void) const
			{
				return			(const_reverse_iterator(_rot));
			};

			bool				empty(void) const
			{
				return			(_len == 0);
			};

			size_type			size(void) const
			{
				return			(_len);
			};

			size_type			max_size(void) const
			{
				return			(std::numeric_limits<size_type>::max() / (sizeof(ft::BNode<key_type, mapped_type>)));
			};

			mapped_type&		operator[](const key_type& _key)
			{
				iterator		_idx = find(_key);
				if (_idx != end())
					return		(_idx->second);
				return			(insert(ft::make_pair(_key, mapped_type())).first->second);
			};

			ft::pair<iterator, bool>
								insert(const value_type &_val)
			{
				iterator		_tmp;
				if ((_tmp = find(_val.first)) != end())
					return		(ft::make_pair(_tmp, false));
				++_len;
				return			(ft::make_pair(iterator(_insert_node(_rot, _val.first, _val.second)), true));
			};
			
			iterator			insert(iterator _pos, const value_type &_val)
			{
				iterator		_tmp;
				if ((_tmp = find(_val.first)) != end())
					return		(_tmp);
				++_len;
				return			(iterator(_insert_node(_pos.node(), _val.first, _val.second)));
			};

			template			<class inputIterator>
			void				insert(inputIterator _ar1, inputIterator _ar2)
			{
				while (_ar1 != _ar2)
				{
					insert(*_ar1);
					++_ar1;
				}
			};

			void				erase(iterator _pos)
			{
				_delete_node(_pos.node());
				--_len;
			};

			size_type			erase(const key_type &_key)
			{
				int				_idx = 0;
				iterator		_tmp;
				while ((_tmp = find(_key)) != end())
				{
					erase(_tmp);
					++_idx;
				}
				return (1);
			};

			void				erase(iterator _ar1, iterator _ar2)
			{
				while (_ar1 != _ar2)
					erase(_ar1++);
			};

			void				swap(map& _cpy)
			{
				ft::swap(_len, _cpy._len);
				ft::swap(_rot, _cpy._rot);
			}

			void				clear(void)
			{
				erase(begin(), end());
			};

			key_compare			key_comp(void) const
			{
				return			(_cmp);
			};

			value_compare		value_comp(void) const
			{
				return			(this->value_compare);
			};

			iterator			find(const key_type& _val)
			{
				if (empty())
					return		(end());
				node			_tmp = _find(_rot, _val);
				if (_tmp)
					return		(iterator(_tmp));
				return			(end());
			};

			const_iterator		find(const key_type& _val) const
			{
				if (empty())
					return		(end());
				node			_tmp = _find(_rot, _val);
				if (_tmp)
					return		(const_iterator(_tmp));
				return			(end());
			};

			size_type			count(const key_type& _val) const
			{
				size_type		_cnt = 0;
				const_iterator	_itr = begin();

				while (_itr != end())
				{
					if (_itr->first == _val)
						++_cnt;
					++_itr;
				}
				return			(_cnt);
			};

			iterator			lower_bound(const key_type& _key)
			{
				iterator		_itr = begin();
				while (_itr != end())
				{
					if (this->_cmp(_itr->first, _key) <= 0)
						return	(_itr);
					++_itr;
				}
				return			(end());
			};

			const_iterator		lower_bound(const key_type& _key) const
			{
				const_iterator	_itr = begin();
				while (_itr != end())
				{
					if (this->_cmp(_itr->first, _key) <= 0)
						return	(_itr);
					++_itr;
				}
				return			(end());
			};

			iterator			upper_bound(const key_type& _key)
			{
				iterator		_itr = begin();
				while (_itr != end())
				{
					if (_itr->first != _key && this->_cmp(_itr->first, _key) <= 0)
						return	(_itr);
					++_itr;
				}
				return			(end());
			};

			const_iterator		upper_bound(const key_type& _key) const
			{
				const_iterator	_itr = begin();
				while (_itr != end())
				{
					if (_itr->first != _key && this->_cmp(_itr->first, _key) <= 0)
						return	(_itr);
					++_itr;
				}
				return			(end());
			};

			ft::pair<const_iterator, const_iterator>
								equal_range(const key_type& _key) const
			{
				return			(ft::pair<const_iterator, const_iterator>(this->lower_bound(_key), this->upper_bound(_key)));
			};

			ft::pair<iterator, iterator>
								equal_range(const key_type& _key)
			{
				return			(ft::pair<iterator, iterator>(this->lower_bound(_key), this->upper_bound(_key)));
			};
	};

	template					<class key, class typ, class cmp, class alc>
	void						swap(ft::map<key, typ, cmp, alc>& _ar1, ft::map<key, typ, cmp, alc>& _ar2)
	{
		_ar1.swap(_ar2);
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator==(const map<key, typ, cmp, alc> &_ar1, const map<key, typ, cmp, alc> &_ar2)
	{
		if (_ar1.size() != _ar2.size())
			return				(false);
		typename				ft::map<key, typ, cmp, alc>::const_iterator	_it1 = _ar2.begin();
		typename				ft::map<key, typ, cmp, alc>::const_iterator	_it2 = _ar1.begin();
		while (_it1 != _ar2.end())
		{
			if (*_it1 != *_it2)
				return			(false);
			++_it2;
			++_it1;
		}
		return					(true);
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator!=(const map<key, typ, cmp, alc> &_ar1, const map<key, typ, cmp, alc> &_ar2)
	{
		return					(!(_ar1 == _ar2));
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator>(const map<key, typ, cmp, alc>& _ar1, const map<key, typ, cmp, alc>& _ar2)
	{
		if (_ar1.size() > _ar2.size())
			return				(true);
		typename				ft::map<key, typ, cmp, alc>::const_iterator	_it1 = _ar1.begin();
		typename				ft::map<key, typ, cmp, alc>::const_iterator	_it2 = _ar2.begin();
		while (_it1 != _ar1.end() && _it2 != _ar2.end())
		{
			if (*_it1 > *_it2)
				return			(true);
			++_it1;
			++_it2;
		}
		return					(false);
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator<(const map<key, typ, cmp, alc>& _ar1, const map<key, typ, cmp, alc>& _ar2)
	{
		return					(_ar2 > _ar1);
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator>=(const map<key, typ, cmp, alc>& _ar1, const map<key, typ, cmp, alc>& _ar2)
	{
		return					(!(_ar1 < _ar2));
	};

	template					<class key, class typ, class cmp, class alc>
	bool						operator<=(const map<key, typ, cmp, alc>& _ar1, const map<key, typ, cmp, alc>& _ar2)
	{
		return					(!(_ar1 > _ar2));
	};
}

# endif