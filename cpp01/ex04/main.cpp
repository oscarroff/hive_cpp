/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:25:38 by thblack-          #+#    #+#             */
/*   Updated: 2026/04/29 14:03:37 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <bits/stdc++.h>

int	main(int argc, char **argv)
{
	if (argc < 4)
	{
		std::cerr << "loserSed: expects 3 parameters: <filename>, <s1>, <s2>\n";
		return (EXIT_FAILURE);
	}
	std::string		s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "loserSed: invalid empty <s1> (find string)\n";
		return (EXIT_FAILURE);
	}
	std::ifstream	input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "loserSed: error opening the file.\n";
		return (EXIT_FAILURE);
	}
	std::string		output_filename = argv[1];
	output_filename.append(".replace");
	std::ofstream	output(output_filename);
	if (!output.is_open())
	{
		std::cerr << "loserSed: error opening the file.\n";
		return (EXIT_FAILURE);
	}
	std::string		s2 = argv[3];
	size_t			position;
	std::string		line;
	while (std::getline(input, line))
	{
		position = line.find(s1);
		while (position != std::string::npos)
		{
			line.erase(position, s1.length());
			line.insert(position, s2);
			position = line.find(s1);
		}
		output << line << "\n";
	}
	input.close();
	output.close();
}
