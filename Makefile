##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## C/Cpp makefile
##

# =================================================================================================
# = DECLARATION ===================================================================================
# =================================================================================================

# ============================================================================= Basics

ARGV				:=
BINNAME				:=	akanya

# Directories
BINDIR				:=	binary
SRCDIR				:=	sources
LIBDIR				:=	libraries
TSTDIR				:=	tests
INCDIR				:=	includes
OBJDIR				:=	.objects
DEPDIR				:=	.dependencies

# Libraries
LIBNAME				:=	glfw GL GLEW GLU glut X11 pthread Xrandr Xi dl
LIBLOCATION			:=

# C
CC					:=	gcc
C_EXT				:=	.c
C_INCDIR			:=
C_FLAGS				:=

# CPP
CXX					:=	g++
CPP_EXT				:=	.cpp
CPP_INCDIR			:=	sources
CPP_FLAGS			:=	-Wpedantic -std=c++20 -Wno-volatile

# COMMON FLAGS
COMMON_INCDIR		:=	$(INCDIR) $(LIBDIR) externs
COMMON_WFLAGS		:=	all extra abi=11
COMMON_FLAGS		:=	

# Extentions
OBJEXT				:=	.o
DEPEXT				:=	.d
S_LIBEXT			:=	.a
D_LIBEXT			:=	.so

# Percentage (disable to optimise compilation)
# PERCENTAGE_PRINTING	:=	false

# ============================================================================= AutoDecleration

MODE_EXT			=	$(RELEASE_EXT)

# Directories
BINDIR				?=	./
SRCDIR				?=	sources
LIBDIR				?=	libraries
TSTDIR				?=	tests

# C
CFLAGS				+=	$(foreach flag, $(COMMON_WFLAGS),$(addprefix -W,$(flag))) $(C_FLAGS) $(COMMON_FLAGS)
C_CPPFLAGS			:=	$(foreach inc, $(C_INCDIR), $(addprefix -I,$(inc)))
C_SRC				!=	find $(SRCDIR) -type f -name \*$(C_EXT)

# CPP
CXXFLAGS			+=	$(foreach flag, $(COMMON_WFLAGS),$(addprefix -W,$(flag))) $(CPP_FLAGS) $(COMMON_FLAGS)
CXX_CPPFLAGS		:=	$(foreach inc, $(CPP_INCDIR), $(addprefix -I,$(inc)))
CXX_SRC				!=	find $(SRCDIR) -type f -name \*$(CPP_EXT)

# COMMON
LIB_DIR				!=	mkdir -p $(LIBDIR); find $(LIBDIR)/ -maxdepth 1 -type d ! -path $(LIBDIR)/
EXTERN_DIR			!=	find ./externs/ -maxdepth 1 -type d ! -path ./externs/
LDFLAGS				+=	-L$(CURDIR) -L$(BINDIR) $(foreach lib, $(LIBLOCATION),$(addprefix -L,$(lib)))
LDLIBS				+=	$(foreach lib, $(LIBNAME),$(addprefix -l,$(lib)))
CPPFLAGS			+=	$(foreach inc, $(COMMON_INCDIR), $(addprefix -I,$(inc)))


# ============================================================================= Mode debug
ifeq (debug,$(findstring debug,$(MAKECMDGOALS)))

MODE_EXT			:=	_debug
CFLAGS				+=	-g3 -Og -pipe -DDEBUG=2
CXXFLAGS			+=	-g3 -Og -pipe -DDEBUG=2
MOD_OBJDIR			:=	$(addsuffix /debug,$(OBJDIR))


# ============================================================================= Mode valgrind
else ifeq (auto_valgrind,$(findstring auto_valgrind,$(MAKECMDGOALS)))

MODE_EXT			:=	_valgrind
CFLAGS				+=	-g3 -Og -pipe -DDEBUG=1
CXXFLAGS			+=	-g3 -Og -pipe -DDEBUG=1
MOD_OBJDIR			:=	$(addsuffix /valgrind,$(OBJDIR))


# ============================================================================= Mode gdb
else ifeq (auto_gdb,$(findstring auto_gdb,$(MAKECMDGOALS)))

MODE_EXT			:=	_gdb
CFLAGS				+=	-g3 -Og -pipe
CXXFLAGS			+=	-g3 -Og -pipe
MOD_OBJDIR			:=	$(addsuffix /gdb,$(OBJDIR))

# ============================================================================= Mode release
else

