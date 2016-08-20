
#include "descr_sm_factions.cpp"
#include "descr_regions.cpp"

struct textureCoords
{
	int x0, y0, x1, y1;
};

struct groundType
{
	std::string name;
	sf::Color colorOnMap;
	textureCoords coords;
} gType;

class Map
{
	public:
	std::ifstream mapText;
	int textureSize;
	int width, height;
	int bufColor;
	std::string nameTextureFile, nameMapGroundFile, nameMapRegionsFile, temp;
	std::vector<groundType> groundTypes;
	sf::Image mapGrounds, mapRegions, mapImage, textureImg;
	sf::Texture textures, tempTexture;
	sf::Sprite sprite, map;
	sf::RenderTexture mapGroundTexture, mapRegionsTexture;
	sf::RectangleShape tile;

	Map()
	{
		mapText.open("data/map.txt");
		mapText >> temp; mapText >> textureSize;			std::cout<< textureSize <<std::endl;
		mapText >> temp; mapText >> nameTextureFile;			std::cout<< nameTextureFile <<std::endl;
		mapText >> temp; mapText >> nameMapGroundFile;			std::cout<< nameMapGroundFile <<std::endl;
		mapText >> temp; mapText >> nameMapRegionsFile;			std::cout<< nameMapRegionsFile <<std::endl;

		while (!mapText.eof())
		{
			mapText >> gType.name;
			mapText >> bufColor;
			gType.colorOnMap.r = bufColor;
			mapText >> bufColor;
			gType.colorOnMap.g = bufColor;
			mapText >> bufColor;
			gType.colorOnMap.b = bufColor;
			mapText >> gType.coords.x0;
			mapText >> gType.coords.y0;
			mapText >> gType.coords.x1;
			mapText >> gType.coords.y1;
			groundTypes.push_back(gType);
		}

		textures.loadFromFile(nameTextureFile); std::cout << "textures.loadFromFile(nameTextureFile); " << std::endl;
		mapGrounds.loadFromFile(nameMapGroundFile);  std::cout << "mapGrounds.loadFromFile(nameMapGroundFile);" << std::endl;
		mapRegions.loadFromFile(nameMapRegionsFile);
		sprite.setTexture(textures);  std::cout << "sprite.setTexture(textures);" << std::endl;

		width = mapGrounds.getSize().x * textureSize; std::cout << "width = mapGrounds.getSize().x * textureSize;;" << std::endl;
		height = mapGrounds.getSize().y * textureSize; std::cout << "height = mapGrounds.getSize().y * textureSize;" << std::endl;

		mapGroundTexture.create(width, height); std::cout << "mapGroundTexture.create(width, height);" << std::endl;
		mapRegionsTexture.create(width, height); std::cout << "mapRegionsTexture.create(width, height);" << std::endl;
		readFactions(); mapGroundTexture.create(width, height); std::cout << "readFactions();" << std::endl;
		readRegions();  std::cout << "readRegions();" << std::endl;
	}

	enum mapMode {GROUND, REGIONS} mode;

	textureCoords getCoordsFromeColor (sf::Color clr)
	{
		for (int i = 0; i < groundTypes.size(); ++i)
			if (groundTypes[i].colorOnMap == clr)
				return groundTypes[i].coords;
	}

	void buildMapGrounds()
	{
	std::cout << "Building map grounds..." << std::endl;
		for (int y = 0; y < mapGrounds.getSize().y; ++y)
			for (int x = 0; x < mapGrounds.getSize().x; ++x)
				for (int i = 0; i < groundTypes.size(); ++i)
					if (mapGrounds.getPixel(x, y) == groundTypes[i].colorOnMap)
					{
						sprite.setTextureRect(sf::IntRect(groundTypes[i].coords.x0, groundTypes[i].coords.y0, groundTypes[i].coords.x1, groundTypes[i].coords.y1));
						sprite.setPosition(sf::Vector2f(x*textureSize, y*textureSize));
						mapGroundTexture.draw(sprite);
					}

		mapGroundTexture.display();
		std::cout << "End building map gounds" << std::endl;
	}

