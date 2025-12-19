/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:55:53 by frbranda          #+#    #+#             */
/*   Updated: 2025/12/19 18:30:28 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main ()
{
	int nums[] = {1, 2, 3, 4, 5};
	int sizeNums = sizeof(nums) / sizeof(nums[0]);

	iter(nums, sizeNums, print);
}
