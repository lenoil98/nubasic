//  
// This file is part of nuBASIC
// Copyright (c) Antonino Calderone (antonino.calderone@gmail.com)
// All rights reserved.  
// Licensed under the MIT License. 
// See COPYING file in the project root for full license information.
//

/* -------------------------------------------------------------------------- */

#ifndef __NU_STMT_GOSUB_H__
#define __NU_STMT_GOSUB_H__


/* -------------------------------------------------------------------------- */

#include "nu_prog_pointer.h"
#include "nu_stmt.h"
#include <string>


/* -------------------------------------------------------------------------- */

namespace nu {


/* -------------------------------------------------------------------------- */

class stmt_gosub_t : public stmt_t {
public:
    stmt_gosub_t() = delete;
    stmt_gosub_t(const stmt_gosub_t&) = delete;
    stmt_gosub_t& operator=(const stmt_gosub_t&) = delete;

    stmt_gosub_t(prog_ctx_t& ctx, prog_pointer_t::line_number_t ln)
        : stmt_t(ctx)
        , _line_number(ln)
    {
    }

    stmt_gosub_t(prog_ctx_t& ctx, const std::string& label)
        : stmt_t(ctx)
        , _label(label)
    {
    }

    void run(rt_prog_ctx_t& ctx) override;

protected:
    prog_pointer_t::line_number_t _line_number = 0;
    std::string _label;
};


/* -------------------------------------------------------------------------- */

}


/* -------------------------------------------------------------------------- */

#endif //__NU_STMT_GOTO_H__
