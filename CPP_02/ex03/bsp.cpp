/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:39:14 by frbranda          #+#    #+#             */
/*   Updated: 2025/11/07 17:26:10 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	areaTriangle(Point const& a, Point const& b, Point const& c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()))
				+ (b.getX() * (c.getY() - a.getY()))
				+ (c.getX() * (a.getY() - b.getY()));
	
	return fabs(area.toFloat()) / 2.0f;
}

bool	bsp( Point const a, Point const b, Point const c, Point const p)
{
	float	areaTotal = areaTriangle(a, b, c);
	float	areaABP = areaTriangle(a, b, p);
	float	areaBCP = areaTriangle(b, c, p);
	float	areaCAP = areaTriangle(c, a, p);

	if (SHOW_INFO)
	{
		std::cout << RST << "\nTotal Area:  " << areaTotal << RST << std::endl;
		std::cout << "Area of ABP: " << areaABP << RST << std::endl;
		std::cout << "Area of BCP: " << areaBCP << RST << std::endl;
		std::cout << "Area of CAP: " << areaCAP << RST << std::endl;
		std::cout << "area1 + area2 + area3 = " << areaABP + areaBCP + areaCAP;
		std::cout << "\nDifference: " << fabs(areaTotal - (areaABP + areaBCP + areaCAP))
				  << " -> " << RST;
	}

	if (areaABP == 0 || areaBCP == 0 || areaCAP == 0)
		return false;

	// elipson comparison
	float epsilon = 0.001f;
	return (fabs(areaTotal - (areaABP + areaBCP + areaCAP)) < epsilon);
}