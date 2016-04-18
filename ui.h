#ifndef ui_h
#define ui_h

#define TRUE 1
#define FALSE 0

/*
  Interface: get and execute commands; get integers, floats, and strings
 */
char get_command(char *msg);
int execute_command(char operator);
float get_float(char *msg);
int get_int(char *msg);
void get_string(char *msg, char *return_value);
#endif
