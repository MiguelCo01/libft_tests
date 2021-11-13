#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compil_lib.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:36 by jtoty             #+#    #+#              #
#    Updated: 2017/04/03 10:35:38 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
compile_binary()
{
	printf "$> make -C -g "$MK_PATH" all 1>/dev/null 2>&1" >> ${PATH_DEEPTHOUGHT}/deepthought
	RESULT=$(make -C -g "$MK_PATH" all 1>&1 2>&1)
	HAS_ERROR=$(echo ${RESULT} | grep errors)
	if [ "${HAS_ERROR}" != "" ]
	then
		printf "${RED}Error Compiling \n ${DEFAULT}${RESULT}"
		exit 1
	fi
}

set_makefile_var()
{
	if [ -e ${PATH_LIBFT}/Makefile ]
	then
		MAKEFILE_VAR="Makefile"
	elif [ -e ${PATH_LIBFT}/makefile ]
	then
		MAKEFILE_VAR="makefile"
	else
		MAKEFILE_VAR="missing_makefile"
	fi
	MK_PATH=${PATH_LIBFT}
}

remove_binary()
{
	if [ -e ${PATH_LIBFT}/${BINARY_NAME} ]
	then
		rm -f ${PATH_LIBFT}/${BINARY_NAME}
	fi
}
print_rules_headers()
{
	printf "make all"
	printf "\033[17Gmake clean"
	printf "\033[34Gmake fclean"
	printf "\033[51Gmake re"
	printf "\033[67Gmake clean"
	printf "\033[83Glibft.a\n"
}

clear_obj_and_binary()
{
	find ${PATH_LIBFT} -type f -name "*.o" -exec rm {} \;
	find ${PATH_LIBFT} -type f -name "*.a" -exec rm {} \;
}

check_rule_all()
{
	if [ -z "$(echo "$MK_CAT" | awk '$0 ~ /^all[\t ]*:/ {print}')" ]
	then
		printf "\n$> NO RULE: make all\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		printf "${COLOR_FAIL}missing rule${DEFAULT}"
	else
		printf "\n$> make all\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		make --no-print-directory -C ${PATH_LIBFT} all>>${PATH_DEEPTHOUGHT}/deepthought 2>&1
		if [ -e ${PATH_LIBFT}/${BINARY_NAME} ]
		then
			printf "\033[3G${COLOR_OK}ok${DEFAULT}"
			rm -f ${PATH_LIBFT}/${BINARY_NAME}
		else
			printf "\033[2G${COLOR_FAIL}fail${DEFAULT}"
		fi
	fi
}

check_rule_name()
{
	if [ -z "$(echo "$MK_CAT" | awk '$0 ~ /^\$\(NAME\)[\t ]*:/ {print}')" ]
	then
		printf "\n$> NO RULE: make $(NAME)\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		printf "${COLOR_FAIL}missing rule${DEFAULT}"
	else
		printf "\n$> make ${BINARY_NAME}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		make --no-print-directory -C ${PATH_LIBFT} all>>${PATH_DEEPTHOUGHT}/deepthought 2>&1
		if [ -e ${PATH_LIBFT}/${BINARY_NAME} ]
		then
			printf "\033[3G${COLOR_OK}ok${DEFAULT}"
		else
			printf "\033[2G${COLOR_FAIL}fail${DEFAULT}"
		fi
	fi
}



check_rule_clean()
{
	if [ -z "$(echo "$MK_CAT" | awk '$0 ~ /^clean[\t ]*:/ {print}')" ]
	then
		printf "\n$> NO RULE: make clean\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		printf "${COLOR_FAIL}missing rule${DEFAULT}"
	else
		printf "\n$> make clean\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		make --no-print-directory -C ${PATH_LIBFT} clean>>${PATH_DEEPTHOUGHT}/deepthought 2>&1
		if [ -z "$(ls -1 "$PATH_LIBFT" | awk '$0 ~ /\.o$/ {print}')" ]
		then
			printf "\033[21G${COLOR_OK}ok${DEFAULT}"
		else
			printf "\033[20G${COLOR_FAIL}fail${DEFAULT}"
		fi
	fi
}

