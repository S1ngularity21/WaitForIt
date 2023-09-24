#ifndef __BIN_WAIT_WAIT_H
#define __BIN_WAIT_WAIT_H

#include <POSIXApplication.h>

class Wait : public POSIXApplication
{
	public:
		Wait(int argc, char **argv);

		virtual ~Wait();

		virtual Result exec();
};

#endif
