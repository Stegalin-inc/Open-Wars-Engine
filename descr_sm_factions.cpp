
struct Faction
{
	std::string name;
	std::string culture;
	int PcolorR, PcolorG, PcolorB;
	int ScolorR, ScolorG, ScolorB;
}fac;

std::vector<Faction> factions;

int readFactions()
{
	std::fstream file("data/descr_sm_factions.txt");
	std::string buff, help;
	while(!file.eof())
	{
		getline(file, buff);
		std::stringstream *ss = new std::stringstream;
		*ss << buff;
		*ss >> help;
		if (help == "faction")
		{
			factions.push_back(fac);
			*ss >> factions[factions.size()-1].name;
			delete ss;
		}
		if (help == "culture")
		{
			*ss >> factions[factions.size()-1].culture;
			delete ss;
		}
		if (help == "primary_colour")
		{
			help = "";
			for (int i = 0; i < buff.size(); ++i)
				if (buff[i] != ',')
					help.push_back(buff[i]);
			delete ss;
			ss = new std::stringstream;
			*ss << help;
			*ss >> help;
			*ss >> help;
			*ss >> factions[factions.size()-1].PcolorR;
			*ss >> help;
			*ss >> factions[factions.size()-1].PcolorG;
			*ss >> help;
			*ss >> factions[factions.size()-1].PcolorB;
		}
		if (help == "secondary_colour")
		{
			help = "";
			for (int i = 0; i < buff.size(); ++i)
				if (buff[i] != ',')
					help.push_back(buff[i]);
			delete ss;
			ss = new std::stringstream;
			*ss << help;
			*ss >> help;
			*ss >> help;
			*ss >> factions[factions.size()-1].ScolorR;
			*ss >> help;
			*ss >> factions[factions.size()-1].ScolorG;
			*ss >> help;
			*ss >> factions[factions.size()-1].ScolorB;
		}
	}
}
