/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:23:39 by wuabdull          #+#    #+#             */
/*   Updated: 2026/04/20 16:23:40 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.id = 42;
    data.name = "worod";

    Data* ptr = &data;
    uintptr_t raw = Serializer::serialize(ptr);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << ptr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Restored pointer: " << restored << std::endl;

    if (ptr == restored)
        std::cout << "Pointers are equal" << std::endl;
    else
        std::cout << "Pointers are NOT equal" << std::endl;

    std::cout << "Data id: " << restored->id << std::endl;
    std::cout << "Data name: " << restored->name << std::endl;

    return 0;
}