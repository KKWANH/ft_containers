/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:10:11 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 15:42:37 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template <typename T>
static void print_vector(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << ANSI_BOL << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << ANSI_RES << std::endl;
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
static void print_vector_reverse(T vec, std::string type)
{
	typename T::iterator it;

	std::cout << ANSI_BOL << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << ANSI_RES << std::endl;
	it = vec.rbegin();
	while (it != vec.rend())
	{
		std::cout << *it;
		if (it + 1 != vec.rend())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

static void default_constructor(void)
{
	ft_print_header("Default constructor");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft_check("v1 == v2", v1 == v2);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft_check("v1 == v2", v1 == v2);
}

static void copy_constructor(void)
{
	ft_print_header("Copy");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft::vector<int> v3(v1);
	std::vector<int> v4(v2);
	v1.push_back(42);
	v2.push_back(42);
	ft_check("v1 == v2", (v1 == v2));
	ft_check("v3 == v4", (v3 == v4));
	ft_check("v1 != v3", (v1 != v3));
	ft_check("v2 != v4", (v2 != v4));
}

static void max_size(void)
{
	ft_print_header("Max size");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	ft_check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
	v1.push_back("test");
	v2.push_back("test");
	ft_check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
}

static void resize(void)
{
	ft_print_header("Resize");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(10, "test");
	v2.resize(10, "test");
	ft_check("v1 == v2", (v1 == v2));
	v1.resize(2, "42");
	v2.resize(2, "42");
	ft_check("v1 == v2", (v1 == v2));
}

static void access_operator(void)
{
	ft_print_header("[] operator, at()");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft_check("v1[0] == v2[0]", v1[0], v2[0]);
	ft_check("v1[1] == v2[1]", v1[1], v2[1]);
	ft_check("v1[2] == v2[2]", v1[2], v2[2]);
	try
	{
		std::cout << "v1.at(100): " << v1.at(100) << ": " << EMOTIC_X << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(7, ' ') << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	}
	try
	{
		std::cout << "v2.at(100): " << v2.at(100) << ": " << EMOTIC_X  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(20, ' ') << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	}
	try
	{
		std::cout << "v1.at(-1): " << v1.at(-1) << ": " << EMOTIC_X  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(8, ' ') << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	}
	try
	{
		std::cout << "v2.at(-1): " << v2.at(-1) << ": " << EMOTIC_X  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << ": " << std::string(21, ' ') << ANSI_BOL << ANSI_GRE << EMOTIC_O << ANSI_RES << std::endl;
	}
}

static void front_back(void)
{
	ft_print_header("Front / Back");
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	ft_check("v1.front() == v2.front()", v1.front(), v2.front());
	ft_check("v1.back() == v2.back()", v1.front(), v2.front());
}

static void assign(void)
{
	ft_print_header("Assign");
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	ft_check("v1 == v2", v1 == v2);
	std::cout << "debug" << std::endl;
	v1.assign(10, "?");
	std::cout << "debug" << std::endl;
	v2.assign(10, "?");
	ft_check("v1 == v2", v1 == v2);
}

static void insert(void)
{
	ft_print_header("Insert");
	int test[] = {1, 2, 3};
	ft::vector<int> v1;
	std::vector<int> v2;
	v1.insert(v1.begin(), 42);
	v1.insert(v1.end(), 21);
	v1.insert(v1.begin(), 10);
	v1.insert(v1.begin() + 1, 11);
	v1.insert(v1.begin() + 2, (size_t)3, 0);
	v1.insert(v1.begin() + 1, test, test + 3);
	v2.insert(v2.begin(), 42);
	v2.insert(v2.end(), 21);
	v2.insert(v2.begin(), 10);
	v2.insert(v2.begin() + 1, 11);
	v2.insert(v2.begin() + 2, (size_t)3, 0);
	v2.insert(v2.begin() + 1, test, test + 3);
	ft_check("v1 == v2", v1 == v2);
}

static void erase(void)
{
	ft_print_header("Erase / Clear");
	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.assign(test, test + 4);
	v2.assign(test, test + 4);
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	ft_check("v1 == v2", v1 == v2);
	v1.clear();
	v2.clear();
	ft_check("v1 == v2", v1 == v2);
}

static void swap(void)
{
	ft_print_header("Swap");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3.push_back(42);
	v3.push_back(43);
	v4.push_back(42);
	v4.push_back(43);
	v1.swap(v3);
	v2.swap(v4);
	ft_check("v1 == v2", v1 == v2);
	ft_check("v3 == v4", v3 == v4);
}

static void operators(void)
{
	ft_print_header("Operators");
	ft::vector<int> v1;
	std::vector<int> v2;
	ft::vector<int> v3;
	std::vector<int> v4;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v3 = v1;
	v4 = v2;
	ft_check("v1 == v2", (v1 == v3), (v2 == v4));
	ft_check("v1 != v2", (v1 != v3), (v2 != v4));
	ft_check("v1 > v2", (v1 > v3), (v2 > v4));
	ft_check("v1 < v2", (v1 < v3), (v2 < v4));
	ft_check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	ft_check("v1 <= v2", (v1 <= v3), (v2 <= v4));
	v1.push_back(42);
	v2.push_back(42);
	ft_check("v1 == v2", (v1 == v3), (v2 == v4));
	ft_check("v1 != v2", (v1 != v3), (v2 != v4));
	ft_check("v1 > v2", (v1 > v3), (v2 > v4));
	ft_check("v1 < v2", (v1 < v3), (v2 < v4));
	ft_check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	ft_check("v1 <= v2", (v1 <= v3), (v2 <= v4));
	v3.push_back(43);
	v4.push_back(43);
	ft_check("v1 == v2", (v1 == v3), (v2 == v4));
	ft_check("v1 != v2", (v1 != v3), (v2 != v4));
	ft_check("v1 > v2", (v1 > v3), (v2 > v4));
	ft_check("v1 < v2", (v1 < v3), (v2 < v4));
	ft_check("v1 >= v2", (v1 >= v3), (v2 >= v4));
	ft_check("v1 <= v2", (v1 <= v3), (v2 <= v4));
}

void ft_test_vector(void)
{
	ft_print_header("vector");

	default_constructor();
	copy_constructor();
	max_size();
	resize();
	access_operator();
	front_back();
	assign();
	insert();
	erase();
	swap();
	operators();
}