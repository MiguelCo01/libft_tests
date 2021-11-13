# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_required_functions.sh                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 13:52:29 by mmelo-da          #+#    #+#              #
#    Updated: 2021/11/06 13:32:54 by mmelo-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

check_turned_in_functions()
{
	text="= $1 "
	printf "\n${text}\n" >> ${PATH_DEEPTHOUGHT}/deepthought
	if [[ -n $(echo ${LIB_CONTENT} | grep -w $(echo $1)) ]]
	then
		retvalue=1
		return "$retvalue"
	else

		retvalue=0
		return "$retvalue"
	fi
}

check_required_functions()
{
	print_header "Required Functions"
	text="= Required Functions "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought
	LIB_CONTENT=$(cat ${PATH_LIBFT}/libft.h)
	REQ_FUN_DEF=$(echo PART_1_REQUIRED_FUN[@] | tr '[:lower:]' '[:upper:]')
	REQ_FUN=($(echo ${!REQ_FUN_DEF} | tr ";" "\n"))
	COL=-1
	for func in "${REQ_FUN[@]}"
	do
		COL=$((($COL + 1) % 4))
		COL_NUMBER=$(echo COLN${COL})
		check_turned_in_functions ${func}
		if [ $? == 1 ]
		then
			printf "${!COL_NUMBER}${GREEN}[OK] ${func}${WHITE}"
		else
			printf "${!COL_NUMBER}${RED}[NOK] ${func}${WHITE}"
		fi
		if [ ${COL} == 3 ]
		then
			printf "\n"
		fi
	done
	printf "\n"
}
