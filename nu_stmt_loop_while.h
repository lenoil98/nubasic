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

#ifndef __NU_STMT_LOOP_WHILE_H__
#define __NU_STMT_LOOP_WHILE_H__


/* -------------------------------------------------------------------------- */

#include "nu_stmt.h"
#include "nu_token_list.h"
#include "nu_expr_any.h"

#include <string>


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */

class stmt_loop_while_t : public stmt_t
{
public:
   stmt_loop_while_t(prog_ctx_t & ctx,
                     expr_any_t::handle_t condition);

   stmt_loop_while_t() = delete;
   stmt_loop_while_t(const stmt_loop_while_t&) = delete;
   stmt_loop_while_t& operator=(const stmt_loop_while_t&) = delete;

   virtual void run(rt_prog_ctx_t& ctx) override;
   virtual stmt_cl_t get_cl() const throw() override;

protected:
   expr_any_t::handle_t _condition;
};


/* -------------------------------------------------------------------------- */

}


/* -------------------------------------------------------------------------- */

#endif //__NU_STMT_LOOP_WHILE_H__