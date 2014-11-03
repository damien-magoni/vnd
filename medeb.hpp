
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

#ifndef MEDEB_HPP
#define MEDEB_HPP

#include "util.hpp"

namespace medeb
{
	extern bool active;

	class entry
	{
	public:
		int byte_size;
		std::string file_name;
		int line_number;
	};

	void * newm(void * p, int byte_size, char const * file_name, int line_number);
	void delm(void * p);
	void init();
	void dump();
}

#endif