makefile_check_rules()
{
	print_header "COMPILING LIB"
	text="= Compiling libft "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought

	if [ "${MAKEFILE_VAR}" == "missing_makefile" ]
	then
		text="Missing Makefile, can't compil library."
		printf "\033[$(( (${TITLE_LENGTH} - ${#text}) / 2 ))G${COLOR_FAIL}${text}${DEFAULT}\n\n"
		printf "\n${text}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	else
		print_rules_headers
		clear_obj_and_binary

		# Read the 'Makefile' and save it into a temporary variable $MK_CAT
		MK_CAT=`cat "${PATH_LIBFT}/${MAKEFILE_VAR}"`

		check_rule_all
		check_rule_clean
		check_rule_name
	fi
	printf "\n"
}

makefile_make_check()
{

		printf "\033[34G"
		printf "\033[51G"
		printf "\033[67G"
		printf "\033[83G"


	# Check if a rule named 'fclean:' does exist
	TEST=$(echo "$MK_CAT" | awk '$0 ~ /^fclean[\t ]*:/ {print}')
	if [ "$TEST" == "" ]
	then
		echo "Missing rule: 'fclean'"
		return
	fi

	# Check if a rule named 're:' does exist
	TEST=$(echo "$MK_CAT" | awk '$0 ~ /^re[\t ]*:/ {print}')
	if [ "$TEST" == "" ]
	then
		echo "Missing rule: 're'"
		return
	fi

	# Check if a rule named '$(NAME):' does exist
	TEST=$(echo "$MK_CAT" | awk '$0 ~ /^\$\(NAME\)[\t ]*:/ {print}')
	if [ "$TEST" == "" ]
	then
		echo "Missing rule: '\$(NAME)'"
		return
	fi

	# Clean the working directory by running 'make fclean'
	make -C "$MK_PATH" fclean 1>/dev/null 2>&1



	# Check if the rule 'fclean' is removing the binary
	make -C "$MK_PATH" fclean 1>/dev/null 2>&1
	if [ -f "$MK_PATH/$MK_BINARY" ]
	then
		echo "Failing rule: 'fclean' does not remove the binary"
		return
	fi

	# Check if the rule 're' is re-compiling the binary
	# 1. Get inode value of the binary after running 'make all'
	make -C "$MK_PATH" all 1>/dev/null 2>&1
	local TEST1=$(ls -i "$MK_PATH/$MK_BINARY")
	# 2. Get inode value of the binary after running 'make re'
	make -C "$MK_PATH" re 1>/dev/null 2>&1
	local TEST2=$(ls -i "$MK_PATH/$MK_BINARY" 2>/dev/null)
	# 3. When the two inode values are identical, the rule 're' has failed
	if [ "$TEST1" == "$TEST2" -o "$TEST2" == "" ]
	then
		echo "Failing rule: 're' is not re-compiling the binary"
		return
	fi

	# The test did not failed, everything is OK
	echo "Makefile seems to work perfectly"
}

# Declare a function that takes 2 arguments
makefile_checker()
{

	#Search for  makefile
	set_makefile_var
	remove_binary


	print_header "COMPILING LIB"
	text="= Compiling libft "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought

	if [ "${MAKEFILE_VAR}" == "missing_makefile" ]
	then
		text="Missing Makefile, can't compil library."
		printf "\033[$(( (${TITLE_LENGTH} - ${#text}) / 2 ))G${COLOR_FAIL}${text}${DEFAULT}\n\n"
		printf "\n${text}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	else
		makefile_make_check
	fi


}

