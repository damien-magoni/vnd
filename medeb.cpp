
// memory output (medeb)
// Copyright (C) 2012-2014 Damien Magoni

/*
    This file is part of vnd.

    vnd is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as 
    published by the Free Software Foundation, either version 3 of 
    the License, or (at your option) any later version.

    vnd is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with vnd.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "medeb.hpp"

namespace medeb
{
	bool active = false;
	std::map<void *, entry> map;

	void * newm(void * p, int size, char const * file, int line)
	{
		entry d;
		d.byte_size = size;
		d.file_name = file;
		d.line_number = line;
		map[p] = d;
		return 0;//p;
		//void * p = malloc(size);
		//return ::new char [size];
	}

	void delm(void * p)
	{
		map.erase(p);
		//free(p);
	}

	void init()
	{
		map.clear();
	}

	void dump()
	{
		if ( map.empty() )
		{
			std::cout << "no memory leaks\n";
			return;
		}
		std::ofstream ofs("mem-dbg.txt");
		ofs << "number of mem objects = " << map.size() << "\n";
		std::map<void * , entry>::iterator it = map.begin();
		while ( it != map.end() )
		{
			ofs.flags(std::ios::right|std::ios::hex|std::ios::showbase);
			ofs << "-> 0x" << std::setw(8) << it->first;
			ofs.flags(std::ios::right|std::ios::dec);
			ofs << " [" << it->second.file_name << ":" << it->second.line_number << "] " << it->second.byte_size << " Bytes\n";
			it++;
		}
		ofs.close();
	}
}
