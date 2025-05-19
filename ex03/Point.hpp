/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:38:40 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 23:54:54 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point {
	private:
		Fixed	x_;
		Fixed	y_;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		const Fixed	&getX() const;
		void		setX(const Fixed &value);
		const Fixed	&getY() const;
		void		setY(const Fixed &value);
};

#endif //POINT_HPP