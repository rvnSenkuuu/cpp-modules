#include <iostream>
#include <cstring>

void	convert_uppercase(char *str)
{
	for (size_t i = 0; i < std::strlen(str); i++)
		str[i] = std::toupper(str[i]);	
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		convert_uppercase(argv[i]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
	return 0;
}
