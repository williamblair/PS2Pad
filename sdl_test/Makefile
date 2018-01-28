
# ---------------------------------------------------------

#ifndef SOURCE_PATH
#SOURCE_PATH = /home/bj/Documents/console_dev/ps2/glampert/glampert-ps2dev-tests-dfef4fc8fdeb/source
#endif

ifndef INSTALL_PATH
INSTALL_PATH = /Applications/pcsx2.app/Contents/Resources/pcsx2
endif

ifndef RUN_CMD
RUN_CMD = open -a pcsx2
endif

ifndef EE_BIN
EE_BIN = test_sdlpad.elf
endif

# ---------------------------------------------------------

EE_OBJS =                                           \
	../PS2Pad.o                                     \
	main.o

# ---------------------------------------------------------

EE_LIBS =     \
	-lc       \
	-ldma     \
	-lgraph   \
	-ldraw    \
	-lpatches \
	-lmf      \
	-lpad     \
	-lsdlmain \
	-lsdl     

# ---------------------------------------------------------

GLOBAL_DEFINES =                      \
	-I./                              \
	-I$(PS2SDK)/ports/include         \
	-Dnullptr=NULL                    \
	-DLOG_PRINTF_ADD_MESSAGE_PREFIX=1 \
	-DUSE_CUSTOM_ASSERT=1

# ---------------------------------------------------------

EE_CXXFLAGS +=                \
	-lstdc++                  \
	-O3                       \
	-funroll-loops            \
	-fexpensive-optimizations \
	-fno-exceptions           \
	-fno-rtti                 \
	-Wall                     \
	-Wformat=2                \
	-Wmissing-braces          \
	-Wparentheses             \
	-Wpointer-arith           \
	-Wreturn-type             \
	-Wsequence-point          \
	-Wswitch                  \
	-Wuninitialized           \
	-Wunknown-pragmas         \
	-Wwrite-strings           \
	$(GLOBAL_DEFINES)

EE_CFLAGS += -L$(PS2SDK)/ports/lib

# ---------------------------------------------------------

all: $(EE_BIN)
	ee-strip --strip-all $(EE_BIN)

# ---------------------------------------------------------

clean:
	rm -f *.elf $(EE_OBJS) *.a
# ---------------------------------------------------------

run: $(EE_BIN)
	cp $(EE_BIN) $(INSTALL_PATH)/$(EE_BIN)
	$(RUN_CMD)

# ---------------------------------------------------------

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

# ---------------------------------------------------------

