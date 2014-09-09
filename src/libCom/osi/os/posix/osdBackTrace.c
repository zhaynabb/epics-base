/* 
 * Copyright: Stanford University / SLAC National Laboratory.
 *
 * EPICS BASE is distributed subject to a Software License Agreement found
 * in file LICENSE that is included with this distribution. 
 *
 * Author: Till Straumann <strauman@slac.stanford.edu>, 2011
 */ 

#include <execinfo.h>

#include "epicsStackTracePvt.h"

epicsShareFunc int epicsBackTrace(void **buf, int buf_sz)
{
	return backtrace(buf, buf_sz);
}
