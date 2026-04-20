/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:29:21 by wuabdull          #+#    #+#             */
/*   Updated: 2026/04/20 16:29:22 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    Base* ptr = generate();

    std::cout << "identify by pointer: ";
    identify(ptr);

    std::cout << "identify by reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}