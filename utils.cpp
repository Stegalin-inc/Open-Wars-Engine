struct begEnd
{
	int bx;
	int by;
	int ex;
	int ey;
}bd;

void calcEssent(int camX, int camY, int camSizeX, int camSizeY)
{
	if (camX < 0) camX = 0;
	if (camY < 0) camY = 0;
	if (camSizeX > maps.width - camX) camSizeX = maps.width - camX;
	if (camSizeY > maps.height - camY) camSizeY = maps.height - camY;
	bd.bx = camX/maps.textureSize;
	bd.by = camY/maps.textureSize;
	bd.ex = (camX/maps.textureSize) + (camSizeX/maps.textureSize);
	bd.ey = (camY/maps.textureSize) + (camSizeY/maps.textureSize);
}
