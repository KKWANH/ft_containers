/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:43:59 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 15:53:13 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <list>
#include <stdlib.h>

template <class T>
static void print_list(T &list)
{
	typename T::iterator it = list.begin();
	typename T::iterator it2;
	std::cout << "Size " << list.size() << " : ";
	while (it != list.end())
	{
		std::cout << *it;
		it2 = it;
		it2++;
		if (it2 != list.end())
			std::cout << " - ";
		it++;
	}
	std::cout << std::endl;
}

struct Greater {
    bool operator()(const int &a, const int &b) {return a < b;}
};

static void constructors(void)
{
	ft_print_header("Default constructor");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	ft_check("(default) l1 == l2", l1 == l2);
	ft::list<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	ft_check("(fill with default value) l3 == l4", l3 == l4);
	ft::list<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	ft_check("(fill) l5 == l6", l5 == l6);
	ft::list<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	ft_check("(iterator) l7 == l8", l7 == l8);
	ft::list<int> l9(l7);
	std::list<int> l10(l8);
	ft_check("(copy) l9 == l10", l9 == l10);
}

static void copy_operator(void)
{
	ft_print_header("Operator =");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::list<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	ft_check("l1 == l3", l1 == l3);
	ft_check("l2 == l4", l2 == l4);
	l1.push_back(1);
	l2.push_back(1);
	ft_check("l1 != l3", l1 != l3);
	ft_check("l2 != l4", l2 != l4);
}

static void max_size(void)
{
	ft_print_header("Max size");
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<std::string> l3;
	std::list<std::string> l4;
	ft_check("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	ft_check("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
}

static void front_back(void)
{
	ft_print_header("Front / Back");
	ft::list<int> l1;
	std::list<int> l2;
	ft_check("front == back", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	ft_check("l1.front() == l2.front()", l1.front(), l2.front());
	ft_check("l1.back() == l2.back()", l1.back(), l2.back());
}

static void assign(void)
{
	ft_print_header("Assign");
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	l1.assign(test, test + 4);
	l2.assign(test, test + 4);
	ft_check("l1 == l2", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	ft_check("l1 == l2", l1 == l2);
}

static void push(void)
{
	ft_print_header("Push front/back");
	ft::list<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	ft_check("l1 == l2", l1 == l2);
}

static void swap(void)
{
	ft_print_header("Swap");
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
}

static void resize(void)
{
	ft_print_header("Resize / Clear");
	ft::list<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	ft_check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	ft_check("l1 == l2", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	ft_check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	ft_check("l1 == l2", l1 == l2);
}

static void splice(void)
{
	ft_print_header("Splice");
	ft::list<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::list<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
}

static bool even(const int& value) { return (value % 2) == 0; } 

static void remove(void)
{
	ft_print_header("Remove / Remove if");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	ft_check("l1 == l2", l1 == l2);
	l1.remove_if(even);
	l2.remove_if(even);
	ft_check("l1 == l2", l1 == l2);
}

static void erase(void)
{
	ft_print_header("Erase");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	ft_check("l1 == l2", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	ft_check("l1 == l2", l1 == l2);
}

static bool compare(int a, int b) 
{ 
    return (a >= b); 
} 

static void unique()
{
	ft_print_header("Unique");
	std::cout << "debug" << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	std::cout << "debug" << std::endl;
	l1.unique();
	l2.unique();
	std::cout << "debug" << std::endl;
	ft_check("l1 == l2", l1 == l2);
	std::cout << "debug" << std::endl;
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	std::cout << "debug" << std::endl;
	l1.unique(compare);
	l2.unique(compare);
	std::cout << "debug" << std::endl;
	ft_check("l1 == l2", l1 == l2);
}

static bool compare2(int a, int b) 
{ 
    return (a == b); 
} 

static void merge(void)
{
	ft_print_header("Merge");
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	std::cout << "debug" << std::endl;
	ft::list<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	std::cout << "debug" << std::endl;
	ft::list<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	std::cout << "debug" << std::endl;
	l1.merge(l3);
	l2.merge(l4);
	std::cout << "debug" << std::endl;
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
	std::cout << "debug" << std::endl;
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	std::cout << "debug" << std::endl;
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	std::cout << "debug" << std::endl;
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	std::cout << "debug" << std::endl;
	ft_check("l1 == l2", l1 == l2);
	ft_check("l3 == l4", l3 == l4);
}

static void reverse(void)
{
	ft_print_header("Reverse");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	ft_check("l1 == l2", l1 == l2);
}

static void operators(void)
{
	ft_print_header("Operators");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::list<int> l3(l1);
	std::list<int> l4(l2);
	ft_check("l1 == l2", (l1 == l3), (l2 == l4));
	ft_check("l1 != l2", (l1 != l3), (l2 != l4));
	ft_check("l1 > l2", (l1 > l3), (l2 > l4));
	ft_check("l1 < l2", (l1 < l3), (l2 < l4));
	ft_check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	ft_check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l1.push_back(42);
	l2.push_back(42);
	ft_check("l1 == l2", (l1 == l3), (l2 == l4));
	ft_check("l1 != l2", (l1 != l3), (l2 != l4));
	ft_check("l1 > l2", (l1 > l3), (l2 > l4));
	ft_check("l1 < l2", (l1 < l3), (l2 < l4));
	ft_check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	ft_check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l3.push_back(43);
	l4.push_back(43);
	ft_check("l1 == l2", (l1 == l3), (l2 == l4));
	ft_check("l1 != l2", (l1 != l3), (l2 != l4));
	ft_check("l1 > l2", (l1 > l3), (l2 > l4));
	ft_check("l1 < l2", (l1 < l3), (l2 < l4));
	ft_check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	ft_check("l1 <= l2", (l1 <= l3), (l2 <= l4));
}

void ft_test_list(void)
{
	std::srand(time(0));
	ft_print_header("list");
	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();
	swap();
	resize();
	splice();
	remove();
	erase();
	unique();
	merge();
	reverse();
	operators();
}