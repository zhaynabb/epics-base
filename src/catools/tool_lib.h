/*************************************************************************\
* Copyright (c) 2002 The University of Chicago, as Operator of Argonne
*     National Laboratory.
* Copyright (c) 2002 The Regents of the University of California, as
*     Operator of Los Alamos National Laboratory.
* Copyright (c) 2002 Berliner Elektronenspeicherringgesellschaft fuer
*     Synchrotronstrahlung.
* EPICS BASE Versions 3.13.7
* and higher are distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution. 
\*************************************************************************/
/* 
 *  $Id$
 *
 *  Author: Ralph Lange (BESSY)
 *
 */

#ifndef INCLtool_libh
#define INCLtool_libh

/* Convert status and severity to strings */
#define stat_to_str(stat)                                               \
        ((stat) >= 0 && (stat) <= (signed)lastEpicsAlarmCond) ? \
        epicsAlarmConditionStrings[stat] : "??"

#define sevr_to_str(stat)                                               \
        ((stat) >= 0 && (stat) <= (signed)lastEpicsAlarmSev) ?  \
        epicsAlarmSeverityStrings[stat] : "??"


#define CA_PRIORITY 50          /* CA priority */
#define DEFAULT_TIMEOUT 1.0     /* Default CA timeout */


/* Type of timestamp (absolute, relative, incremental) */
typedef enum { absTime, relTime, incTime } TimeT;

/* Output formats for integer data types */
typedef enum { dec, bin, oct, hex } IntFormatT;

/* Structure representing one PV (= channel) */
typedef struct 
{
    char* name;
    chid  chid;
    long  dbfType;
    long  dbrType;
    unsigned long nElems;
    unsigned long reqElems;
    int status;
    void* value;
} pv;


extern TimeT tsType;        /* Timestamp type flag (-q or -Q option) */
extern IntFormatT outType;  /* Flag used for -0.. output format option */
extern int charAsNr;        /* Used for -n option (get DBF_CHAR as number) */
extern double timeout;      /* Wait time default (see -w option) */
extern char dblFormatStr[]; /* Format string to print doubles (see -e -f option) */


extern char *val2str (const void *v, unsigned type, int index);
extern char *dbr2str (const void *value, unsigned type);
extern void print_time_val_sts (const pv *pv, int nElems);
extern int  connect_pvs (pv *pvs, int nPvs);

/*
 * no additions below this endif
 */
#endif /* ifndef INCLtool_libh */
