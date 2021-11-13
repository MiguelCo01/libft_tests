# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    copy_files.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 20:08:29 by mmelo-da          #+#    #+#              #
#    Updated: 2021/11/13 19:03:42 by mmelo-da         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

copying_files()
{
	if [ -d ${PATH_TEST}/${TMP_TESTS_DIR} ]
	then
		rm -rf ${PATH_TEST}/${TMP_TESTS_DIR}
	fi
	printf "Copying files...\nPlease wait a moment.\n"
	mkdir ${PATH_TEST}/${TMP_TESTS_DIR}
	cp -r ${PATH_LIBFT}/* ${PATH_TEST}/${TMP_TESTS_DIR}
	#find ${PATH_LIBFT} -type f -name "*.[ch]" -print | xargs cp -t ${PATH_TEST}/dirlibft
	find ${PATH_LIBFT} -type f -name "*.[ch]" -exec cp {} ${PATH_TEST}/${TMP_TESTS_DIR}  \;
	PATH_LIBFT=${PATH_TEST}/${TMP_TESTS_DIR}
}


rm_files()
{
	if [ -e ${PATH_TEST}/test_file.dSYM ]
	then
		rm -rf ${PATH_TEST}/test_file.dSYM
	fi
	if [ -e ${PATH_TEST}/test_file ]
	then
		rm ${PATH_TEST}/test_file
	fi

	if [ -e ${PATH_TEST}/libft.h ]
	then
		rm ${PATH_TEST}/libft.h
	fi

	if [ -e ${PATH_TEST}/main_check_forbidden_function.c ]
	then
		rm ${PATH_TEST}/main_check_forbidden_function.c
	fi

	if [ -d ${PATH_TEST}/${TMP_TESTS_DIR} ]
	then
		rm -rf ${PATH_TEST}/${TMP_TESTS_DIR}
	fi
}
