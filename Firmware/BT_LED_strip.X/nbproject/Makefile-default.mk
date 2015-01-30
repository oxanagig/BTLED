#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/mcc_generated_files/cmp1.c ../src/mcc_generated_files/eusart.c ../src/mcc_generated_files/fvr.c ../src/mcc_generated_files/interrupt_manager.c ../src/mcc_generated_files/mcc.c ../src/mcc_generated_files/memory.c ../src/mcc_generated_files/pin_manager.c ../src/mcc_generated_files/tmr1.c ../src/LED.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1677160165/cmp1.p1 ${OBJECTDIR}/_ext/1677160165/eusart.p1 ${OBJECTDIR}/_ext/1677160165/fvr.p1 ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1 ${OBJECTDIR}/_ext/1677160165/mcc.p1 ${OBJECTDIR}/_ext/1677160165/memory.p1 ${OBJECTDIR}/_ext/1677160165/pin_manager.p1 ${OBJECTDIR}/_ext/1677160165/tmr1.p1 ${OBJECTDIR}/_ext/1360937237/LED.p1 ${OBJECTDIR}/_ext/1360937237/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1677160165/cmp1.p1.d ${OBJECTDIR}/_ext/1677160165/eusart.p1.d ${OBJECTDIR}/_ext/1677160165/fvr.p1.d ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d ${OBJECTDIR}/_ext/1677160165/mcc.p1.d ${OBJECTDIR}/_ext/1677160165/memory.p1.d ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d ${OBJECTDIR}/_ext/1360937237/LED.p1.d ${OBJECTDIR}/_ext/1360937237/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1677160165/cmp1.p1 ${OBJECTDIR}/_ext/1677160165/eusart.p1 ${OBJECTDIR}/_ext/1677160165/fvr.p1 ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1 ${OBJECTDIR}/_ext/1677160165/mcc.p1 ${OBJECTDIR}/_ext/1677160165/memory.p1 ${OBJECTDIR}/_ext/1677160165/pin_manager.p1 ${OBJECTDIR}/_ext/1677160165/tmr1.p1 ${OBJECTDIR}/_ext/1360937237/LED.p1 ${OBJECTDIR}/_ext/1360937237/main.p1

# Source Files
SOURCEFILES=../src/mcc_generated_files/cmp1.c ../src/mcc_generated_files/eusart.c ../src/mcc_generated_files/fvr.c ../src/mcc_generated_files/interrupt_manager.c ../src/mcc_generated_files/mcc.c ../src/mcc_generated_files/memory.c ../src/mcc_generated_files/pin_manager.c ../src/mcc_generated_files/tmr1.c ../src/LED.c ../src/main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=12F1822
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1677160165/cmp1.p1: ../src/mcc_generated_files/cmp1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/cmp1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/cmp1.p1  ../src/mcc_generated_files/cmp1.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/cmp1.d ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/eusart.p1: ../src/mcc_generated_files/eusart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/eusart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/eusart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/eusart.p1  ../src/mcc_generated_files/eusart.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/eusart.d ${OBJECTDIR}/_ext/1677160165/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/fvr.p1: ../src/mcc_generated_files/fvr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/fvr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/fvr.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/fvr.p1  ../src/mcc_generated_files/fvr.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/fvr.d ${OBJECTDIR}/_ext/1677160165/fvr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/fvr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1: ../src/mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1  ../src/mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.d ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/mcc.p1: ../src/mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/mcc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/mcc.p1  ../src/mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/mcc.d ${OBJECTDIR}/_ext/1677160165/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/memory.p1: ../src/mcc_generated_files/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/memory.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/memory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/memory.p1  ../src/mcc_generated_files/memory.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/memory.d ${OBJECTDIR}/_ext/1677160165/memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/pin_manager.p1: ../src/mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/pin_manager.p1  ../src/mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/pin_manager.d ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/tmr1.p1: ../src/mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/tmr1.p1  ../src/mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/tmr1.d ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/LED.p1: ../src/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/LED.p1  ../src/LED.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/LED.d ${OBJECTDIR}/_ext/1360937237/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/main.p1: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/main.p1  ../src/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/main.d ${OBJECTDIR}/_ext/1360937237/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1677160165/cmp1.p1: ../src/mcc_generated_files/cmp1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/cmp1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/cmp1.p1  ../src/mcc_generated_files/cmp1.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/cmp1.d ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/cmp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/eusart.p1: ../src/mcc_generated_files/eusart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/eusart.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/eusart.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/eusart.p1  ../src/mcc_generated_files/eusart.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/eusart.d ${OBJECTDIR}/_ext/1677160165/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/fvr.p1: ../src/mcc_generated_files/fvr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/fvr.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/fvr.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/fvr.p1  ../src/mcc_generated_files/fvr.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/fvr.d ${OBJECTDIR}/_ext/1677160165/fvr.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/fvr.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1: ../src/mcc_generated_files/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1  ../src/mcc_generated_files/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.d ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/mcc.p1: ../src/mcc_generated_files/mcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/mcc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/mcc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/mcc.p1  ../src/mcc_generated_files/mcc.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/mcc.d ${OBJECTDIR}/_ext/1677160165/mcc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/mcc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/memory.p1: ../src/mcc_generated_files/memory.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/memory.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/memory.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/memory.p1  ../src/mcc_generated_files/memory.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/memory.d ${OBJECTDIR}/_ext/1677160165/memory.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/memory.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/pin_manager.p1: ../src/mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/pin_manager.p1  ../src/mcc_generated_files/pin_manager.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/pin_manager.d ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/pin_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1677160165/tmr1.p1: ../src/mcc_generated_files/tmr1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1677160165" 
	@${RM} ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1677160165/tmr1.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1677160165/tmr1.p1  ../src/mcc_generated_files/tmr1.c 
	@-${MV} ${OBJECTDIR}/_ext/1677160165/tmr1.d ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1677160165/tmr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/LED.p1: ../src/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/LED.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/LED.p1  ../src/LED.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/LED.d ${OBJECTDIR}/_ext/1360937237/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1360937237/main.p1: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1360937237/main.p1  ../src/main.c 
	@-${MV} ${OBJECTDIR}/_ext/1360937237/main.d ${OBJECTDIR}/_ext/1360937237/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1360937237/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"      --ram=default,-b0-bf,-fe3-fe3  -odist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.map  --double=24 --float=24 --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,+osccal,-resetbits,-download,-stackcall,+clib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     -odist/${CND_CONF}/${IMAGE_TYPE}/BT_LED_strip.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
