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

#include "nu_signal_handling.h"
#include <functional>

#ifdef _WIN32
#include <Windows.h>
#endif


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */
   
static bool _os_install_signal_handler(); //forward


/* -------------------------------------------------------------------------- */

signal_mgr_t * signal_mgr_t::_instance = nullptr;


/* -------------------------------------------------------------------------- */

signal_mgr_t& signal_mgr_t::instance()
{
   static bool _console_active = false;

   if (!_instance)
   {
      _instance = new signal_mgr_t();
      assert(_instance);
   }

   if (! _console_active
#ifdef _WIN32
         && GetConsoleWindow()
#endif
      )
   {
      _console_active = _os_install_signal_handler();
   }

   return *_instance;
}


/* -------------------------------------------------------------------------- */

bool signal_mgr_t::dispatch(signal_handler_t::event_t ev)
{
   auto handler = _handlers.find(ev);

   if (handler != _handlers.end() && ! handler->second.empty())
   {
      bool ret = true;

      for (auto h : handler->second)
         ret = h->notify(ev) && ret;

      return ret;
   }

   return false;
}


/* -------------------------------------------------------------------------- */

// Needed to implement information hiding mechanism
// Friendship with this function decouple o/s implementation
// dependences
bool _ev_dispatcher(signal_handler_t::event_t ev)
{
   if (! signal_mgr_t::instance()._disable_notifications)
      return signal_mgr_t::instance().dispatch(ev);

   return true;
}


/* -------------------------------------------------------------------------- */

} // namespace nu


/* -------------------------------------------------------------------------- */

// Windows implementation
#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <signal.h>


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */

static BOOL WINAPI console_handler(DWORD cevent)
{
   switch (cevent)
   {
      case CTRL_C_EVENT:
      case CTRL_BREAK_EVENT:
      case CTRL_CLOSE_EVENT:
         return _ev_dispatcher(nu::signal_handler_t::event_t::BREAK)
                ? TRUE : FALSE;

         //other not yet handled events are the following:
         //CTRL_CLOSE_EVENT
         //CTRL_LOGOFF_EVENT
         //CTRL_SHUTDOWN_EVENT
   }

   return FALSE;
}


/* -------------------------------------------------------------------------- */

static bool _os_install_signal_handler()
{
   return (FALSE != SetConsoleCtrlHandler(
              (PHANDLER_ROUTINE)console_handler,
              TRUE));
}


/* -------------------------------------------------------------------------- */

} // namespace nu


#else // Linux and others


/* -------------------------------------------------------------------------- */

#include <signal.h>


/* -------------------------------------------------------------------------- */

namespace nu
{


/* -------------------------------------------------------------------------- */

static void _ctrl_c_handler(int dummy=0)
{
   _ev_dispatcher(nu::signal_handler_t::event_t::BREAK);
}


/* -------------------------------------------------------------------------- */

static bool _os_install_signal_handler()
{
   return SIG_ERR != signal(SIGINT, _ctrl_c_handler);
}


/* -------------------------------------------------------------------------- */

} // namespace nu


/* -------------------------------------------------------------------------- */

#endif //... Linux implementation
