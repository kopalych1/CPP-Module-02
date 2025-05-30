/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:17 by akostian          #+#    #+#             */
/*   Updated: 2025/05/15 16:50:24 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	if (DO_PRINT_DEBUG)
		std::cout << "Default constructor called\n";
	this->raw = 0;
}

Fixed::Fixed(const int value)
{
	if (DO_PRINT_DEBUG)
		std::cout << "Constant integer constructor called\n";
	this->raw = value << 8;
}

Fixed::Fixed(const float value)
{
	if (DO_PRINT_DEBUG)
		std::cout << "Constant float constructor called\n";
	this->raw = roundf(value * (1 << this->bits));
}

Fixed::Fixed(const Fixed& other)
{
	if (DO_PRINT_DEBUG)
		std::cout << "Copy constructor called\n";
	this->raw = other.raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (DO_PRINT_DEBUG)
		std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->raw = other.raw;
	}
	return *this;
}

Fixed::~Fixed()
{
	if (DO_PRINT_DEBUG)
		std::cout << "Destructor called\n";
}


int	Fixed::getRawBits() const
{
	if (DO_PRINT_DEBUG)
		std::cout << "getRawBits member function called\n";
	return this->raw;
}

void	Fixed::setRawBits(int const raw)
{
	if (DO_PRINT_DEBUG)
		std::cout << "setRawBits member function called\n";
	this->raw = raw;
}

int	Fixed::toInt( void ) const
{
	if (DO_PRINT_DEBUG)
		std::cout << "toInt() member function called\n";
	if (this->raw >= 0)
		return (this->raw >> bits);
	return -((-this->raw) >> bits);
}

float	Fixed::toFloat( void ) const
{
	if (DO_PRINT_DEBUG)
		std::cout << "toFloat() member function called\n";
	return ((float)this->raw / (1 << this->bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	if (DO_PRINT_DEBUG)
		std::cout << "<< operator member function called\n";
	os << fixed.toFloat();
	return os;
}
