/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elementAccess.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:45:44 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/16 22:10:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_ACCESS_HPP
#define ELEMENT_ACCESS_HPP

// access specified element
template<class container>
void	SquareBrackets( const container &vector )
{
	std::cout << "--------------- [] -----------------" << std::endl;
	std::cout << " Read at [0] pos : " << vector[0] << std::endl;
	std::cout << " Read at [1] pos : " << vector[0] << std::endl;
}

template<class container>
void	atTest( const container &vector )
{
	std::cout << "--------------- at() -----------------" << std::endl;
	try {
		std::cout << " Read at [-1] pos : " << vector.at(-1) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::cout << " Read at [0] pos : " << vector.at(0) << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}

template<class container>
void	testingElementAccess(const container &vector)
{
	atTest(vector);
	SquareBrackets(vector);
	std::cout	<< " back(): " << vector.back() << std::endl
				<< " front(): " << vector.front() << std::endl;
}



#endif //ELEMENT_ACCESS_HPP
