PROJECT := TestProj
TopDir	:= $(shell pwd)
OutDir	:= Build

ifeq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    Detected_OS := Windows
	Exec_Ext := .exe
else
    Detected_OS := $(shell uname)  # same as "uname -s"
	Exec_Ext :=
endif

objs 	:= main.o C_Test.o Cpp_Test.o Fpt_Test.o

VPATH := $(TopDir) $(TopDir)/$(OutDir)
.SUFFIXES: $(Exec_Ext) .txt .inf

.PHONY: all createdir clean

all: detectos createdir $(OutDir)/$(PROJECT)$(Exec_Ext) $(OutDir)/$(PROJECT).txt

ifneq ($(Detected_OS),Windows)
all: $(OutDir)/$(PROJECT).inf
endif

# notice this should be after target "all".
# this is because we want "all" be our default (1st) target.
deplist := $(wildcard *.d)
ifneq ($(deplist),)
-include $(deplist)
endif

detectos:
	@echo 'Detected OS : $(Detected_OS)'

createdir: 
	[ -d $(OutDir) ] || echo '  MD      $(OutDir)' &&	mkdir -p $(OutDir)

# About the option "-MMD -MF $@.d" when invoking gcc : 
#   not only compile but also let CPP create dependence file *.o.d to 
#   describe user header files included so that we can make it our dependence also.

%.o:%.c
	gcc -c $< -g -o $@ -MMD -MF $@.d
	
%.o:%.cpp
	gcc -c $< -g -o $@ -MMD -MF $@.d

$(OutDir)/$(PROJECT)$(Exec_Ext): $(objs) makefile
	gcc $(objs) -lstdc++ -o $@
	chmod +x $@

%.inf:%$(Exec_Ext)
	readelf -a $< > $*.inf

%.txt:%$(Exec_Ext)
	objdump -x -S $< > $*.txt
	
clean: 
	-rm -rf $(OutDir)
	-rm *.o *.d
	echo "Deleted dir : $(OutDir) and obj files"

