
// messenger application (mesap)
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

#ifndef MESAP_HPP
#define MESAP_HPP

#include "util.hpp"

namespace mesap
{
	typedef byte messages_output_type;
	const messages_output_type console = 0x01;
	const messages_output_type logging = 0x02;
	//const messages_output_type netsock = 0x04;

	class messenger
	{
	public:
		std::ofstream log_file;
		messages_output_type output_mode;
		bool pause_mode;

		messenger();
		messenger(std::string filename, messages_output_type startup_output_mode, bool startup_pause_mode);
		~messenger();
		messenger & operator<<(const std::string & s);
		messenger & operator<<(const char * s);
		messenger & operator<<(const int & i);
		messenger & operator<<(const unsigned char & i);
		messenger & operator<<(const unsigned int & i);
		messenger & operator<<(const unsigned long & i);
		messenger & operator<<(const double & d);
		void flush();
		void precision(int p);
	};
}

#endif
