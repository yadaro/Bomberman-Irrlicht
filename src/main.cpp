//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include "core.hpp"

static int start()
{
	Core core(1200, 1000);

	core.run();
	return 0;
}

int main(int ac, char **av)
{
	(void)av;
	if (ac == 1) {
		start();
	} else
		printf("Usage: ./bomerman\n");
	return 0;
}
