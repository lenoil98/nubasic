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
*  Author: Antonino Calderone <acaldmail@gmail.com>
*
*/


/* -------------------------------------------------------------------------- */

#ifndef __NU_STMT_CLS_H__
#define __NU_STMT_CLS_H__


/* -------------------------------------------------------------------------- */

#include "nu_stmt.h"
#include "nu_os_console.h"

#include <string>
#include <stdlib.h>


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */

class stmt_cls_t : public stmt_t
{
public:
   stmt_cls_t(prog_ctx_t & ctx) :
      stmt_t(ctx)
   {}

   stmt_cls_t() = delete;
   stmt_cls_t(const stmt_cls_t&) = delete;
   stmt_cls_t& operator=(const stmt_cls_t&) = delete;

   virtual void run(rt_prog_ctx_t& ctx) override;
};


/* -------------------------------------------------------------------------- */

}


/* -------------------------------------------------------------------------- */

#endif //__NU_STMT_CLS_H__
