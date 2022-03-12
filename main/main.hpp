/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:06:55 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 16:02:50 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef		MAIN_HPP
# define		MAIN_HPP

# include		<iostream>

# include		<vector>
# include		<map>
# include		<stack>
# include		<list>

# include		"../cont/vector.hpp"
# include		"../cont/map.hpp"
# include		"../cont/stack.hpp"
# include		"../cont/list.hpp"

# define		ANSI_RES	"\e[0;0m"
# define		ANSI_BOL	"\e[0;1m"
# define		ANSI_ITA	"\e[0;3m"
# define		ANSI_BLC	"\e[0;30m"
# define		ANSI_RED	"\e[0;31m"
# define		ANSI_GRE	"\e[0;32m"
# define		ANSI_YEL	"\e[0;33m"
# define		ANSI_BLU	"\e[0;34m"	
# define		ANSI_MAG	"\e[0;35m"
# define		ANSI_CYA	"\e[0;36m"

# define		EMOTIC_O	"✓"
# define		EMOTIC_X	"❌"

void			ft_test_vector(void);
void			ft_test_map(void);
void			ft_test_stack(void);
void			ft_test_list(void);

inline void		ft_print_header(std::string str)
{
	int margin = (40 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << ANSI_BLU << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << ANSI_RES;
};

template		<typename _typ>
inline void		ft_check(std::string _nam, _typ _ar1, _typ _ar2)
{
	std::string	_mar(38 - _nam.length(), ' ');

	if (_ar1 == _ar2)
		std::cout	<< _nam << " : " << _mar << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	else
		std::cout	<< _nam << " : " << _mar << ANSI_BOL << ANSI_RED << EMOTIC_X << ANSI_RES << std::endl;
};

inline void		ft_check(std::string _nam, bool _chk)
{
	std::string	_mar(38 - _nam.length(), ' ');
	if (_chk)
		std::cout	<< _nam << " : " << _mar << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	else
		std::cout	<< _nam << " : " << _mar << ANSI_BOL << ANSI_RED << EMOTIC_X << ANSI_RES << std::endl;
};

template		<typename _typ>
bool			operator==(ft::vector<_typ> &_vc1, std::vector<_typ> &_vc2)
{
	if (_vc1.size() != _vc2.size())
		return	(false);
	if (_vc1.empty() != _vc2.empty())
		return	(false);
	for (size_t _idx = 0; _idx < _vc1.size(); _idx++)
		if (_vc1[_idx] != _vc2[_idx])
			return	(false);
	return	(true);
};

template		<typename _typ>
bool			operator==(ft::list<_typ> &_ar1, std::list<_typ> &_ar2)
{
	if (_ar1.size() != _ar2.size())
		return (false);
	if (_ar1.empty() != _ar2.empty())
		return (false);
	typename	ft::list< _typ>::iterator _it1 = _ar1.begin();
	typename	std::list<_typ>::iterator _it2 = _ar2.begin();
	while (_it1 != _ar1.end())
	{
		if (*_it1 != *_it2)
			return (false);
		++_it1;
		++_it2;
	}
	return (true);
};

template		<typename _ty1, typename _ty2>
bool			operator==(ft::map<_ty1, _ty2> &_mp1, std::map<_ty1, _ty2> &_mp2)
{
	if (_mp1.size() != _mp2.size())
		return	(false);
	if (_mp1.empty() != _mp2.empty())
		return	(false);
	typename	ft::map<_ty1,  _ty2>::iterator _it1 = _mp1.begin();
	typename	std::map<_ty1, _ty2>::iterator _it2 = _mp2.begin();
	
	while (_it1 != _mp1.end())
	{
		if (_it1->first != _it2->first || _it1->second != _it2->second)
			return	(false);
		++_it1;
		++_it2;
	}
	return	(true);
};

# endif