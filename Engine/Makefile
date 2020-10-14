##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of the entire project
##

ARGV		:=
BINDIR		:=	binary

CFLAGS		+=	-Wpedantic -Wall -Wextra -std=c++17
CPPFLAGS	+=	-Iincludes -Ilibraries -Isources
LDFLAGS		+=	-L$(CURDIR) -L$(BINDIR)
LDLIBS		+=	-lglfw -lGL -lGLEW -lGLU -lglut -lX11 -lpthread -lXrandr -lXi -ldl

ifeq (debug,$(findstring debug, $(MAKECMDGOALS)))
NAME		:=	engine_debug
CFLAGS		+=	-Ofast -pipe -DDEBUG=2
OBJDIR		:=	.objects/debug
LIBEXT		:=	_debug.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_debug,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_gdb,$(findstring auto_gdb, $(MAKECMDGOALS)))
NAME		:=	engine_gdb
CFLAGS		+=	-Ofast -pipe -DDEBUG=2
OBJDIR		:=	.objects/gdb
LIBEXT		:=	_gdb.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_gdb,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_valgrind,$(findstring auto_valgrind, $(MAKECMDGOALS)))
NAME		:=	engine_valgrind
CFLAGS		+=	-g3 -Og -pipe -DDEBUG=1
OBJDIR		:=	.objects/valgrind
LIBEXT		:=	_valgrind.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_valgrind,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (tests_run,$(findstring tests_run, $(MAKECMDGOALS)))
NAME		:=	unit_tests
CFLAGS		+=	-Ofast -pipe --coverage
OBJDIR		:=	.objects/tests
LDLIBS		+=	-lcriterion
LIBEXT		:=	.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else
NAME		:=	engine
CFLAGS		+=	-Ofast -pipe
OBJDIR		:=	.objects/release
LIBEXT		:=	.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
endif
NAME		:=	$(BINDIR)/$(NAME)

all : $(NAME)

ifeq (tests_run,$(findstring tests_run, $(MAKECMDGOALS)))
$(NAME) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/main.cpp) ./tests/tests.cpp) $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir))) | $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) --coverage $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/main.cpp) ./tests/tests.cpp) $(LDFLAGS) $(LDLIBS)
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"
else
$(NAME) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp)) $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir))) | $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp)) $(LDFLAGS) $(LDLIBS)
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"
endif
$(BINDIR)/lib%$(LIBEXT) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./libraries/$% -type f -name \*.cpp))
	ar -rc $@ $^
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(OBJDIR)/%o : %cpp
	mkdir -p $(@D) $(patsubst .objects%,.dependencies%,$(@D))
	$(CXX) -c $(OUTPUT_OPTION) $(CFLAGS) $(CPPFLAGS) $< -MT $@ -MMD -MP -MF $(patsubst .objects%o,.dependencies/%d,$@)
	@echo -e "$(LRED)[Compilation]$(NORMAL) $<"

$(BINDIR) :; mkdir -p $@

include $(shell find . -type f -name \*.d)

clean :
	rm -rf .objects .dependencies vgcore.*
	@echo -e "$(DARKGRAY)[Clean]$(NORMAL) done"

fclean : clean
	rm -f $(NAME) $(NAME)_debug $(NAME)_valgrind $(BINDIR)/unit_tests $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir) $(libdir)_debug $(libdir)_valgrind))
	if [[ "$(BINDIR)" != "." && "$(BINDIR)" != "" ]]; then rm -df ./$(BINDIR); fi
	@echo -e "$(DARKGRAY)[Fclean]$(NORMAL) done"

re :
	$(MAKE) fclean
	$(MAKE) all

auto			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)"					; ./$(NAME) $(ARGV)
debug			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) debug $(ARGV)"					; ./$(NAME) $(ARGV)
auto_valgrind	: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto valgrind $(ARGV)"			; valgrind ./$(NAME) $(ARGV)
auto_gdb		: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto gdb $(ARGV)"				; gdb --args $(NAME) $(ARGV)
tests_run		: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) tests_run"						; ./$(NAME) ; gcovr -be tests

NORMAL			:=	\e[0m
DARKGRAY		:=	\e[1;30m
LRED			:=	\e[1;31m
YELLOW			:=	\e[1;33m

MAKEFLAGS		+=	--silent --no-print-directory
.PHONY: all clean fclean re $(NAME) $(NAME)_debug $(NAME)_valgrind $(NAME)_gdb unit_tests auto debug auto_valgrind auto_gdb tests_run
.PRECIOUS: $(OBJDIR)/%o
