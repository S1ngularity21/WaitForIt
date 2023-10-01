#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#include "Wait.h"

Wait::Wait(int argc, char **argv)
	: POSIXApplication(argc, argv)
{
	// Constructor for the Wait class. It initializes the application with command-line arguments.
	parser().setDescription("Wait for a specific process to finish. Provide a valid process ID as an argument.");
	parser().registerPositional("ID", "Process ID to wait for");
}

Wait::~Wait()
{
	// Destructor for the Wait class. It can be used for cleanup if needed.
}

Wait::Result Wait::exec()
{
	int status;
    
    const char *idArg = arguments().get("ID");
	char *endptr;
    pid_t pid = strtol(idArg, &endptr, 10);                                                                                                                                                                                 
    //pid_t pid;


    // Check if the ID argument is provided and is a valid integer.
    
    
    if (!idArg || !*idArg) {
        ERROR("Invalid ID argument");
        return IOError;
    }
    if (*endptr != '\0') {
        ERROR("Invalid ID argument");
        return IOError;
    
    }

     // Wait for the specified process ID to finish.
    printf("Waiting for process %d to finish...\n", pid);
    // Wait for the specified process ID to finish.
    if (waitpid(pid, &status, 0) == -1) {
        printf("Finished waiting for process %d, but an error occurred: %s\n", pid, strerror(errno));
        ERROR("Status Error: " << strerror(errno));
        return IOError;
    }
    printf("Finished waiting for process %d.\n", pid);
   

    return Success;	
}
