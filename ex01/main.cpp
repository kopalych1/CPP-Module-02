/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:15 by akostian          #+#    #+#             */
/*   Updated: 2025/05/15 14:14:07 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#include <stdio.h>
#include <string.h>


// Regular Green text
# define GRN "\033[0;32m"
// Regular Yellow text
# define YEL "\033[0;33m"
// Regular Magenta text
# define MAG "\033[0;35m"
// Regular Red text
# define RED "\033[0;31m"
//Regular Background Red text
# define REDB "\033[41m"

//Color reset
# define CRESET "\033[0m"


void	print32bit(unsigned int n)
{
	for (int i = 31; i >= 0; --i)
	{
		if (i != 31 && !((i + 1) % 8))
			std::cout << ' ';
		std::cout << ((n >> i) & 1);
	}
}

void	testFixed(const Fixed &num)
{
	std::cout << YEL "Test number:\t\t" CRESET << MAG << num << CRESET << "\n";
	int		raw_bits = num.getRawBits();
	std::cout << YEL "bits:\t\t\t" CRESET; print32bit(raw_bits); std::cout << "\n";
	std::cout << YEL ".toInt():\t\t" CRESET << num.toInt() << "\n";
	std::cout << YEL ".toFloat():\t\t" CRESET << num.toFloat() << "\n";
	std::cout << YEL "obj:\t\t\t" CRESET << num << "\n";
	std::cout << "\n";
}


int	main( void ) {
	testFixed(Fixed(-12.63f));
	testFixed(Fixed(-12.33f));
	testFixed(Fixed(12.33f));
	testFixed(Fixed(12.63f));
	testFixed(Fixed(0));
	testFixed(Fixed(1234.4321f));

	std::cout << YEL"Copy constructor test: " CRESET << "\n";
	Fixed a(33);
	Fixed b(a);
	a = Fixed(52);
	return 0;
}
