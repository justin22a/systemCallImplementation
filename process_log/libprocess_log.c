#include "process_log.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//for compiling into a library
//gcc -c libprocess_log.c -o libprocess_log.o
//ar rcs libprocess_log.a libprocess_log.o

int get_proc_log_level()
{
int level = syscall(437);
return level;
}

int set_proc_log_level(int new_level)
{
int success = syscall(436 , new_level);
return success;
}

int proc_log_message(int level, char *message)
{

if(level < 0 || level > 7)
{
return -1;
}

if(syscall(437) < level)
{
return level;
}
int result = syscall(435, message,level);
return level;


}

int* retrieve_set_level_params(int new_level)
{
int* ptr;
ptr = (int*)malloc(3 * sizeof(int));
ptr[0] = 436;
ptr[1] = 1;
ptr[2] = new_level;
return ptr;
}


int* retrieve_get_level_params()
{
int* ptr;
ptr = (int*)malloc(2 * sizeof(int));
ptr[0] = 437;
ptr[1] = 0;
return ptr;
}


int interpret_set_level_result(int ret_value) 
{
return ret_value;
}

int interpret_get_level_result(int ret_value)
{
return ret_value;
}

int interpret_log_message_result(int ret_value)
{
return ret_value;
}
