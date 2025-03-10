/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:17 by akostian          #+#    #+#             */
/*   Updated: 2025/03/10 16:47:39 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	raw = 0x00000000;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	raw = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		raw = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return this->raw;
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}
