/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 05:21:46 by coder             #+#    #+#             */
/*   Updated: 2022/11/10 05:33:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCATOR_HPP
#define FT_ALLOCATOR_HPP

#include <iostream>
#include <vector>

template <typename T>
struct ft_allocator: std::allocator<T>
{
   T * allocate(size_t size)
   {
        std::cout << "Allocation request size: " << size << std::cout;
        return (new T(size));
   }
   void deallocate(T *ptr, size_t size)
   {
        std::cout << "Deallocating size:" << size << std::endl;
        delete [] ptr;
   }
};

#endif //FT_ALLOCATOR_HPP
