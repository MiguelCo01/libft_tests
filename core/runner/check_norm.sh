# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_norm.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 04:48:01 by mmelo-da          #+#    #+#              #
#    Updated: 2021/11/06 11:20:54 by mmelo-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLN0=
COLN1="\033[25G"
COLN2="\033[45G"
COLN3="\033[65G"
COLN4="\033[85G"
COLN5="\033[100G"


check_norminette()
{
	print_header "NORMINETE"
	text="= Norminette "
	printf "\n${text}" >> ${PATH_DEEPTHOUGHT}/deepthought
	printf "%.s=" $(seq 1 $(( 80 - ${#text} ))) >> ${PATH_DEEPTHOUGHT}/deepthought

	printf "\n$> norminette\n" >> ${PATH_DEEPTHOUGHT}/deepthought

	COL=-1
	NORM=$(norminette ${PATH_LIBFT} | sed -e "s|$PATH_LIBFT/||g")
	printf "${NORM}" >> ${PATH_DEEPTHOUGHT}/deepthought

	NORM_OK=($(echo $NORM | grep "OK" | tr ": OK!" " "| tr ";" "\n"))
	for i in "${!NORM_OK[@]}"
	do
		COL=$((($COL + 1) % 4))
		COL_NUMBER=$(echo COLN${COL})
		printf "${!COL_NUMBER}${GREEN}[OK]  ${NORM_OK[i]}${WHITE}"
		if [ ${COL} == 3 ]
		then
			printf "\n"
		fi
	done

	NORM_NOK=($(echo $NORM | grep "NOK" | tr ": NOK!" " "| tr ";" "\n"))
	for i in "${!NORM_NOK[@]}"
	do
		COL=$((($COL + 1) % 4))
		COL_NUMBER=$(echo COLN${COL})
		printf "${!COL_NUMBER}${RED}[NOK] ${NORM_NOK[i]}${WHITE}"
		if [ ${COL} == 3 ]
		then
			printf "\n"
		fi
	done
	printf "\n"
}
