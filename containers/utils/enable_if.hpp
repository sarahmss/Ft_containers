/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:29:34 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 20:26:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/*
	-> Often used as a template parameter to conditionally enable or disable certain methods
		or behavior based on the type of the template parameter.
	-> Using ft::enable_if, you can write more flexible and type-safe code that adapts
		to the specific needs of your application.
	-> enable_if condition is checked during template instantiation, and if it evaluates to false,
		the template function/constructor that uses it is simply not considered as a viable option,
		resulting in a substitution failure, which is not considered an error.
*/

namespace ft
{
	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}

#endif //ENABLE_IF_HPP
