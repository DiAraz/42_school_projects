/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daraz <daraz@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:19:27 by daraz             #+#    #+#             */
/*   Updated: 2024/09/17 10:51:02 by daraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/User.hpp"
# include "inc/Server.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 3)
			throw std::invalid_argument("Usage: ./ircserv [port] [password]");
		Server server(argv);
		std::cout << "Server port: " << server.get_port() << "\nServer password: " << server.get_password() << std::endl;
		server.server_loop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return(0);
}

