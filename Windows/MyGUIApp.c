
/*********************************************************************************************
 *                                                                                           *
 *  File: MyGUIApp.c                                                                         *
 *  Type: main program.                                                                      *
 *  Distribution: source/object code.                                                        *
 *  License: GNU General Public License ver3.                                                *
 *  Dependency: ,                                                                            *
 *  Desription: .                                                                            *
 *                                                                                           *
 *********************************************************************************************
 *                                                                                           *
 *     This is MyGUIApp.c file (main program).                                               *
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

/*********************************************************************************************
 *                                *** Header Files ***                                       *
 *********************************************************************************************/

#include "myguiapp.h"

/*********************************************************************************************
 *                              *** Global Variables ***                                     *
 *********************************************************************************************/

struct MYAPPDATA *AppData;

/*********************************************************************************************
 *                             *** Function Prototypes ***                                   *
 *********************************************************************************************/

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/*********************************************************************************************
 *                                *** WinMain Function ***                                   *
 *********************************************************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

  /* Memory Allocation */
  if(!(AppData=(struct MYAPPDATA*)LocalAlloc(LPTR,(sizeof(struct MYAPPDATA))))) goto ExitFailMem;

  AppData->MainWndClass.lpfnWndProc    = WindowProc;
  AppData->MainWndClass.hInstance      = hInstance;
  AppData->MainWndClass.hIcon          = LoadIcon(NULL,MAKEINTRESOURCE(IDI_APPLICATION));
  AppData->MainWndClass.hCursor        = LoadCursor(NULL,IDC_ARROW);
  AppData->MainWndClass.hbrBackground  = (HBRUSH)GetSysColorBrush(COLOR_3DFACE);;
  AppData->MainWndClass.lpszClassName  = TEXT("MyGUIApp\0");
  if(!RegisterClass(&(AppData->MainWndClass))) goto ExitFailClass;

  /* Main Window Creation */
  if(!(AppData->hMainWnd=CreateWindow((AppData->MainWndClass.lpszClassName),(AppData->MainWndClass.lpszClassName),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,(HWND)NULL,(HMENU)NULL,(AppData->MainWndClass.hInstance),(LPVOID)NULL))) goto ExitFailWnd;
  if(!IsWindowVisible(AppData->hMainWnd)) ShowWindow(AppData->hMainWnd,SW_SHOWNORMAL);

  /* Main Window Initialisation */
  GetClientRect(AppData->hMainWnd,&(AppData->rcMainWnd));

  /* Main Message Loop */
  while(!(AppData->uStatus))
  { if(GetMessage(&(AppData->msgMain),AppData->hMainWnd,0,0)<0) break;
    TranslateMessage(&(AppData->msgMain));
    DispatchMessage(&(AppData->msgMain)); };

ExitFailWnd:
  UnregisterClass((AppData->MainWndClass.lpszClassName),(AppData->MainWndClass.hInstance));

ExitFailClass:
  LocalFree((HLOCAL)AppData);

ExitFailMem:
  return(0); }

/*********************************************************************************************
 *                                *** End of File ***                                        *
 *********************************************************************************************/

