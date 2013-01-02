//*********************************************/
// 
//  File:   debug.h
// 
//  Author:  Domenico La Fauci
// 
//********************************************/


#ifndef Debug_H
#define Debug_H

#include <stdio.h>
#include <string.h>

#define INFO_INIT_FLAG 	1
#define INFO_TCP_FLAG 	2
#define INFO_SPI_FLAG 	4
#define INFO_CM_FLAG 	8
#define INFO_UTIL_FLAG 16
#define INFO_5 32
#define INFO_D (1<<0xD)     // Debug
#define INFO_E (1<<0xE)     // Error
#define INFO_WARN_FLAG (1<<0xF)     // Warning
#define DEFAULT_INFO_FLAG 0 //INFO_WARN_FLAG

extern uint16_t enableDebug;
extern uint16_t verboseDebug;

#ifdef _INFO_DEBUG_
#define INFO_INIT(msg, args...) do { 			\
if (enableDebug & INFO_INIT_FLAG) printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)

#define INFO_TCP(msg, args...) do { 			\
if (enableDebug & INFO_TCP_FLAG) printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)

#define INFO_TCP_VER(msg, args...) do { 			\
if ((enableDebug & INFO_TCP_FLAG)&&(verboseDebug & INFO_TCP_FLAG)) \
	printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)


#define INFO_SPI(msg, args...) do { 			\
if (enableDebug & INFO_SPI_FLAG) printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)

#define INFO_SPI_VER(msg, args...) do { 			\
if ((enableDebug & INFO_SPI_FLAG)&&(verboseDebug & INFO_SPI_FLAG)) \
	printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)


#define INFO_UTIL(msg, args...) do { 			\
if (enableDebug & INFO_UTIL_FLAG) printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)

#define INFO_UTIL_VER(msg, args...) do { 			\
if ((enableDebug & INFO_UTIL_FLAG)&&(verboseDebug & INFO_UTIL_FLAG)) \
	printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)


#else
#define INFO_INIT(msg, args...) do {}while(0);
#define INFO_TCP(msg, args...) do {}while(0);
#define INFO_TCP_VER(msg, args...) do { }while(0);
#define INFO_SPI(msg, args...) do {}while(0);
#define INFO_SPI_VER(msg, args...) do { }while(0);
#define INFO_UTIL(msg, args...) do {}while(0);
#define INFO_UTIL_VER(msg, args...) do { }while(0);
#endif

#ifdef _APP_DEBUG_
#define INFO(msg, args...) do { 			\
printk("I-[%s] " msg , __func__ , ##args );	\
} while (0)

#else /* !defined(_DEBUG_) */
//#define INFO(msg, args...) do {} while (0)
#endif /* !defined(_DEBUG_) */

#if 1
#define WARN(msg, args...) do {	\
	if (enableDebug & INFO_WARN_FLAG) printk("W-[%s] " msg , __func__ , ##args );		\
	} while (0)
#else
#define WARN(msg, args...) do {		} while (0)
#endif

#define IF_DEBUG(X,Y) do { 			\
if (enableDebug & INFO_##X##_FLAG) \
Y;	\
} while (0)

#define IF_DEBUG_VER(X,Y) do { 			\
if ((enableDebug & INFO_##X##_FLAG)&&(verboseDebug & INFO_##X##_FLAG)) \
Y;	\
} while (0)

#define IF_WARN_VER(X) do { 			\
if ((enableDebug & INFO_WARN_FLAG)&&(verboseDebug & INFO_WARN_FLAG)) \
	X;	\
} while (0)

#define IF_WARN(Y) IF_DEBUG(WARN,Y)
#define IF_WARN_VER(Y) IF_DEBUG_VER(WARN,Y)
#define IF_TCP(Y) IF_DEBUG(TCP,Y)
#define IF_TCP_VER(Y) IF_DEBUG_VER(TCP,Y)
#define IF_SPI(Y) IF_DEBUG(SPI,Y)
#define IF_SPI_VER(Y) IF_DEBUG_VER(SPI,Y)
#define IF_UTIL(Y) IF_DEBUG(UTIL,Y)
#define IF_UTIL_VER(Y) IF_DEBUG_VER(UTIL,Y)

extern void dump(char* _buf, uint16_t _count);

#ifdef _APP_DEBUG_
#define DUMP(BUF, COUNT) do {		\
	printk("[%s]\n", __func__);		\
	dump((char*)BUF, COUNT);				\
	} while (0)
#else
#define DUMP(BUF, COUNT) do {} while (0)
#endif
#endif

#define DUMP_TCP(BUF, COUNT) do {			\
	if (verboseDebug & INFO_TCP_FLAG) {		\
	printk("[%s]\n", __func__);				\
	dump((char*)BUF, COUNT);				\
	}} while (0)

