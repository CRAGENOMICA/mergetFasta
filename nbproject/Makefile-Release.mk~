#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=bin
CND_BUILDDIR=build
CND_SOURCES=sources

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CStringTools.o \
	${OBJECTDIR}/CTFasta.o \
	${OBJECTDIR}/File.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/zindex.o \
	${OBJECTDIR}/zutil.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/mergetFasta

${CND_DISTDIR}/mergetFasta: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}
	${LINK.cc} -o ${CND_DISTDIR}/mergetFasta ${OBJECTFILES} ${LDLIBSOPTIONS} -lz -l:libboost_iostreams.a

${OBJECTDIR}/CStringTools.o: ${CND_SOURCES}/CStringTools.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CStringTools.o ${CND_SOURCES}/CStringTools.cpp

${OBJECTDIR}/CTFasta.o: ${CND_SOURCES}/CTFasta.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CTFasta.o ${CND_SOURCES}/CTFasta.cpp

${OBJECTDIR}/File.o: ${CND_SOURCES}/File.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/File.o ${CND_SOURCES}/File.cpp

${OBJECTDIR}/main.o: ${CND_SOURCES}/main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o ${CND_SOURCES}/main.cpp

${OBJECTDIR}/zindex.o: ${CND_SOURCES}/zindex.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/zindex.o ${CND_SOURCES}/zindex.c

${OBJECTDIR}/zutil.o: ${CND_SOURCES}/zutil.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/zutil.o ${CND_SOURCES}/zutil.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/mergetFasta

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
