#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "map.cpp"
#include "utils.cpp"
#include "cursorUtils.cpp"
#include "controle.cpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(xResolution, yResolution), "OWE"/*, sf::Style::Fullscreen*/);
	sf::RectangleShape rec(sf::Vector2f(maps.textureSize, maps.textureSize));
	sf::View view;

	maps.buildMapGrounds();
	maps.buildMapRegions();
	view.reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));

    while (window.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        controle(&view, &window, pos);
        cursorUtils(pos);
        sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}

        if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
        std::cout<< "Provincion: " << maps.getProvintionName(xxx, yyy) << " Settlement: " << maps.getSettlementName(xxx, yyy) << " Ownership: " << maps.getProvintionOwnerName(xxx, yyy) <<std::endl;

		window.setView(view);
		window.clear();
		//calcEssent(xcam, ycam, xCamSize, yCamSize);

		window.draw(maps.getCurrentMapSprite());
		rec.setFillColor(sf::Color(255,255,255,100));
		rec.setPosition(sf::Vector2f(xxx * maps.textureSize, yyy * maps.textureSize) );
		window.draw(rec);
		window.display();
	}

	return 0;
}
