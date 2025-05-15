/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:15 by akostian          #+#    #+#             */
/*   Updated: 2025/05/15 16:39:12 by akostian         ###   ########.fr       */
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
	return 0;
}
