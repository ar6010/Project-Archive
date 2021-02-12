/*
 * Andrew Ramirez
 * CS 3841-011
 * Lab 3 TTSH
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_MAX 256
#define CMD_MAX 5

/* read_cmd_string()
 *     Reads a line of text from the user
 *         Parameters:  dest - target location for the input
 *         Returns: int - 0 on success or
 *                        -1 on error
 */
int read_cmd_string(char dest[INPUT_MAX])
{
    // Read user input
    if(fgets(dest, INPUT_MAX, stdin) == NULL) {
        fprintf(stderr, "Unable to read user input\n");
        return -1;
    }

    // Remove trailing return character
    int len = strlen(dest);
    if(dest[len-1] == '\n') {
        dest[len - 1] = '\0';
    }

    return 0;
}

/* parse_commands()
 *     Reads a line of text from the user
 *         Parameters:  input - string containing user input
 *                      cmd_strs - the target array for command strings
 *         Returns: int - The number of commands found or
 *                        -1 on error
 */
int parse_commands(char input[INPUT_MAX], char cmd_strs[CMD_MAX][INPUT_MAX])
{
    // Chop the input into command strings
    int cmd_count = 0;
    char* cmd_ptr = strtok(input, ";");
    while(cmd_ptr) {
        if(cmd_count >= CMD_MAX) {
            fprintf(stderr, "Too many commands\n");
            return -1;
        }
        strncpy(cmd_strs[cmd_count], cmd_ptr, INPUT_MAX);
        cmd_count++;
        cmd_ptr = strtok(NULL, ";");
    }

    return cmd_count;
}

int main()
{
    char user_input[INPUT_MAX];
    char cmd_strs[CMD_MAX][INPUT_MAX];

    // TODO need to be able to get input from
    //    the user in a loop
    while(1) {

        // Print the input prompt
        printf("$> ");

        // Read user input
        if (read_cmd_string(user_input) == -1) {
            return 1;
        }

        // Chop the input into command strings
        int cmd_count = parse_commands(user_input, cmd_strs);
        if (cmd_count == -1) {
            return 1;
        }

        // Chop the commands into arguments and execute one at a time
        for (int i = 0; i < cmd_count; i++) {

            int counter = 1;
            char space[2] = " ";
            char* args[11] = {"0"};
            char* cmd = strtok(cmd_strs[i], space);
            args[0] = cmd;


            //Quit process routine
            if(strcmp(args[0],"quit") == 0){
                return 0;
            }

            //send command arguments to an array
            while(cmd != NULL){
                cmd = strtok(NULL, space);
                args[counter] = cmd;
                counter++;
            }

            //Fork the process
            pid_t pid = fork();

            if(pid<0){
                printf("Failure to Fork");
            } else if(pid == 0){ //Execute command in child process
                int check = execvp(args[0], args);
                if(check < 0){
                    printf("Command not found\n");
                }
                return 0;
            } else {
                wait(0); //Wait for child to finish
            }

        }


    }
    return 0;
}
