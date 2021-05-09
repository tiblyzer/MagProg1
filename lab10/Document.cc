#include "Document.hh"

void Document::read(std::string path)
{
	std::ifstream input(path);
	std::string line;

	while (std::getline(input, line)) {
		lines.push_back(line);
	}
	
	input.close();
}

void Document::swapLines(int n1, int n2)
{
	std::string temp;
	std::list<std::string>::iterator line1 = lines.begin();
	std::list<std::string>::iterator line2 = lines.begin();
	
	for(int i=0;i<n1;++i)
		++line1;

	for (int i = 0; i < n2; ++i)
		++line2;

	temp = *line1;
	*line1 = *line2;
	*line2 = temp;
}