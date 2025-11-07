/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:38:42 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 17:36:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

# define SHOW_INFO false

class	Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif