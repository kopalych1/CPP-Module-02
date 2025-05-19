/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:38:43 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 23:33:11 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x_(0), y_(0)
{
}

Point::Point(const float x, const float y) : x_(Fixed(x)), y_(Fixed(y))
{
}

Point::Point(const Point& other)
{
	this->x_ = other.x_;
	this->y_ = other.y_;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other) {
		this->x_ = other.x_;
		this->y_ = other.y_;
	}
	return *this;
}

Point::~Point()
{
}


const Fixed	&Point::getX() const
{
	return this->x_;
}
void		Point::setX(const Fixed &value)
{
	this->x_ = value;
}
const Fixed	&Point::getY() const
{
	return this->y_;
}
void		Point::setY(const Fixed &value)
{
	this->y_ = value;
}
