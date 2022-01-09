/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:06:32 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/01 23:12:35 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef						UTILS_HPP
# define						UTILS_HPP

namespace						ft
{
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
		std::pair<_key, _typ>	pair;
		BNode					*_left;
		BNode					*_right;
		BNode					*_parent;
		bool					_end;
	};
}

# endif