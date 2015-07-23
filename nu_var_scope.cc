/*
*  This file is part of nuBASIC
*
*  nuBASIC is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  nuBASIC is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with nuBASIC; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  US
*
*  Author: <antonino.calderone@ericsson.com>, <acaldmail@gmail.com>
*
*/


/* -------------------------------------------------------------------------- */

#include "nu_var_scope.h"


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */

void var_scope_t::get_err_msg(const std::string& key, std::string& err) const
{
   err = "'" + key + "' out of scope";
}


/* -------------------------------------------------------------------------- */

bool var_scope_t::define(const std::string& name, const variant_t& value)
{
   auto i = map().insert(std::make_pair(name, variant_t()));

   auto & item = (*(i.first));

   item.second = value;

   return i.second;
}


/* -------------------------------------------------------------------------- */

std::stringstream& operator<<(std::stringstream& ss, var_scope_t& obj)
{
   for (const auto & e : obj.map())
   {
      ss << "\t" << e.first.str() << ": " << e.second
         << (e.second.is_const() ? " CONST" : "") << std::endl;
   }

   return ss;
}


/* -------------------------------------------------------------------------- */

} // namespace nu
