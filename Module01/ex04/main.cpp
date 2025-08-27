#include <iostream>
#include <string.h>
#include <fstream>

int check_inputs(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "please enter first a filename, and then s1, s2" << std::endl;
		return (1);
	}
	std::fstream file(argv[1], std::ios::in);
    if (!file) 
	{
        std::cerr << "File doesn't exist" << std::endl;
        return (1);
    }
	file.close();
	return (0);
}

/*int old_copy_file(char *argv[])
{
    std::ifstream src(argv[1], std::ios::binary);
    if (!src) 
	{
        std::cerr << "File doesn't exist" << std::endl;
        return (1);
    }

    src.seekg(0, std::ios::end);
    size_t size = src.tellg();
    src.seekg(0, std::ios::beg);

    std::string content(size, '\0');
    src.read(&content[0], size);
    src.close();

    std::string new_filename = std::string(argv[1]) + "_copy";
    std::ofstream dest(new_filename.c_str(), std::ios::binary);
    if (!dest) 
	{
        std::cerr << "File error" << std::endl;
        return (1);
    }

    dest.write(content.c_str(), size);
    dest.close();
	
	return (0);
}*/

int copy_file(char *argv[])
{
	std::string old_str = argv[2];
	std::string new_str = argv[3];

	size_t old_str_len = old_str.size();

    std::ifstream src(argv[1]);
    if (!src) 
	{
        std::cerr << "File doesn't exist" << std::endl;
        return (1);
    }

	std::string new_filename = std::string(argv[1]) + "_copy";
    std::ofstream dest(new_filename.c_str());
    if (!dest) 
	{
        std::cerr << "File error" << std::endl;
        return (1);
    }
	std::string line;
	std::string first_part;
	std::string end_part;
    while (std::getline(src, line)) 
	{
		/*size_t index = 0;
		while ((index = line.find(old_str)) != std::string::npos)
		{
			line.erase(index, old_str.size());
			line.insert(index, new_str);
		}
		dest << line << '\n';*/
		size_t index = 0;
		while((index = line.find(old_str)) != std::string::npos) 
		{
			size_t line_len = line.size();
			first_part = line.substr(0, index);
			end_part = line.substr(index + old_str_len, line_len);
			line = first_part + new_str + end_part;
    	}
		dest << line << '\n';
    }
    src.close();
	dest.close();
	return (0);
}

int main (int argc, char *argv[])
{
	if (check_inputs(argc, argv) || copy_file(argv))
	{
		return(1);
	}

	return (0);
}