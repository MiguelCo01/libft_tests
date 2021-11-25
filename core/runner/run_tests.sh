# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:08:00 by mmelo-da          #+#    #+#              #
#    Updated: 2021/11/24 18:35:01 by mmelo-da         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

TEST_FOLDER=${PATH_TEST}/tests

print_part_header()
{
	printf "\n${COLOR_PART}$(echo $1 | tr "[a-z]" "[A-Z]")\n\n"
	printf "${COLOR_TITLE}"
	printf "${DEFAULT}"
}

print_part_table_header()
{
	printf "${COLOR_TITLE}"
	printf "SUITE"
	printf "\033[${COMPIL_COL}GCOMPIL."
	printf "\033[${TESTS_COL}GTESTS"
	printf "\033[${RESULT_COL}GRESULT"
	printf "\n${DEFAULT}"
}

compile_test_file()
{
	if [ -e ${PATH_TEST}/test_file ]
	then
		rm -f ${PATH_TEST}/test_file
	fi
	COMPIL_FLAGS="-Wextra -Wall -Werror"
	MAIN_FILE="$1"
	FRAMEWORK="-I${PATH_TEST}/core/framework ${PATH_TEST}/core/framework/*.c"
	if [ ${DEBUG} == 1 ]
	then
		COMPIL_ARGS="${COMPIL_FLAGS} $1 -g  -I${PATH_LIBFT} ${PATH_LIBFT}/*.c  ${FRAMEWORK}"
	else
		COMPIL_ARGS="${COMPIL_FLAGS} $1  -L${PATH_LIBFT} -lft -I${PATH_LIBFT}  ${FRAMEWORK}"
	fi
	
	printf "$> gcc  ${COMPIL_ARGS} -o ${PATH_TEST}/test_file \n\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	compilation_error=$(gcc  ${COMPIL_ARGS} -o ${PATH_TEST}/test_file 2>&1 >/dev/null)
	RESULT=$?
	printf "\033[${COMPIL_COL}G"
	if [ ${RESULT} == 1 ]
	then
		printf "${compilation_error}" >> ${PATH_DEEPTHOUGHT}/deepthought
		printf "${RED}Not compiling${DEFAULT}"
		printf "\033[${TESTS_COL}G"
		printf "${RED}Not compiling${DEFAULT}"
		printf "\033[${RESULT_COL}G"
		printf "${RED}NOK${DEFAUL}"

		printf "\n"
		printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
		printf "\n${compilation_error}\n"
		printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
		printf "\n"
		printf "${DEFAULT}"
		return 0;
	else
		printf "${GREEN}OK${DEFAULT}"
		return 1;
	fi
}

run_single_test_file()
{
	printf "\033[${TESTS_COL}G"
	retvalue=1
	SUITE=
	not_ok=
	k=1
	HAS_MORE_TEST=1
	while [ ${HAS_MORE_TEST} == 1 ]
	do
		test_result=$(${PATH_TEST}/test_file ${k})
		#printf "$> ${PATH_TEST}/test_file ${k}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		SIG=$?
		CUR_SUITE="$(printf "${test_result}" | grep 'SUITE')"
		test_result="$(printf "${test_result}" | grep -v 'SUITE')"
		if [ $SIG -eq 134 ]
		then
			printf "Command './test_file' got killed by an Abort\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "${COLOR_FAIL}A${DEFAULT}"
			retvalue=0
			HAS_MORE_TEST=0
		elif [ $SIG -eq 138 ]
		then
			printf "Command './test_file' got killed by a Bus error\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "${COLOR_FAIL}B${DEFAULT}"
			retvalue=0
			HAS_MORE_TEST=0
		elif [ $SIG -eq 139 ]
		then
			printf "Command './test_file' got killed by a Segmentation fault\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "${COLOR_FAIL}S${DEFAULT}"
			retvalue=0
			HAS_MORE_TEST=0
		elif [ $SIG -eq 142 ]
		then
			printf "Command './test_file' got killed by a Timeout\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "${COLOR_FAIL}T${DEFAULT}"
			retvalue=0
			HAS_MORE_TEST=0
		elif [ $SIG -eq 255 ]
		then
			HAS_MORE_TEST=0
		elif [ $SIG -eq 1 ]
		then
			printf "${test_result}\n\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		#	printf "\nDiff KO :(\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			if [ "${CUR_SUITE}" != "${SUITE}" ]
			then
				not_ok="${not_ok}\n${CUR_SUITE}\n"
				SUITE=${CUR_SUITE}
			fi
			not_ok="${not_ok}\n${test_result}\n"
			retvalue=0
			printf "${COLOR_FAIL}✗${DEFAULT}"
			k=$(( $k + 1 ))
		else
			printf "${test_result}\n\n" >> ${PATH_DEEPTHOUGHT}/deepthought
		#	printf "\nDiff OK :D\n" >> ${PATH_DEEPTHOUGHT}/deepthought
			printf "${COLOR_OK}✓${DEFAULT}"
			k=$(( $k + 1 ))
		fi
	done

	if [ $retvalue == 0 ]
	then
		printf "\033[${RESULT_COL}G"
		printf "${RED}NOK${DEFAUL}"
	else
		printf "\033[${RESULT_COL}G"
		printf "${GREEN}OK${DEFAULT}"
	fi
	if [ ! -z "$not_ok" ]
	then
	printf "\n"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "${not_ok}\n"
	printf "%.s${CHAR_LENGTH}" $(seq 1 ${TITLE_LENGTH})
	printf "\n"
	printf "${DEFAULT}"
	fi
}

run_all_tests()
{
	BLOCKS=$(find ${TEST_FOLDER} -mindepth 1 -type d -exec basename {} \;)
	text="= Tests "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	for BLOCK in ${BLOCKS}
	do	
		#check if block has runnable tests according to pattern
		TOTAL_TEST_FILES=$(find ${TEST_FOLDER}/${BLOCK} -type f -name "*.c")
		RUNNABLE_TEST_FILES=$(echo "${TOTAL_TEST_FILES}" | grep "${TEST_PATTERN}")
		if [[ ! -z "${RUNNABLE_TEST_FILES}" ]]
		then
			print_part_header ${BLOCK}
			#load setup function 
			source ${TEST_FOLDER}/${BLOCK}/_setup.sh
			if [ ${HAS_BINARY} == 1 ]
			then
				print_header "BINARY COMPILATION"
				compile_binary
			fi
			check_required_functions $(echo ${BLOCK}_REQUIRED_FUN | tr '[:lower:]' '[:upper:]')
			check_forbbiden_functions $(echo ${BLOCK}_FORBIDDEN_FUN | tr '[:lower:]' '[:upper:]')
			
			print_header "TESTS"
			print_part_table_header
			for TEST_FILE in $(basename -a ${RUNNABLE_TEST_FILES})
			do
					text="= Test ${TEST_FILE} "
					printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
					printf "%.s=" $(seq 1 $(( 60 - ${#arg} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
					printf "\n" >> ${PATH_DEEPTHOUGHT}/deepthought
					printf	${TEST_FILE}
					compile_test_file ${TEST_FOLDER}/${BLOCK}/${TEST_FILE}
					if [ $? == 1 ]
					then
						run_single_test_file /${BLOCK}/${TEST_FILE}
					fi
					printf "\n"
			done
		fi
	done
	printf "\n"
}


check_should_test_run()
{
	retvalue=0

	if [ -z ${TEST_PATTERN} ]
	then
		return 1
	else
		for pattern in "${TEST_PATTERN[@]}"
		do
			if [[ $1 == *${pattern}* ]]
			then
				return 1
			fi
		done
	fi
	return 0
}

