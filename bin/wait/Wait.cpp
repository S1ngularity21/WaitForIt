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
	parser().setDescription("Wait for program to finish");
	parser().registerPositional("ID", "Stop program execution");
}

Wait::~Wait()
{
	//test
}

Wait::Result Wait::exec()
{
	int status;
	pid_t pid = atoi(arguments().get("ID"));

	if(waitpid(pid, &status, 0) == (pid_t) -1) {
		ERROR("Status Error");
		return IOError;
	}

	return Success;

}

