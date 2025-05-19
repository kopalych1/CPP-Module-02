/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akostian <akostian@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:39:06 by akostian          #+#    #+#             */
/*   Updated: 2025/05/19 23:39:46 by akostian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	sign(Point const &p1, Point const &p2, Point const &p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY())).toFloat();
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d1 = sign(point, a, b);
	float d2 = sign(point, b, c);
	float d3 = sign(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
