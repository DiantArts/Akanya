##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile of the entire project
##

ARGV		:=
BINDIR		:=	.

CFLAGS		+=	-Wpedantic -Wall -Wextra -std=c++17
CPPFLAGS	+=	-Iincludes -Ilibraries -Isources
LDFLAGS		+=	-L$(CURDIR) -L$(BINDIR)
LDLIBS		+=	

BASENAME	:=	threadPool
ifeq (debug,$(findstring debug, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_debug
CFLAGS		+=	-Ofast -pipe -DDEBUG=2
OBJDIR		:=	.objects/debug
LIBEXT		:=	_debug.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_debug,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_gdb,$(findstring auto_gdb, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_gdb
CFLAGS		+=	-g3 -Og -pipe
OBJDIR		:=	.objects/gdb
LIBEXT		:=	_gdb.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_gdb,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_valgrind,$(findstring auto_valgrind, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_valgrind
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
NAME		:=	$(BASENAME)
CFLAGS		+=	-Ofast -pipe
OBJDIR		:=	.objects/release
LIBEXT		:=	.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
endif
NAME		:=	$(BINDIR)/$(NAME)

all : $(NAME)

ifeq (tests_run,$(findstring tests_run, $(MAKECMDGOALS)))
$(NAME) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/main.cpp) $(shell find ./tests -type f -name \*.cpp)) $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir))) | $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) --coverage $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/main.cpp) $(shell find ./tests -type f -name \*.cpp)) $(LDFLAGS) $(LDLIBS)
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"
$(OBJDIR)/%o : .FORCE
	mkdir -p $(@D) $(patsubst .objects%,.dependencies%,$(@D))
	rm -f $(patsubst %o,%gcda,$@) $(patsubst %o,%gcno,$@)
	$(CXX) -c $(OUTPUT_OPTION) $(CFLAGS) $(CPPFLAGS) $(patsubst $(OBJDIR)/%o,%cpp,$@) -MT $@ -MMD -MP -MF $(patsubst .objects%o,.dependencies/%d,$@)
	@echo -e "$(LRED)[Compilation]$(NORMAL) $(patsubst $(OBJDIR)/%o,%cpp,$@)"
.FORCE:
else
$(NAME) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp)) $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir))) | $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp)) $(LDFLAGS) $(LDLIBS)
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"
$(OBJDIR)/%o : %cpp
	mkdir -p $(@D) $(patsubst .objects%,.dependencies%,$(@D))
	$(CXX) -c $(OUTPUT_OPTION) $(CFLAGS) $(CPPFLAGS) $< -MT $@ -MMD -MP -MF $(patsubst .objects%o,.dependencies/%d,$@)
	@echo -e "$(LRED)[Compilation]$(NORMAL) $<"
endif
$(BINDIR)/lib%$(LIBEXT) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./libraries/$% -type f -name \*.cpp))
	ar -rc $@ $^
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(BINDIR) :; mkdir -p $@

include $(shell find . -type f -name \*.d)

clean :
	rm -rf .objects .dependencies vgcore.*
	@echo -e "$(DARKGRAY)[Clean]$(NORMAL) done"

fclean : clean
	rm -f ./$(BINDIR)/$(BASENAME) ./$(BINDIR)/$(BASENAME)_debug ./$(BINDIR)/$(BASENAME)_valgrind ./$(BINDIR)/$(BASENAME)_gdb ./$(BINDIR)/unit_tests $(foreach libdir,$(patsubst ./libraries/%,./$(BINDIR)/lib%,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),$(libdir)$(LIBEXT) $(libdir)_debug$(LIBEXT) $(libdir)_valgrind$(LIBEXT) $(libdir)_gdb$(LIBEXT))
	if [[ "$(BINDIR)" != "." && "$(BINDIR)" != "" ]]; then rm -df ./$(BINDIR); fi
	@echo -e "$(DARKGRAY)[Fclean]$(NORMAL) done"

re :; $(MAKE) fclean; $(MAKE) all

auto			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)"					; valgrind -q ./$(NAME) $(ARGV)
debug			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) debug $(ARGV)"					; valgrind -q ./$(NAME) $(ARGV)
auto_valgrind	: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto valgrind $(ARGV)"			; valgrind --leak-check=full ./$(NAME) $(ARGV)
auto_gdb		: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto gdb $(ARGV)"				; gdb --args $(NAME) $(ARGV)
tests_run		: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) tests_run"						; ./$(NAME) ; gcovr -be tests

NORMAL			:=	\e[0m
DARKGRAY		:=	\e[1;30m
LRED			:=	\e[1;31m
YELLOW			:=	\e[1;33m

MAKEFLAGS		+=	--silent --no-print-directory
.PHONY: all clean fclean re $(NAME) $(NAME)_debug $(NAME)_valgrind $(NAME)_gdb unit_tests auto debug auto_valgrind auto_gdb tests_run
.PRECIOUS: $(OBJDIR)/%o
