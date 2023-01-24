/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:14:15 by smodesto          #+#    #+#             */
/*   Updated: 2023/01/24 18:58:46 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../../utils/pair.hpp"

static void Operators(void)
{
	ft::pair<int, int>	myPair(15, 5);
	std::pair<int, int>	stdPair(15, 5);
	ft::pair<int, int>	copyMyPair = myPair;
	std::pair<int, int>	copyStdPair = stdPair;

	std::cout << "| (=) Assignment operator: ";
	if (copyMyPair.first == copyStdPair.first && copyMyPair.second == copyStdPair.second)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (==) Equal operator: ";
	if (myPair == copyMyPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (!=) Different operator: ";
	copyMyPair.first = 5;
	copyMyPair.second = 15;
	if (myPair != copyMyPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (<) smaller operator: ";
	copyMyPair.first = 5;
	copyMyPair.second = 1;
	if (copyMyPair < myPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (>) greater operator: ";
	copyMyPair.first = 16;
	copyMyPair.second = 16;
	if (copyMyPair > myPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (<=) smaller equal operator: ";
	copyMyPair.first = 5;
	copyMyPair.second = 15;
	if (copyMyPair < myPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
	std::cout << "| (>=) greater equal operator: ";
	copyMyPair.first = 15;
	copyMyPair.second = 10;
	if (copyMyPair >= myPair)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;

}

static void CopyConstructor(void)
{
	std::cout << "| Pair copy constructor: ";
	ft::pair<int, int>	myPair(15, 5);
	std::pair<int, int>	stdPair(15, 5);
	ft::pair<int, int>	copyMyPair(myPair);
	std::pair<int, int>	copyStdPair(stdPair);

	if (copyMyPair.first == copyStdPair.first && copyMyPair.second == copyStdPair.second)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
}

static void ParametricConstructor(void)
{
	std::cout << "| Pair parametric constructor: ";
	ft::pair<int, int>	myPair(15, 5);
	std::pair<int, int>	stdPair(15, 5);
	if (myPair.first == stdPair.first && myPair.second == stdPair.second)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
}

static void DefaultConstructor(void)
{
	std::cout << "| Pair default constructor: ";
	ft::pair<int, int>	myPair;
	std::pair<int, int>	stdPair;
	if (myPair.first == stdPair.first && myPair.second == stdPair.second)
		std::cout << "OK |" << std::endl;
	else
		std::cout << "KO |" << std::endl;
}

int main(void)
{
	DefaultConstructor();
	ParametricConstructor();
	CopyConstructor();
	Operators();
	return (0);
}
