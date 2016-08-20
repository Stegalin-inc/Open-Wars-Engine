std::string agressor = "romans_julii";

int controle (sf::View *view2, sf::RenderWindow *win ,sf::Vector2i position)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && xCamSize > 700) {xCamSize-=4*coeff; yCamSize-=3*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& xCamSize < 4100) {xCamSize+=4*coeff; yCamSize+=3*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && ycam > -128) {ycam-=((xCamSize*16)/700)+1; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && xcam > -128) {xcam-=((xCamSize*16)/700)+1; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && ycam < maps.height - 128) {ycam+=((xCamSize*16)/700)+1; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && xcam < maps.width - 128) {xcam+=((xCamSize*16)/700)+1; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {maps.changeMapMode(Map::GROUND);} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {maps.changeMapMode(Map::REGIONS);}

    //if (position.y < 12 && ycam > -128) {ycam-=8*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    //if (position.x < 12 && xcam > -128) {xcam-=8*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    //if (position.y > yResolution-12 && ycam < maps.height-128) {ycam+=8*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    //if (position.x > xResolution-12 && xcam < maps.width-128) {xcam+=8*coeff; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && xCamSize > 700) {xCamSize-=4; yCamSize-=3; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Right)&& xCamSize < 4100) {xCamSize+=4; yCamSize+=3; view2->reset(sf::FloatRect(xcam, ycam, xCamSize, yCamSize));}
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) agressor = maps.getProvintionOwnerName(xxx, yyy);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) maps.captureRegion(agressor, maps.getProvintionName(xxx, yyy));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) win->close();
}
