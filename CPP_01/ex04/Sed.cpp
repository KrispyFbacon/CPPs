/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:19:15 by frbranda          #+#    #+#             */
/*   Updated: 2025/10/29 17:09:31 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

static std::string	replaceLine(const std::string &line,
								const std::string &s1, const std::string &s2)
{
	std::string	res;
	size_t		i = 0;
	size_t		pos;

	while (i < line.length())
	{
		pos = line.find(s1, i);
		if (pos == std::string::npos)
		{
			res.append(line, i, std::string::npos);
			break ;
		}
		res.append(line, i, pos - i);
		res += s2;
		i = pos + s1.length();
	}
	return (res);
}

int	sed(const std::string &filename, const std::string &s1,
		const std::string &s2)
{
	if (s1.empty())
	{
		Error::error("S1 cannot be empty.");
		return (1);
	}
	
	// open file
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		Error::open(filename);
		return (1);
	}

	// create file
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		Error::error("Cannot create outputfile.");
		return (1);
	}
	
	// appending into outfile
	std::string line;
	while (std::getline(infile, line))
		outfile << replaceLine(line, s1, s2) << "\n";
	
	// outfile error check
	if (outfile.fail())
	{
		Error::error("Write operation failed");
		infile.close();
		outfile.close();
		return (1);
	}
	
	infile.close();
	outfile.close();
	return (0);
}