	void changeMapMode(mapMode mm)
	{
		mode = mm;
	}

	void buildMapRegions()
	{
        std::cout << "Building map regions..." << std::endl;
		tile.setSize(sf::Vector2f(textureSize, textureSize) );
		for (int y = 0; y < mapRegions.getSize().y; ++y)
			for (int x = 0; x < mapRegions.getSize().x; ++x)
			{
				tile.setPosition(sf::Vector2f(x*textureSize, y*textureSize));
				for (int i = 0; i < regions.size(); ++i){
				if(mapRegions.getPixel(x, y) == sf::Color(0,0,0)) tile.setFillColor(sf::Color(0,0,0));
				if(mapRegions.getPixel(x, y) == sf::Color(255,255,255)) tile.setFillColor(sf::Color(255,255,255));
				if(mapRegions.getPixel(x, y) == sf::Color(41,140,233)) tile.setFillColor(sf::Color(41,140,233));
					if (mapRegions.getPixel(x, y) == sf::Color(regions[i].Rcolor, regions[i].Gcolor, regions[i].Bcolor))
						for (int u = 0; u < factions.size(); ++u)
							if (regions[i].owner == factions[u].name)
								tile.setFillColor(sf::Color(factions[u].PcolorR, factions[u].PcolorG, factions[u].PcolorB));}
				mapRegionsTexture.draw(tile);
			}

		mapRegionsTexture.display();
		std::cout << "End building map regions" << std::endl;
	}

	sf::Sprite getCurrentMapSprite()
	{
		if (mode == GROUND)
			map.setTexture(mapGroundTexture.getTexture());
		else if (mode == REGIONS)
			map.setTexture(mapRegionsTexture.getTexture());

		return map;
	}

	std::string getProvintionName (int xProvintionCoordinat, int yProvintionCoordinat)
    {
        if(xProvintionCoordinat < 0) xProvintionCoordinat = 0; if(yProvintionCoordinat < 0) yProvintionCoordinat = 0;
        std::cout<< xProvintionCoordinat << " " << mapGrounds.getSize().y-yProvintionCoordinat-1 << std::endl;
        for (int i = 0; i < regions.size(); ++i)
            if (mapRegions.getPixel(xProvintionCoordinat, yProvintionCoordinat) == sf::Color(regions[i].Rcolor, regions[i].Gcolor, regions[i].Bcolor))
                return regions[i].name;
        return "";

    }

    std::string getSettlementName (int xProvintionCoordinat, int yProvintionCoordinat)
    {
        if(xProvintionCoordinat < 0) xProvintionCoordinat = 0; if(yProvintionCoordinat < 0) yProvintionCoordinat = 0;
        for (int i = 0; i < regions.size(); ++i)
            if (mapRegions.getPixel(xProvintionCoordinat, yProvintionCoordinat) == sf::Color(regions[i].Rcolor, regions[i].Gcolor, regions[i].Bcolor))
                return regions[i].townName;
        return "";

    }

    std::string getProvintionOwnerName (int xProvintionCoordinat, int yProvintionCoordinat)
    {
        if(xProvintionCoordinat < 0) xProvintionCoordinat = 0; if(yProvintionCoordinat < 0) yProvintionCoordinat = 0;
        for (int i = 0; i < regions.size(); ++i)
            if (mapRegions.getPixel(xProvintionCoordinat, yProvintionCoordinat) == sf::Color(regions[i].Rcolor, regions[i].Gcolor, regions[i].Bcolor))
                return regions[i].owner;
        return "";

    }

    void captureRegion(std::string aggressor, std::string prov)
    {
        std::cout<< "prov: " << prov << std::endl;
        for (int i = 0; i < regions.size(); ++i)
            if(regions[i].name == prov) regions[i].owner = aggressor;
        buildMapRegions();
    }

} maps;
