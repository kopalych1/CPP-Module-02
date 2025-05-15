/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:17 by akostian          #+#    #+#             */
/*   Updated: 2025/05/15 14:16:11 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->raw = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Constant integer constructor called\n";
	this->raw = value << 8;
}

Fixed::Fixed(const float value)
{
	std::cout << "Constant float constructor called\n";
	this->raw = roundf(value * (1 << this->bits)) + ((value < 0) << 8);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->raw = other.raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->raw = other.raw;
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
	std::cout << "setRawBits member function called\n";
	this->raw = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->raw >> this->bits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->raw / (1 << this->bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
