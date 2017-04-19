OBJS_API =	api001.obj api002.obj api003.obj api004.obj api005.obj api006.obj \
			api007.obj api008.obj api009.obj api010.obj api011.obj api012.obj \
			api013.obj api014.obj api015.obj api016.obj api017.obj api018.obj \
			api019.obj api020.obj api021.obj api022.obj api023.obj api024.obj \
			api025.obj api026.obj api027.obj alloca.obj

TOOLPATH = ../../z_tools/
#TOOLPATH86 = ../../../tolset_p86/z_tools/
INCPATH  = ../../z_tools/haribote/

MAKE     = $(TOOLPATH)make -r
NASK     = $(TOOLPATH)nask
CC1      = $(TOOLPATH)gocc1 -I$(INCPATH) -Os -Wall -quiet
GAS2NASK = $(TOOLPATH)gas2nask -a
OBJ2BIM  = $(TOOLPATH)obj2bim
MAKEFONT = $(TOOLPATH)makefont
BIN2OBJ  = $(TOOLPATH)bin2obj
BIM2HRB  = $(TOOLPATH)bim2hrb
RULEFILE = ../haribote.rul
EDIMG    = $(TOOLPATH)edimg
GOLIB    = $(TOOLPATH)golib00
HARITOL  = $(TOOLPATH)haritol
COPY     = $(HARITOL) copy
DEL      = $(HARITOL) remove

#OBJCOPY  = $(TOOLPATH86)i386-elf-gcc/bin/i386-elf-objcopy
OBJCOPY  = $(HOME)/gcc-6.3.0/i386-elf-gcc/bin/i386-elf-objcopy

CLEAN_FILES := $(wildcard *.lst *.obj)

# デフォルト動作

default :
	$(MAKE) apilib.lib libapi.a

# ファイル生成規則

apilib.lib : Makefile $(OBJS_API)
	$(GOLIB) $(OBJS_API) out:apilib.lib

libapi.a : apilib.lib Makefile
	$(OBJCOPY) apilib.lib -I coff-i386 -O elf32-i386 libapi.a

# 一般規則

%.obj : %.nas Makefile
	$(NASK) $*.nas $*.obj $*.lst

# コマンド

clean :
	-$(DEL) $(CLEAN_FILES)

src_only :
	$(MAKE) clean
	-$(DEL) apilib.lib
