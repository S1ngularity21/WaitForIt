/*
 * Copyright (C) 2015 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Types.h>
#include <Macros.h>
#include <stdio.h>
#include <unistd.h>
#include <ProcessClient.h>
#include "ReniceAssign.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

ReniceAssign::ReniceAssign(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Reassign process priority level");
    parser().registerFlag('n', "nice", "Provide new priority level for process");
    parser().registerPositional("PTY", "Process priority value");
    parser().registerPositional("ID", "Process ID to apply the priority change");

}

ReniceAssign::Result ReniceAssign::exec()
{   


    

    //first get the process by its id and then use the priority number to schedule the process
    ProcessClient process;
    String out;

    if(arguments().get("nice")) {
        ProcessClient client;
        ProcessID pid = atoi(arguments().get("ID"));
        int priority = atoi(arguments().get("PTY"));
       
    
	//out << "ID  PRIORITY \r\n";
    //take the process id and use the ML algorithm to reassign its priority
    //first check if the process id is valid
    //const ProcessClient::Result result = process.processInfo(pid, info);
    //if (result == ProcessClient::Success)
    //{   
       if (priority < 1 || priority > 5)
        {
            return InvalidArgument;
        }
        client.setPriority(pid, priority);
        return Success;
   
    }
    return InvalidArgument;
}
