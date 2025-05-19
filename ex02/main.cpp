/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:15 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 21:15:18 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#include <stdio.h>
#include <string.h>



int	main( void ) {
	std::cout << Fixed(2.4f) + Fixed(-2.5f) << "\n";
	std::cout << Fixed(2.4f) + Fixed(1) << "\n";
	std::cout << Fixed(0.1f) + Fixed(0.2f) << "\n";
	std::cout << Fixed(0.1f) - Fixed(0.2f) << "\n";
	std::cout << Fixed(3) - Fixed(4) << "\n";
	std::cout << Fixed(3) * Fixed(4) << "\n";
	std::cout << Fixed(5) / Fixed(-2.5f) << "\n";

	std::cout << "(Fixed(5) > Fixed(-2.5f)): " << (Fixed(5) > Fixed(-2.5f)) << "\n";
	std::cout << "(Fixed(5) < Fixed(-2.5f)): " << (Fixed(5) < Fixed(-2.5f)) << "\n";
	std::cout << "Fixed(0.3f) == (Fixed(0.2f) + Fixed(0.1f)): " << (Fixed(0.3f) == (Fixed(0.2f) + Fixed(0.1f))) << "\n";
	std::cout << "(Fixed(0.3f) != Fixed(0.3f)): " << (Fixed(0.3f) != Fixed(0.3f)) << "\n";
	std::cout << "(Fixed(0.3f) >= Fixed(0.3f)): " << (Fixed(0.3f) >= Fixed(0.3f)) << "\n";
	std::cout << "(Fixed(0.3f) <= Fixed(-0.3f)): " << (Fixed(0.3f) <= Fixed(-0.3f)) << "\n";

	Fixed a;
	Fixed b;
	Fixed c;
	Fixed d;
	for (int i = 0; i < 1 << 7; i++)
	{
		if (i == 0)
		{
			std::cout << "First iteration: " << a++ << "\n";
			std::cout << "First iteration: " << ++b << "\n";
			std::cout << "First iteration: " << c-- << "\n";
			std::cout << "First iteration: " << --d << "\n";
			continue;
		}
		a++;
		++b;
		c--;
		--d;
	}
	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";
	std::cout << d << "\n";

	std::cout << Fixed::min(Fixed(13), Fixed(22)) << "\n";
	std::cout << Fixed::min(Fixed(13), Fixed(-22)) << "\n";

	return 0;
}
