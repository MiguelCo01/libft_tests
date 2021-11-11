# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grademe.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:11:44 by mmelo-da          #+#    #+#              #
#    Updated: 2021/11/08 11:10:57 by mmelo-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    grademe.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:26:01 by jtoty             #+#    #+#              #
#    Updated: 2017/02/28 11:42:36 by jtoty            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PATH_TEST=$(dirname $(readlink -f $0))
PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"

#exec 6>&2 2>/dev/null
# exec 2> /dev/null

cd ${PATH_TEST}


# Load Core Files
source ${PATH_TEST}/core/runner/check_config.sh
source ${PATH_TEST}/core/runner/copy_files.sh
source ${PATH_TEST}/core/runner/compil_lib.sh
source ${PATH_TEST}/core/runner/check_norm.sh
source ${PATH_TEST}/core/runner/print.sh
source ${PATH_TEST}/core/runner/colors.sh
source ${PATH_TEST}/core/runner/display.sh
source ${PATH_TEST}/core/runner/options.sh

source ${PATH_TEST}/core/runner/check_required_functions.sh
source ${PATH_TEST}/core/runner/check_forbbiden_functions.sh
source ${PATH_TEST}/core/runner/run_tests.sh




# SET options
RUN_CORE=1
RUN_TEST=1

for arg in ${@}
do
	case "${arg}" in
		"--test-only")	RUN_CORE=0;;
		esac
done


# Check if config file exist, if not tries to create it
check_my_config_file
# Load Config
source ${PATH_TEST}/my_config.sh

# Copy Original Lib Files
copying_files
clear

# Start Ddebug file
if [ -e ${PATH_DEEPTHOUGHT}/deepthought ]
then
	rm -f ${PATH_DEEPTHOUGHT}/deepthought
fi

if [ ${RUN_CORE} == 1 ]
then
	print_part_header "CORE"
	check_norminette
fi

if [ ${HAS_BINARY} == 1 ]
then
	set_makefile_var

	if [ ${RUN_CORE} == 1 ]
	then
		makefile_check_rules
	fi
	compile_binary
fi


if [ ${RUN_TEST} == 1 ]
then
	printf "\n\n"
	run_all_tests
fi

#rm_files
