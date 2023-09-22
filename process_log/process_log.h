#include <stdio.h>
#include <unistd.h>
#define PROC_LOG_CALL 435


int get_proc_log_level();
int set_proc_log_level(int new_level);
int proc_log_message(int level, char *message);
int* retrieve_set_level_params(int new_level); 
int* retrieve_get_level_params(); 
int interpret_set_level_result(int ret_value); 
int interpret_get_level_result(int ret_value); 
int interpret_log_message_result(int ret_value); 
