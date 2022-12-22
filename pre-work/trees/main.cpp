/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:58:27 by smodesto          #+#    #+#             */
/*   Updated: 2022/12/21 22:11:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RBT.hpp"

template <typename Key, typename Value>
class person
{
	private:
		Key		name;
		Value	age;
	public:
		person(Key name, Value age) : name(name), age(age) {};
		~person() {};
};

template <typename T>
struct NameKey
{
	std::string operator()(const T &p) const
	{
		return (p.name);
	}
};

template <typename T>
struct AgeKey
{
	int operator()(const T &p) const
	{
		return (p.age);
	}
};

int main ( void )
{
	ft::RedBlackTree<	std::string,						\
						person<std::string, int>,			\
						NameKey<person<std::string, int> >, \
						std::less<std::string> > tree;

	tree.insert(person<std::string, int>("Ana", 23), tree.get_root());

/*	bst.insert(18);
	bst.insert(5);
	bst.insert(15);
	bst.insert(17);
	bst.insert(25);
	bst.insert(40);
	bst.insert(80);
	bst.deleteNode(25);
	bst.prettyPrint();*/
	return 0;
}
