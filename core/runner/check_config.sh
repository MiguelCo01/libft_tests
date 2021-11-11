# Check if my_config.sh file exists, otherwise create it
check_my_config_file()
{
	if [ ! -e ${PATH_TEST}/my_config.sh ]
	then
		printf "${BOLD}my_config.sh${DEFAULT} file is not found.\n"
		printf "Creating file...\n"
		if [ -e ${PATH_TEST}/core/templates/config_template.sh ]
		then
			cp ${PATH_TEST}/core/templates/config_template.sh ${PATH_TEST}/my_config.sh
			printf "File created with success in ${BOLD}${PURPLE}${PATH_TEST}\n${DEFAULT}"
			printf "${RED}${UNDERLINE}Edit my_config.sh file${DEFAULT} with the path of your libft project and launch script.\n"
		else
			printf "Can't create my_config.sh file, try to update or clone again the repository and retry.\n"
			exit
		fi
		exit
	fi
}
