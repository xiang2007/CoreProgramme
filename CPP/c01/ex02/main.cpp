/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:43:57 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/04 19:25:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bits/stdc++.h>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address of string " << str << " is: " << &str << "\n";
	std::cout << "Memery address of stringPTR is: " << &stringPTR << "\n";
	std::cout << "Memory address of stringREF is: " << &stringREF << "\n";
	std::cout << "Value of string is " << str << "\n";
	std::cout << "Value of stringPTR is: " << stringPTR << "\n";
	std::cout << "Value of stringREF is: " << stringREF << std::endl;
	return 0;
}