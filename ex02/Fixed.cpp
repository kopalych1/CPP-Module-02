/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:22:17 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 21:18:23 by akostian         ###   ########.fr       */
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


Fixed	Fixed::operator+(Fixed const& other) const
{
	Fixed	ret;
	ret.raw = this->raw + other.raw;
	return ret;
}
Fixed	Fixed::operator-(Fixed const& other) const
{
	Fixed	ret;
	ret.raw = this->raw - other.raw;
	return ret;
}
Fixed	Fixed::operator*(Fixed const& other) const
{
	Fixed	ret;
	ret.raw = this->raw * other.toFloat();
	return ret;
}
Fixed	Fixed::operator/(Fixed const& other) const
{
	Fixed	ret;
		ret.raw = this->raw / other.toFloat();
	return ret;
}


// Pre-increment
Fixed&	Fixed::operator++()
{
	this->raw++;
	return *this;
}
// Post-increment
Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	this->operator++();
	return ret;
}
// Pre-decrement
Fixed&	Fixed::operator--()
{
	this->raw--;
	return *this;
}
// Post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	this->operator--();
	return ret;
}


bool	Fixed::operator>(Fixed const& other) const
{
	return this->raw > other.raw;
}
bool	Fixed::operator<(Fixed const& other) const
{
	return this->raw < other.raw;
}
bool	Fixed::operator>=(Fixed const& other) const
{
	return this->raw >= other.raw;
}
bool	Fixed::operator<=(Fixed const& other) const
{
	return this->raw <= other.raw;
}
bool	Fixed::operator==(Fixed const& other) const
{
	return this->raw == other.raw;
}
bool	Fixed::operator!=(Fixed const& other) const
{
	return this->raw != other.raw;
}


Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}
Fixed&			Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
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
