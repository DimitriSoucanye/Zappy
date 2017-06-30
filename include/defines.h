/*
** defines.h for dsq in /home/galpin_a
**
** Made by Antoine Galpin
** Login   <galpin_a@epitech.net>
**
** Started on  Tue Jun 27 20:20:27 2017 Antoine Galpin
** Last update Tue Jun 27 20:20:28 2017 Antoine Galpin
*/

#ifndef __DEFINES_H__
# define __DEFINES_H__

# define DEBUG_MODE 1

/* CAST VALUES */
# define CAST_VOID(x) (void)(x)

/* SERVER MESSAGE */
# define REQUEST_MSZ "msz %d %d\n"
# define REQUEST_BCT "bct %d %d %d %d %d %d %d %d %d\n"
# define REQUEST_TNA "tna %s\n"
# define REQUEST_PNW "pnw #%d %d %d %d %d %s\n"
# define REQUEST_PPO "ppo #%d %d %d %s\n"
# define REQUEST_PLV "plv #%d %d\n"
# define REQUEST_PIN "pin #%d %d %d %d %d %d %d %d %d %d\n"
# define REQUEST_PEX "pex #%d\n"
# define REQUEST_PBC "pbc #%d %s\n"
# define REQUEST_PIC "pic %d %d %d #%d #%d ...\n"
# define REQUEST_PIE "pie %d %d %s\n"
# define REQUEST_PFK "pfk #%d\n"
# define REQUEST_PDR "pdr #%d %d\n"
# define REQUEST_PGT "pgt #%d %d\n"
# define REQUEST_PDI "pdi #%d\n"
# define REQUEST_ENW "enw #%d #%d %d %d\n"
# define REQUEST_EHT "eht #%d\n"
# define REQUEST_EBO "ebo %d\n"
# define REQUEST_EBI "ebi %d\n"
# define REQUEST_SGT "sgt %d\n"
# define REQUEST_SEG "seg %s\n"
# define REQUEST_SMG "smg %s\n"
# define REQUEST_SUC "suc\n"
# define REQUEST_SBP "sbp\n"

/* RETURN VALUES  */
# define ERROR 84
# define SUCCESS 0

/* ERROR MESSAGES */
# define ERROR_PORT "\nERROR: -p needs to have digits.\n\n"
# define ERROR_TIME "\nERROR: -t needs to have digits.\n\n"
# define ERROR_HEIGHT "\nERROR: -y needs to have digits.\n\n"
# define ERROR_HEIGHT_SIZE "\nERROR: -y needs to be between [10-30].\n\n"
# define ERROR_WIDTH_SIZE "\nERROR: -x needs to be between [10-30].\n\n"
# define ERROR_WIDTH "\nERROR: -x needs to have digits.\n\n"
# define ERROR_CLIENT "\nERROR: -c needs to have digits.\n\n"
# define ERROR_CLIENT_SIZE "\nERROR: -c needs to be between [1-9].\n\n"
# define ERROR_TIME_SIZE "\nERROR: -f needs to be between [2-10000].\n\n"
# define ERROR_TEAM_SIZE "\nERROR: -n needs to be [1-9].\n\n"
# define ERROR_NB_INFOS "ERROR: infos missing, use ./zappy_server --help\n"

/* USAGE MESSAGE */
# define FIRST_LINE_ONE "USAGE: ./server -p port -x width -y"
# define FIRST_LINE_TWO " height -n name1 name2 -c nbClients -t time\n"
# define SECOND_LINE "port\t is the port number\n"
# define THIRD_LINE "width\t is the width of the world\n"
# define FOUR_LINE "height\t is the height of the world\n"
# define FIVE_LINE "name1\t is the name of the team 1\n"
# define SIX_LINE "name2\t is the name of the team 2\n"
# define SEV_LINE "nbClients is the number of authorized clients per team\n"
# define EIGHT_LINE "time\t is the time limit for execution of actions\n"
# define SPACE_START "       "

/* SETUP SERVER */
# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2
# define MAX_FD 255

/* IA COMMANDS */
# define REQUEST_INVENTORY "[%d, %d, %d, %d, %d, %d, %d]\n"
# define REQUEST_LOOK "[%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s]\n"

#endif /* !__DEFINES_H__ */
