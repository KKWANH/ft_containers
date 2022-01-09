/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:18:28 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 15:31:51 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						STACK_HPP
# define						STACK_HPP

# include						"list.hpp"

namespace						ft
{
	template					<class Typ, class Container = ft::list<Typ> >
	class						stack
	{
		public:
			typedef				Typ												value_type;
			typedef				Container										container_type;
			typedef				unsigned long									size_type;

		protected:
			container_type														_cnt;
		
		public:
			explicit			stack(const container_type& _cpy = container_type())
			:					_cnt(_cpy)
			{};

			stack(const stack& _cpy)											{ *this = _cpy; };
			~stack(void)														{};
			stack&				operator=(const stack& _cpy)					{ _cnt = _cpy._cnt; return (*this); };
			bool				empty(void) const								{ return (_cnt.empty()); };
			size_type			size(void) const								{ return (_cnt.size()); };
			value_type&			top(void)										{ return (_cnt.back()); };
			const value_type&	top(void) const									{ return (_cnt.back()); };
			void				push(const value_type& _val)					{ _cnt.push_back(_val); };
			void				pop(void)										{ _cnt.pop_back(); };

		private:
			template			<class Cl1, class Cl2>
			friend bool			operator==(const stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
			template			<class Cl1, class Cl2>
			friend bool			operator!=(const stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
			template			<class Cl1, class Cl2>
			friend bool			operator<(const  stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
			template			<class Cl1, class Cl2>
			friend bool			operator>(const  stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
			template			<class Cl1, class Cl2>
			friend bool			operator<=(const stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
			template			<class Cl1, class Cl2>
			friend bool			operator>=(const stack<Cl1, Cl2>& _ar1, const stack<Cl1, Cl2>& _ar2);
	};

	template					<class Typ, class Container>
	bool						operator==(const stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt == _ar2._cnt);
	};

	template					<class Typ, class Container>
	bool						operator!=(const stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt != _ar2._cnt);
	};

	template					<class Typ, class Container>
	bool						operator<(const  stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt < _ar2._cnt);
	};

	template					<class Typ, class Container>
	bool						operator>(const  stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt > _ar2._cnt);
	};

	template					<class Typ, class Container>
	bool						operator<=(const stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt <= _ar2._cnt);
	};

	template					<class Typ, class Container>
	bool						operator>=(const stack<Typ, Container>& _ar1, const stack<Typ, Container>& _ar2)
	{
		return (_ar1._cnt >= _ar2._cnt);
	};
};

# endif
