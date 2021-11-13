#!/bin/bash

###################################
#     Mandatory configuration     #
###################################

#Edit the next line with the path of your libft project.
PATH_LIBFT=/goinfre/mmelo-da/42Private/libft
TMP_TESTS_DIR=TEMP_FILES

REQUIRED_FUN=(
	"ft_isalpha" \
	"ft_isdigit" \
	"ft_isalnum" \
	"ft_isascii" \
	"ft_isprint" \
	"ft_strlen" \
	"ft_memset" \
	"ft_bzero" \
	"ft_memcpy" \
	"ft_memmove" \
	"ft_strlcpy" \
	"ft_strlcat" \
	"ft_toupper" \
	"ft_tolower" \
	"ft_strchr" \
	"ft_strrchr" \
	"ft_strncmp" \
	"ft_memchr" \
	"ft_memcmp" \
	"ft_strnstr" \
	"ft_atoi" \
)
#If you use a relative path, don't put double quotes.
#For example :
#PATH_LIBFT=~/libft		==> Right
#PATH_LIBFT="~/libft"	==> Wrong

#If you encounter some problems with a relative path, use an absolute path.
#You can put double quotes with the absolute path.
#For example :
#PATH_LIBFT=/home/user/libft	==> Right
#PATH_LIBFT="/home/user/libft"	==> Right


HAS_BINARY=1
BINARY_NAME=libft.a

###################################
#     Optionnal configuration     #
###################################

#By default, the deepthought file will be generated in the grademe directory.
#Edit the next line with an absolute path if you want to change it.
PATH_DEEPTHOUGHT=${PATH_TEST}

#You can chose color and text effect.
#Colors available :
#	- BLACK
#	- CYAN
#	- GREEN
#	- YELLOW
#	- RED
#	- BLUE
#	- PURPLE
#	- WHITE

#Effects available :
#	- BOLD
#	- UNDERLINE

#For example :
#COLOR_EXAMPLE="${UNDERLINE}${BOLD}${PURPLE}

COLOR_OK="${GREEN}"
COLOR_FAIL="${RED}"
COLOR_WARNING="${YELLOW}"
COLOR_TITLE="${BOLD}${BLUE}"
COLOR_FUNC="${CYAN}"
COLOR_PART="${UNDERLINE}${PURPLE}"
COLOR_TOTAL="${BOLD}${YELLOW}"
COLOR_DEEPTHOUGHT_PATH="${BOLD}${PURPLE}"
