/*
Minetest
Copyright (C) 2013 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3.0 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

/*
Dummy database class
*/

#include "database-dummy.h"


bool Database_Dummy::saveBlock(const v3s16 &pos, const std::string &data)
{
	m_database[getBlockAsInteger(pos)] = data;
	return true;
}

std::string Database_Dummy::loadBlock(const v3s16 &pos)
{
	s64 i = getBlockAsInteger(pos);
	std::map<s64, std::string>::iterator it = m_database.find(i);
	if (it == m_database.end())
		return "";
	return it->second;
}

bool Database_Dummy::deleteBlock(const v3s16 &pos)
{
	m_database.erase(getBlockAsInteger(pos));
	return true;
}

void Database_Dummy::listAllLoadableBlocks(std::vector<v3s16> &dst)
{
	dst.reserve(m_database.size());
	for (std::map<s64, std::string>::const_iterator x = m_database.begin();
			x != m_database.end(); ++x) {
		dst.push_back(getIntegerAsBlock(x->first));
	}
}

