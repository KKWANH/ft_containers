/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:43:22 by kimkwanho         #+#    #+#             */
/*   Updated: 2022/01/09 15:43:48 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void constructors(void)
{
	ft_print_header("Constructor");
	ft::stack<int> q1;
	std::stack<int> q2;
	ft_check("q1.size() == q2.size()", q1.size() == q2.size());
	ft_check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

static void front_back(void)
{
	ft_print_header("Front / Back / Push / Pop");
	ft::stack<int> q1;
	std::stack<int> q2;
	q1.push(0);
	q1.push(1);
	q1.push(2);
	q2.push(0);
	q2.push(1);
	q2.push(2);
	ft_check("q1.size() == q2.size()", q1.size() == q2.size());
	ft_check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
	ft_check("q1.top() == q2.top()", q1.top(), q2.top());
	q1.pop();
	q2.pop();
	ft_check("q1.size() == q2.size()", q1.size() == q2.size());
	ft_check("q1.top() == q2.top()", q1.top(), q2.top());
}

void ft_test_stack(void)
{
	ft_print_header("stack");
	constructors();
	front_back();
}