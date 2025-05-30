/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:15 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 23:59:21 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <stdio.h>
#include <string.h>



bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main( void ) {
	std::cout << bsp(Point(-1, 0.5), Point(0.5, 2), Point(1, 0.5), Point(0.2, 1.3)) << "\n";
	std::cout << bsp(Point(-1, 0.5), Point(0.5, 2), Point(1, 0.5), Point(1, 1.5)) << "\n";
	return 0;
}
