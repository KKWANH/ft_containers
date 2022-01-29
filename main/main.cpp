/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:19:42 by lucaslefran       #+#    #+#             */
/*   Updated: 2022/01/29 12:45:31 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>

#include "../containers/list.hpp"
#include "../containers/vector.hpp"
#include "../containers/map.hpp"
#include "../containers/stack.hpp"

int main()
{
    std::vector<int>            std_vec;
    std::list<std::string>      std_lis;
    std::stack<char>            std_sta;
    std::map<int, std::string>  std_map;
    
    ft::vector<int>             ft_vec;
    ft::list<std::string>       ft_lis;
    ft::stack<char>             ft_sta;
    ft::map<int, std::string>   ft_map;

	std::cout << "\033[32mThere's no problem with launching the containers.\033[0m" << std::endl;
}