MODE_EXT			:=
CFLAGS				+=	-Ofast -pipe
CXXFLAGS			+=	-Ofast -pipe
MOD_OBJDIR			:=	$(addsuffix /release,$(OBJDIR))

endif

# ============================================================================= Mode dependent

LDLIBS				+=	$(patsubst $(LIBDIR)/%,-l%$(MODE_EXT),$(LIB_DIR))
LIBBIN				:=	$(foreach libdir,$(LIB_DIR),$(patsubst $(LIBDIR)/%,$(BINDIR)/lib%$(MODE_EXT)$(S_LIBEXT),$(libdir)))

LDLIBS				+=	$(patsubst ./externs/%,-l%$(MODE_EXT),$(EXTERN_DIR))
EXTERNBIN			+=	$(foreach libdir,$(EXTERN_DIR),$(patsubst ./externs/%,$(BINDIR)/lib%$(MODE_EXT)$(S_LIBEXT),$(libdir)))

NAME				:=	$(BINDIR)/$(BINNAME)$(MODE_EXT)
DYNAMIC_LIB_NAME	:=	$(BINDIR)/lib$(BINNAME)$(D_LIBEXT)

SRC					:=	$(patsubst %$(C_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(C_SRC))
SRC					+=	$(patsubst %$(CPP_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(CXX_SRC))

SRC_LIB				:=	$(patsubst %$(CPP_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(shell find $(LIBDIR)/$% -type f -name \*$(CPP_EXT)))
SRC_LIB				+=	$(patsubst %$(C_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(shell find $(LIBDIR)/$% -type f -name \*$(C_EXT)))

SRC_LIB				+=	$(patsubst %$(CPP_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(shell find externs/$% -type f -name \*$(CPP_EXT)))
SRC_LIB				+=	$(patsubst %$(C_EXT),$(MOD_OBJDIR)/%$(OBJEXT),$(shell find externs/$% -type f -name \*$(C_EXT)))

# ============================================================================= UI

# display
PRINTF				:=	@printf

NORMAL				:=	\e[0m
BLACK				:=	\e[0;30m
DARKGRAY			:=	\e[1;30m
RED 				:=	\e[0;31m
LRED				:=	\e[1;31m
GREEN				:=	\e[0;32m
LGREEN				:=	\e[1;32m
BROWN				:=	\e[0;33m
YELLOW				:=	\e[1;33m
BLUE				:=	\e[0;34m
LBLUE				:=	\e[1;34m
PURPLE				:=	\e[0;35m
LPURPLE				:=	\e[1;35m
CYAN				:=	\e[0;36m
LCYAN				:=	\e[1;36m
LIGHT				:=	\e[0;37m
WHITE				:=	\e[1;37m

MAKEFLAGS			+=	--silent --no-print-directory

# =================================================================================================
# = RULES =========================================================================================
# =================================================================================================

# basics

all : $(NAME)

$(NAME) : $(SRC) $(LIBBIN) $(EXTERNBIN)
	$(CXX) $(OUTPUT_OPTION) $(SRC) $(LDFLAGS) $(LDLIBS)
	$(PRINTF) "$(LCYAN)[Linkage]$(NORMAL) $@\n"

ifneq ($(MAKECMDGOALS), count)
$(BINDIR)/lib%$(MODE_EXT)$(S_LIBEXT) : $(SRC_LIB) | $(BINDIR)
	ar -rc $@ $^
	$(PRINTF) "$(LCYAN)[Linkage]$(NORMAL) $@\n"

$(MOD_OBJDIR)/%$(OBJEXT) : %$(C_EXT)
	mkdir -p $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CC) -c $(OUTPUT_OPTION) $(CFLAGS) $(CPPFLAGS) $(C_CPPFLAGS) $< \
		-MT $@ -MMD -MP -MF $(patsubst $(OBJDIR)%$(OBJEXT),$(DEPDIR)/%$(DEPEXT),$@)
ifeq ($(PERCENTAGE_PRINTING), true)
	$(eval INDEX = $(shell printf "$$(($(INDEX)+1))"))
	$(PRINTF) "$(LCYAN)[Compilation]$(NORMAL) - $< (%.2f%c)\n" "$$((10000*$(INDEX)/$(COUNT)))e-2" '%'
else
	$(PRINTF) "$(LCYAN)[Compilation]$(NORMAL) - $<\n"
endif

$(MOD_OBJDIR)/%$(OBJEXT) : %$(CPP_EXT)
	mkdir -p $(@D) $(patsubst $(OBJDIR)%,$(DEPDIR)%,$(@D))
	$(CXX) -c $(OUTPUT_OPTION) $(CXXFLAGS) $(CPPFLAGS) $(CXX_CPPFLAGS) \
		$< -MT $@ -MMD -MP -MF $(patsubst $(OBJDIR)%$(OBJEXT),$(DEPDIR)/%$(DEPEXT),$@)
ifeq ($(PERCENTAGE_PRINTING), true)
	$(eval INDEX = $(shell printf "$$(($(INDEX)+1))"))
	$(PRINTF) "$(LCYAN)[Compilation]$(NORMAL) - $< (%.2f%c)\n" "$$((10000*$(INDEX)/$(COUNT)))e-2" '%'
else
	$(PRINTF) "$(LCYAN)[Compilation]$(NORMAL) - $<\n"
endif
endif


$(BINDIR):; mkdir -p $@

# cleaning

clean	:
	rm -rf .objects .dependencies vgcore.*
	$(PRINTF) "$(DARKGRAY)[Clean]$(NORMAL) done\n"

fclean				: clean
	rm -f $(BINDIR)/$(BINNAME) $(BINDIR)/$(BINNAME)_* $(DYNAMIC_LIB_NAME)
	$(foreach lib,$(LIBBIN),rm -f $(lib) $(patsubst %.a,%_*.a,$(lib)))
	$(foreach lib,$(EXTERNBIN),rm -f $(lib) $(patsubst %.a,%_*.a,$(lib)))
	if [[ -d $(BINDIR) ]]; then rmdir $(BINDIR); fi
	$(PRINTF) "$(DARKGRAY)[FClean]$(NORMAL) done\n"

re					:
	$(MAKE) fclean
	$(MAKE) all

# auto

auto				: all
	$(PRINTF) "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)\n"
	./$(NAME) $(ARGV)

debug				: all
	$(PRINTF) "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)\n"
	./$(NAME) $(ARGV)

auto_valgrind		: all
	$(PRINTF) "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)\n"
	valgrind ./$(NAME) $(ARGV)

auto_gdb			: all
	$(PRINTF) "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)\n"
	gdb --args $(NAME) $(ARGV)


ifneq "$(wildcard $(DEPDIR))" ""
include $(shell find $(DEPDIR) -type f -name \*$(DEPEXT))
endif
.PRECIOUS: $(MOD_OBJDIR)/%$(OBJEXT)

# =================================================================================================
# = Options =======================================================================================
# =================================================================================================

cat					:
	cat Makefile

extractDynamicLib: $(DYNAMIC_LIB_NAME) | $(BINDIR)

$(DYNAMIC_LIB_NAME)	: CFLAGS += -fPIC
$(DYNAMIC_LIB_NAME)	: CXXFLAGS += -fPIC
$(DYNAMIC_LIB_NAME)	: $(SRC) $(LIBBIN) $(EXTERNBIN) | $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) -shared -Wl,-soname,$(DYNAMIC_LIB_NAME) $(SRC) $(LDFLAGS) $(LDLIBS)
	$(PRINTF) "$(LCYAN)[Linkage]$(NORMAL) $@\n"

# =================================================================================================
# = UI  (uncompleted) =============================================================================
# =================================================================================================

ifeq ($(PERCENTAGE_PRINTING), true)

.NOTPARALLEL:
ifneq ($(MAKECMDGOALS), count)
ifneq ($(MAKECMDGOALS), fclean)
ifneq ($(MAKECMDGOALS), clean)
COUNT				!=	$(MAKE) count
INDEX				=	0
endif
endif
else
FILE_COUNTER		=	0
endif

count:	$(SRC) $(LIBBIN) $(EXTERNBIN)
	$(PRINTF) "$(FILE_COUNTER)\n"

ifeq ($(MAKECMDGOALS), count)
$(BINDIR)/lib%$(MODE_EXT)$(S_LIBEXT) : $(SRC_LIB);

$(MOD_OBJDIR)/%$(OBJEXT) : %$(C_EXT)
	$(eval FILE_COUNTER = $(shell printf "$$(($(FILE_COUNTER)+1))"))

$(MOD_OBJDIR)/%$(OBJEXT) : %$(CPP_EXT)
	$(eval FILE_COUNTER = $(shell printf "$$(($(FILE_COUNTER)+1))"))
endif

endif

.PHONY: all clean fclean re auto debug auto_valgrind auto_gdb cat extractDynamicLib count getCount Display
