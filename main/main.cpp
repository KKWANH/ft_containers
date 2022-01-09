/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:15 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 15:45:46 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include		"main.hpp"

int				main(int _arc, char** _arv)
{
	std::string	_str;

	if (_arc != 2)
	{
		std::cout	<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "Please enter one of the following: " << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "mandatory" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "vector" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "map" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "stack" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "bonus" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "all" << ANSI_RES << std::endl;
		return	(0);
	}

	_str = std::string(_arv[1]);
	if (_str == "mandatory")
	{
		ft_test_vector();
		ft_test_map();
		ft_test_stack();
		ft_test_list();
	}
	else if (_str == "vector")
		ft_test_vector();
	else if (_str == "map")
		ft_test_map();
	else if (_str == "stack")
		ft_test_stack();
	else if (_str == "list")
		ft_test_list();
	else if (_str == "bonus")
		std::cout	<< ANSI_BLU << "[ft_containers] " << ANSI_RED << "[ERROR] " << ANSI_RES << "We are sorry, but no bonuses are implemented... 🙄" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "mandatory" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "vector" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "map" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "stack" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "bonus" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "all" << ANSI_RES << std::endl;
	else if (_str == "all")
	{
		ft_test_vector();
		ft_test_map();
		ft_test_stack();
	}
	else
		std::cout	<< ANSI_BLU << "[ft_containers] " << ANSI_RED << "[ERROR] " << ANSI_RES << "Your input is wrong... 🙄" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "Enter one of the following: " << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "mandatory" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "vector" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "map" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << "stack" << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "bonus" << ANSI_RES << std::endl
					<< ANSI_BLU << "[ft_containers] " << ANSI_RES << ANSI_BOL << "all" << ANSI_RES << std::endl;;
	return	(0);
}