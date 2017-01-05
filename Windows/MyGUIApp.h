
/*********************************************************************************************
 *                                                                                           *
 *  File: MyGUIApp.h                                                                         *
 *  Type: MyApp main console program (MyGUIApp.h, MyGUIApp.c).                               *
 *  Distribution: source/object code.                                                        *
 *  License: GNU General Public License ver3.                                                *
 *  Dependency: ,                                                                            *
 *  Desription: main program.                                                                *
 *                                                                                           *
 *********************************************************************************************
 *                                                                                           *
 *     This is MyGUIApp.h file (main GUI program).                                       *
 *     Copyleft, 2016-2017, <feedback@7cats.biz>, cats7.                                     *
 *                                                                                           *
 *     This program is free software; you can redistribute it and/or modify it under the     *
 *  terms of the GNU General Public License as published by the Free Software Foundation;    *
 *  either version 3 of the License, or (at your option) any later version.                  *
 *                                                                                           *
 *     This program is distributed in the hope that it will be useful, but WITHOUT ANY       *
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A          *
 *  PARTICULAR PURPOSE.  See the GNU General Public License for more details.                *
 *                                                                                           *
 *********************************************************************************************/
#ifndef MYGUIAPP_H
#define MYGUIAPP_H

/*********************************************************************************************
 *                                *** Header Files ***                                       *
 *********************************************************************************************/

#include <windows.h>

/*********************************************************************************************
 *                              *** Global Variables ***                                     *
 *********************************************************************************************/

struct MYAPPDATA {
  UNIT uStatus;
  HWND hMainWnd;
  RECT rcMainWnd;
  MSG  msgMain;
  WNDCLASS MainWndClass;
};

/*********************************************************************************************
 *                                *** End of File ***                                        *
 *********************************************************************************************/
#endif // MYGUIAPP_H

