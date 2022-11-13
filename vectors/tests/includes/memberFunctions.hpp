/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memberFunctions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:49:43 by smodesto          #+#    #+#             */
/*   Updated: 2022/11/13 18:14:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMBER_FUCNTIONS_HPP
#define MEMBER_FUCNTIONS_HPP

template<class container>
void	testingCapacity(const container &vector)
{
	std::cout << "----------------- Capacity -------------------" << std::endl;
	std::cout	<< " | Size: " << vector.size()
				<< " | Empty: " << (vector.empty() ? TRUE : FALSE)
				<< " | Capacity: " << vector.capacity() << " |" << std::endl;
}

#endif //MEMBER_FUCNTIONS_HPP
