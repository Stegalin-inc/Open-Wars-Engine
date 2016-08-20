int xResolution = 800, yResolution = 640;
int xCamSize = 400, yCamSize = 300;
int xcam = 512, ycam = 512;
int coeff = 8;
int xxx, yyy;

void cursorUtils(sf::Vector2i position)
{
		xxx = (xcam + ( float(position.x) / float(xResolution) ) * (xCamSize) );
		yyy = (ycam + ( float(position.y) / float(yResolution) ) * (yCamSize) );
		xxx/=maps.textureSize; yyy/=maps.textureSize;
}
