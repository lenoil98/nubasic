' -----------------------------------------------------------------------------
'  bitmap.bas
' -----------------------------------------------------------------------------
'
'  This file is part of nuBASIC
'
'  nuBASIC is free software; you can redistribute it and/or modify
'  it under the terms of the GNU General Public License as published by
'  the Free Software Foundation; either version 2 of the License, or
'  (at your option) any later version.
'
'  nuBASIC is distributed in the hope that it will be useful,
'  but WITHOUT ANY WARRANTY; without even the implied warranty of
'  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
'  GNU General Public License for more details.
'
'  You should have received a copy of the GNU General Public License
'  along with nuBASIC; if not, write to the Free Software
'  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  US
'
'  Author: <antonino.calderone@ericsson.com>, <acaldmail@gmail.com>

' ------------------------------------------------------------------------------
Input "Insert bitmap name: "; file$
' ------------------------------------------------------------------------------

FOpen file$, "r", 1

If FError(1) Then
   MsgBox "Error", file$ + " not found"
   End
End If

Close #1

PlotImage file$, 0, 0 

End