func_compil_lib()
{



		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			find ${PATH_LIBFT} -type f -name "*.o" -exec rm {} \;
			printf "\n$> make $(grep -w NAME ${PATH_LIBFT}/${MAKEFILE_VAR} | grep = | cut -d '=' -f 2 | tr -d ' ' | tr -d '\t')\n" >> ${PATH_DEEPTHOUGHT}/deepthought

			make --no-print-directory -C ${PATH_LIBFT} $(grep NAME ${PATH_LIBFT}/${MAKEFILE_VAR} | grep = | cut -d '=' -f 2 | tr -d ' ' | tr -d '\t') >>${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w '$(NAME)' ${PATH_LIBFT}/${MAKEFILE_VAR} | grep ':' | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w '$(NAME)')" ]
			then
				printf "\033[17G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "\033[17G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[17G${COLOR_FAIL}fail${DEFAULT}"
					touch ${PATH_LIBFT}/libft.a
				fi
			fi
		else
			if [ -z "$(grep -w '$(NAME)' ${PATH_LIBFT}/${MAKEFILE_VAR} | grep ':' | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w '$(NAME)')" ]
			then
				printf "\033[17G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[17G${COLOR_OK}found${DEFAULT}"
			fi
		fi

		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			printf "\n$> make fclean\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			make --no-print-directory -C ${PATH_LIBFT} fclean >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [ -z "$(grep -w fclean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w fclean)" ]
			then
				printf "\033[34G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				LS_OBJ=$(ls -R ${PATH_LIBFT} | grep "\.o$")
				if [ ! -e ${PATH_LIBFT}/libft.a ] && [[ -z $(echo ${LS_OBJ}) ]]
				then
					printf "\033[34G${COLOR_OK}ok${DEFAULT}"
					# touch ${PATH_LIBFT}/libft.a
				else
					printf "\033[34G${COLOR_FAIL}fail${DEFAULT}"
					find ${PATH_LIBFT} -type f -name "*.o" -exec rm {} \;
					rm -f ${PATH_LIBFT}/libft.a
				fi
			fi
		else
			if [ -z "$(grep -w clean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w clean)" ]
			then
				printf "\033[34G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[34G${COLOR_OK}found${DEFAULT}"
			fi
		fi

		printf "\n$> make re\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		if [ ${OPT_FULL_MAKEFILE} -eq 1 ]
		then
			make --no-print-directory -C ${PATH_LIBFT} re >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			if [[ -n "$(grep -w bonus ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | grep bonus: | cut -d ':' -f 1 | grep -w bonus)" ]]
			then
				make --no-print-directory -C ${PATH_LIBFT} bonus >> ${PATH_DEEPTHOUGHT}/deepthought 2>&1
			fi
			if [ -z "$(grep -w re ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w re)" ]
			then
				printf "\033[51G${COLOR_FAIL}missing rule${DEFAULT}"
			else
				if [ -e ${PATH_LIBFT}/libft.a ]
				then
					printf "\033[51G${COLOR_OK}ok${DEFAULT}"
				else
					printf "\033[51G${COLOR_FAIL}fail${DEFAULT}"
				fi
			fi
		else
			if [ -z "$(grep -w fclean ${PATH_LIBFT}/${MAKEFILE_VAR} | tr -d ' ' | tr -d '\t' | cut -d ':' -f 1 | grep -w fclean)" ]
			then
				printf "\033[51G${COLOR_FAIL}not found${DEFAULT}"
			else
				printf "\033[51G${COLOR_OK}found${DEFAULT}"
			fi
		fi



		printf "\n$> ls -la libft.a\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		ls -la ${PATH_LIBFT}/libft.a >> ${PATH_DEEPTHOUGHT}/deepthought
		if [ -e ${PATH_LIBFT}/libft.a ]
		then
			printf "\033[83G${COLOR_OK}found\n\n${DEFAULT}"
		else
			printf "\033[83G${COLOR_FAIL}not found\n\n${DEFAULT}"
		fi
}


