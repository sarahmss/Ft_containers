/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:42:19 by smodesto          #+#    #+#             */
/*   Updated: 2023/02/15 19:55:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "integral_constant.hpp"
/*
	-> Can be used in a template function to enable or disable certain functionality based
		on the type of the function's argument.
	-> After the specialization keyword template<>,
		we define the class for this particular specialization
	-> For unsigned long long int, the is_integral class has a member value that is true,
		as specified by integral_constant.
*/
namespace ft {
	template<class T> struct is_integral: public integral_constant<bool, false> {};
	template<> struct is_integral<bool>: public integral_constant<bool, true> {};
	template<> struct is_integral<char>: public integral_constant<bool, true> {};
	template<> struct is_integral<wchar_t>: public integral_constant<bool, true> {};
	template<> struct is_integral<signed char>: public integral_constant<bool, true> {};
	template<> struct is_integral<short int>: public integral_constant<bool, true> {};
	template<> struct is_integral<int>: public integral_constant<bool, true> {};
	template<> struct is_integral<long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<long long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned char>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned short int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned long int>: public integral_constant<bool, true> {};
	template<> struct is_integral<unsigned long long int>: public integral_constant<bool, true> {};
}

#endif //IS_INTEGRAL_HPP
