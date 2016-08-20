struct Region
{
	std::string name;
	std::string townName;
	std::string owner;
	std::string rebels;
	int Rcolor, Gcolor, Bcolor;
	std::vector<std::string> resources;
	int winScores;
	int agriculture;
} reg;

std::vector<Region> regions;

int readRegions()
{
	std::fstream file("data/descr_regions.txt");
	std::string buff, help;
	getline(file, buff);
	getline(file, buff);
	getline(file, buff);
	getline(file, buff);
	getline(file, buff);
	while(!file.eof())
	{
		getline(file, buff);
		regions.push_back(reg);

		std::stringstream *ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].name;
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].townName;
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].owner;
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].rebels;
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].Rcolor;
		*ss>>regions[regions.size()-1].Gcolor;
		*ss>>regions[regions.size()-1].Bcolor;
		delete ss;

		getline(file, buff);
		for (int i = 0; i < buff.size(); ++i)
			if (buff[i] != ',') help.push_back(buff[i]);
		buff = help;
		ss = new std::stringstream;
		*ss<<buff;
		while (ss->eof())
		{
			*ss>>help;
			regions[regions.size()-1].resources.push_back(help);
		}
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].winScores;
		delete ss;

		getline(file, buff);
		ss = new std::stringstream;
		*ss<<buff;
		*ss>>regions[regions.size()-1].agriculture;
		delete ss;
	}
	for (int i = 0; i < regions.size(); ++i)
        std::cout << "Region " << regions[i].name << " has color " << regions[i].Rcolor << " " << regions[i].Gcolor << " "  << regions[i].Bcolor << std::endl;
}

