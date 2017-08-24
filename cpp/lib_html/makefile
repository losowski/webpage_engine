# MAKEFILE for thie libhtml library

###############
# DEFINITIONS #
###############
# BASE DIRECTORY for install (/usr/local is good)
BASE_PREFIX = /usr/local
MAN_BASE_PREFIX = $(BASE_PREFIX)/share/man

LOCAL_BASE_PREFIX = ..
LOCAL_MAN_BASE_PREFIX = $(BASE_PREFIX)/share/man
# #DEFINE: These go into CFLAGS later
#OTHER1 -D_NAME_YOUR_DEFINE=99

######################
# SYSTEM DEFINITIONS #
######################
INSTALL= install
RM= rm -f
MKDIR = mkdir -p

###########
# INSTALL #
###########

# MAKE FILE VERSIONING
# VERSION
include Makefile.inc/VERSION

#MANUAL DEFINITIONS
MAN_DIR=$(MAN_BASE_DIR)/man1
# MAN_EXT No idea what this means
MAN_EXT=1


#BUILDING DEFINITIONS
BIN_DIR=$(BASE_PREFIX)/bin
LIB_DIR=$(BASE_PREFIX)/lib
LIB_DIR=$(BASE_PREFIX)/lib

INSTALL_PROGRAM_PERM=$(INSTALL) -c -m 0755 #readable and executable by anyone, writing restricted to user owner
INSTALL_DATA_PERM = $(INSTALL) -c -m 0644 #readable by anyone. Writable by user owner

#LOCALBUILDING DEFINITIONS
LOCAL_BIN_DIR=$(LOCAL_BASE_PREFIX)/bin
LOCAL_LIB_DIR=$(LOCAL_BASE_PREFIX)/lib
LOCAL_LIB_DIR=$(LOCAL_BASE_PREFIX)/lib


###############
# COMPILATION #
###############
#Compiler (gcc or g++)
CC ?= g++

TARGET_FLAG = -shared -fPIC -std=c++11
#Compiler options (i.e. pedantic etc -g = adds debugging)
COMPILER_OPTIONS = -g -Wall

#Compiler flags - and include the Makefile.inc/VERSION (VERSION)
CFLAGS = $(TARGET_FLAG) $(COMPILER_OPTIONS) -DVERSION=\"$(VERSION)\" #Other definitions $(OTHER1)

###################
## PROJECT FILES ##
###################
PROGRAM_NAME=libhtml
BINARY_TARGET=$(PROGRAM_NAME).so
#INCLUDES
INCLUDES = -I/form

#Libraries
LDFLAGS = -L../lib -L/usr/lib/x86_64-linux-gnu

#Soures
SRCS =  html_page.cpp html_title.cpp html_form.cpp form/html_form_input.cpp form/html_form_input_text.cpp form/html_form_input_password.cpp form/html_form_input_radio.cpp form/html_form_input_menu_selection.cpp form/html_form_input_menu.cpp html_header.cpp html_header_script.cpp html_header_style.cpp html_header_meta.cpp

###########
## MAGIC ##
###########
OBJECT_FILES = $(SRCS:.cpp=.o)

####################
# MAKEFILE SCRIPTS #
####################

default: $(BINARY_TARGET)
 
all: $(BINARY_TARGET)

$(BINARY_TARGET): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINARY_TARGET) $(OBJECT_FILES)

installdirs:
	test -d $(BIN_DIR) || $(MKDIR) $(BIN_DIR)
	test -d $(MAN_DIR) || $(MKDIR) $(MAN_DIR)

install: $(BINARY_TARGET) installdirs
	$(INSTALL_PROGRAM)	$(BINARY_TARGET)   $(BIN_DIR)/$(BINARY_TARGET)
	$(INSTALL_DATA)		$(BINARY_TARGET).$(MAN_EXT) $(MAN_DIR)/$(PROGRAM_NAME).$(MAN_EXT)

install:  local installdirs
	$(INSTALL_PROGRAM)	$(BINARY_TARGET)   $(LOCAL_BIN_DIR)/$(BINARY_TARGET)
	$(INSTALL_DATA)		$(BINARY_TARGET).$(MAN_EXT) $(LOCAL_MAN_DIR)/$(PROGRAM_NAME).$(MAN_EXT)

#No idea what this adds
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) $(OBJECT_FILES)
	$(RM) $(BINARY_TARGET)
	$(RM) *~ md5/*~

