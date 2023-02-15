/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:10:09 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 19:50:08 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP

/*
	-> It's a helper class template that provides a compile-time constant value of a specified type
	-> A type argument T, and a non-type argument v of type T.
	-> It's often used as a wrapper around a compile-time constant to allow it to be treated as a type.
*/

namespace ft
{
template<class T, T v>
struct integral_constant {
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T, v> type;
	operator T() { return v; }
};
};

#endif //INTEGRAL_CONSTANT_HPP
