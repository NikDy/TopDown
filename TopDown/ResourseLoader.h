#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include <list>
#include <string>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>


#pragma once
class ResourseLoader
{
public:
	ResourseLoader();
	void load(std::string);
	sf::Texture getTextureByName(const std::string&);
	~ResourseLoader();
private:
	std::vector<std::pair<sf::Texture, std::string>> allTexturesList;
};

