
// utilities (util)
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

#ifndef UTIL_HPP
#define UTIL_HPP

#if defined(__linux__)
#define VLIN
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WIN64__)
#define VWIN
#else
#define VUNK
#endif

#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdio>

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;
typedef unsigned long long qword;

namespace util
{
	void pause();

	typedef byte time_format;
	const time_format time_option = 1;
	const time_format date_option = 2;
	const time_format time_date_option = 3;
	const time_format filename_suffix_option = 4;

	std::string print_ascii(std::vector<byte> v);
	std::string print_hexa(std::vector<byte> v);

	void word_to_bytes(word u, std::vector<byte> & v);
	void dword_to_bytes(dword u, std::vector<byte> & v);
	void qword_to_bytes(qword u, std::vector<byte> & v);

	std::string timef(time_format format = time_date_option);
}

#endif
