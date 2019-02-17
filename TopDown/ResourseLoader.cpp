#include "ResourseLoader.h"



ResourseLoader::ResourseLoader()
{

}


sf::Texture ResourseLoader::getTextureByName(const std::string &textureName)
{
	auto it = std::find_if(allTexturesList.begin(), allTexturesList.end(),
		[&textureName](const std::pair<sf::Texture, std::string>& element) { return element.second == textureName; });
	return it->first;
}

void ResourseLoader::load(std::string textureName)
{
	sf::Texture temp;
	temp.loadFromFile(textureName);
	allTexturesList.emplace_back(temp, textureName);
}

ResourseLoader::~ResourseLoader()
{
}
