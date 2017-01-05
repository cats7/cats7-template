#===========================================================================================#
#                                                                                           #
#  File: MyApp.mak (ver 2.30).                                                              #
#  Type: Nmake script (for NMAKE ver. 9+).                                                  #
#  Distribution: source/object code. License: GNU General Public License ver3.              #
#  Dependency: .                                                                            #
#  Desription: .                                                                            #
#                                                                                           #
#===========================================================================================#
#                                                                                           #
#     This is MyApp.mak file.                                                               #
#     Copyleft, 2016-2017, <feedback@7cats.biz>, cats7.                                     #
#                                                                                           #
#     This library is free software; you can redistribute it and/or modify it under the     #
#  terms of the GNU General Public License as published by the Free Software Foundation;    #
#  either version 3 of the License, or (at your option) any later version.                  #
#                                                                                           #
#     This program is distributed in the hope that it will be useful, but WITHOUT ANY       #
#  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A          #
#  PARTICULAR PURPOSE.  See the GNU General Public License for more details.                #
#                                                                                           #
#===========================================================================================#

#===========================================================================================#
#                                     Include files                                         #
#===========================================================================================#

!include <Win32.Mak>

#===========================================================================================#
#                                Assembler flags (MASM ver.9+):                             #
#   -c   - assemble without linking;                                                        #
#   -Cx  - preserve case in publics, externs;                                               #
#   -Fl  - generate listing;                                                                #
#   -Zi  - add symbolic debug info;                                                         #
#   -Zd  - add line number debug info;                                                      #
#===========================================================================================#
MYASFLAGS = -c -Cx -nologo

#===========================================================================================#
#                                     Compiler flags:                                       #
#   -c   - compile without linking;                                                         #
#   -W3  - Set warning level to level 3 (-W4 for 64-bit compilations);                      #
#   -Zi  - generate debugging information;                                                  #
#   -Od  - disable all optimizations;                                                       #
#   -Ox  - use maximum optimizations;                                                       #
#   -Zd  - generate only public symbols and line numbers for debugging;                     #
#   -GS  - enable security checks;                                                          #
#   -GF  - enables string pooling;                                                          #
#   -Gz  - stdcall (only for 32-bit compilations);                                          #
#===========================================================================================#
MYWINVER  = -DUNICODE -DWINVER=$(NMAKE_WINVER) -D_WIN32_WINNT=$(NMAKE_WINVER) -D_WIN32_IE=$(_WIN32_IE)
MYCFLAGS  = $(MYWINVER) -c -nologo -Gz -O1 -GF -GS- -GR- -Zc:wchar_t -Zc:forScope

#===========================================================================================#
#                                Resource compiler flags:                                   #
#   -v   - displays messages that report on the progress of the compiler;                   #
#   -r   - emit RES-file (Ignored. Provided for compatibility with existing makefiles.);    #
#   -n   - append NULL`s to all strings in the string table;                                #
#   -c   - defines a code page used by NLS conversion (65001 - UTF8).                       #
#===========================================================================================#
MYRFLAGS  = $(MYWINVER) -nologo -r -n -c 65001

#===========================================================================================#
#                                     Linker flags:                                         #
#===========================================================================================#
MYLFLAGS  = $(guilflags) -release -map -stack:4194304

#===========================================================================================#
#                                     Linker librarys                                       #
#===========================================================================================#
MYCONLIBS = kernel32.lib user32.lib
MYGUILIBS = $(MYCONLIBS) gdi32.lib comctl32.lib comdlg32.lib advapi32.lib

#===========================================================================================#
#                             Rules for creating project files                              #
#===========================================================================================#
MYTARGET1 =
MYTARGETS = $(MYTARGET1).exe

MYOBJECT1 = $(MYTARGET1).obj file1.obj file2.obj

all: $(MYTARGETS)

$(MYTARGET1).obj: $(MYTARGET1).cpp
    @echo Compiling...
    $(cc) $(MYCFLAGS) -Fo$@ $**

file1.obj: file1.cpp
    @echo Compiling...
    $(cc) $(MYCFLAGS) -Fo$@ $**

file2.obj: file2.asm
    @echo Assembling...
    $(as) $(MYASFLAGS) -Fo $@ $**

$(MYTARGET1).res: $(MYTARGET1).rc
    $(rc) $(MYRFLAGS) -fo $@ $**

$(MYTARGET1).exe: $(MYOBJECT1) $(MYTARGET1).res
    @echo Linking...
    $(link) $(MYLFLAGS) -out:$@ $** $(MYGUILIBS)

#===========================================================================================#
#                             Rules for creating dump-files                                 #
#===========================================================================================#
dump: $(MYTARGET1).log

$(MYTARGET1).log: $(MYTARGET1).exe
    dumpbin -headers -exports -imports -out:$@ $**

#===========================================================================================#
#                       Rules for cleaning out those old files                              #
#===========================================================================================#
clean:
    erase /Q /F *~ *.obj *.res *.pdb *.suo *.sdf *.code *.lst *.map *.log *.il? *.cache *.resources *.meta *.tmp *.tl? *.rsp *.pg? *.tlog *.pch *.exp *.rep *.xdc *_manifest.rc *.bsc *.sbr *.metagen *.bi

cleanall: clean
    erase /Q /F *.exe

#===========================================================================================#
#                                     End of file.                                          #
#===========================================================================================#

