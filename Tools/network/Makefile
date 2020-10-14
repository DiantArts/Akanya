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
LDLIBS		+=	-pthread

BASENAME	:=	gameNetwork
BASE_SERVER_NAME := Server
BASE_CLIENT_NAME := Client

ifeq (debug,$(findstring debug, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_debug
SERVER_NAME	:=	$(BASE_SERVER_NAME)_debug
CLIENT_NAME	:=	$(BASE_CLIENT_NAME)_debug
CFLAGS		+=	-Ofast -pipe -DDEBUG=2
OBJDIR		:=	.objects/debug
LIBEXT		:=	_debug.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_debug,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_gdb,$(findstring auto_gdb, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_gdb
SERVER_NAME	:=	$(BASE_SERVER_NAME)_gdb
CLIENT_NAME	:=	$(BASE_CLIENT_NAME)_gdb
CFLAGS		+=	-g3 -Og -pipe
OBJDIR		:=	.objects/gdb
LIBEXT		:=	_gdb.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_gdb,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else ifeq (auto_valgrind,$(findstring auto_valgrind, $(MAKECMDGOALS)))
NAME		:=	$(BASENAME)_valgrind
SERVER_NAME	:=	$(BASE_SERVER_NAME)_valgrind
CLIENT_NAME	:=	$(BASE_CLIENT_NAME)_valgrind
CFLAGS		+=	-g3 -Og -pipe -DDEBUG=1
OBJDIR		:=	.objects/valgrind
LIBEXT		:=	_valgrind.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%_valgrind,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
else
NAME		:=	$(BASENAME)
SERVER_NAME	:=	$(BASE_SERVER_NAME)
CLIENT_NAME	:=	$(BASE_CLIENT_NAME)
CFLAGS		+=	-Ofast -pipe
OBJDIR		:=	.objects/release
LIBEXT		:=	.a
LDLIBS		+=	$(foreach libname,$(patsubst ./libraries/%,%,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries)),-l$(libname))
endif
NAME		:=	$(BINDIR)/$(NAME)

BASE_LDLIBS	:=	$(LDLIBS)
LDLIBS		+=	-l$(SERVER_NAME) -l$(CLIENT_NAME)

all : $(NAME)

$(BINDIR)/lib$(SERVER_NAME).a : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources/Server -type f -name \*.cpp ! -path ./sources/Server/main.cpp)) | $(BINDIR)
	ar -rc $@ $^
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(BINDIR)/lib$(CLIENT_NAME).a : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources/Client -type f -name \*.cpp ! -path ./sources/Client/main.cpp)) | $(BINDIR)
	ar -rc $@ $^
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(NAME) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/Server/\* ! -path ./sources/Client/\*)) $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),$(libdir))) | $(BINDIR)/lib$(CLIENT_NAME).a $(BINDIR)/lib$(SERVER_NAME).a $(BINDIR)
	$(CXX) $(OUTPUT_OPTION) $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./sources -type f -name \*.cpp ! -path ./sources/Server/\* ! -path ./sources/Client/\*)) $(LDFLAGS) $(LDLIBS)
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(OBJDIR)/%o : %cpp
	mkdir -p $(@D) $(patsubst .objects%,.dependencies%,$(@D))
	$(CXX) -c $(OUTPUT_OPTION) $(CFLAGS) $(CPPFLAGS) $< -MT $@ -MMD -MP -MF $(patsubst .objects%o,.dependencies/%d,$@)
	@echo -e "$(LRED)[Compilation]$(NORMAL) $<"

$(BINDIR)/lib%$(LIBEXT) : $(patsubst ./%cpp,$(OBJDIR)/%o,$(shell find ./libraries/$% -type f -name \*.cpp))
	ar -rc $@ $^
	@echo -e "$(LRED)[Linkage]$(NORMAL) $@"

$(BINDIR) :; mkdir -p $@

include $(shell find . -type f -name \*.d)

clean :
	rm -rf .objects .dependencies vgcore.*
	@echo -e "$(DARKGRAY)[Clean]$(NORMAL) done"

fclean : clean
	rm -f ./$(BINDIR)/$(BASENAME) ./$(BINDIR)/$(BASENAME)_debug ./$(BINDIR)/$(BASENAME)_valgrind ./$(BINDIR)/$(BASENAME)_gdb $(foreach libdir,$(shell find ./libraries -maxdepth 1 -type d ! -path ./libraries),$(patsubst ./libraries/%,$(BINDIR)/lib%$(LIBEXT),./$(BINDIR)/$(libdir) ./$(BINDIR)/$(libdir)_debug ./$(BINDIR)/$(libdir)_valgrind))
	rm -f ./$(BINDIR)/lib$(BASE_SERVER_NAME).a ./$(BINDIR)/lib$(BASE_SERVER_NAME)_debug.a ./$(BINDIR)/lib$(BASE_SERVER_NAME)_valgrind.a ./$(BINDIR)/lib$(BASE_SERVER_NAME)_gdb.a
	rm -f ./$(BINDIR)/lib$(BASE_CLIENT_NAME).a ./$(BINDIR)/lib$(BASE_CLIENT_NAME)_debug.a ./$(BINDIR)/lib$(BASE_CLIENT_NAME)_valgrind.a ./$(BINDIR)/lib$(BASE_CLIENT_NAME)_gdb.a
	rm -f ./$(BINDIR)/game*
	if [[ "$(BINDIR)" != "." && "$(BINDIR)" != "" ]]; then rm -df ./$(BINDIR); fi
	@echo -e "$(DARKGRAY)[Fclean]$(NORMAL) done"

re :; $(MAKE) fclean; $(MAKE) all

auto			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto $(ARGV)"					; valgrind -q ./$(NAME) $(ARGV)
debug			: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) debug $(ARGV)"					; valgrind -q ./$(NAME) $(ARGV)
auto_valgrind	: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto valgrind $(ARGV)"			; valgrind --leak-check=full ./$(NAME) $(ARGV)
auto_gdb		: all ; @echo -e "$(YELLOW)[Binary]$(NORMAL) auto gdb $(ARGV)"				; gdb --args $(NAME) $(ARGV)

NORMAL			:=	\e[0m
DARKGRAY		:=	\e[1;30m
LRED			:=	\e[1;31m
YELLOW			:=	\e[1;33m

MAKEFLAGS		+=	--silent --no-print-directory
.PHONY: all clean fclean re $(NAME) $(NAME)_debug $(NAME)_valgrind $(NAME)_gdb $(BASE_SERVER_NAME) $(BASE_SERVER_NAME)_debug $(BASE_SERVER_NAME)_valgrind $(BASE_SERVER_NAME)_gdb $(BASE_CLIENT_NAME) $(BASE_CLIENT_NAME)_debug $(BASE_CLIENT_NAME)_valgrind $(BASE_CLIENT_NAME)_gdb auto debug auto_valgrind auto_gdb
.PRECIOUS: $(OBJDIR)/%o
