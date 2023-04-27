#ifndef __MAIN_H
#define __MAIN_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>








void print_chessboard(char (*a)[8]);

#endif /* __MAIN_H */
