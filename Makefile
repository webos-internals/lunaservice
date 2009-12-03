CC				=	$(CROSS_COMPILE)gcc

MAIN_INCLUDES	=	-I. \
					-I$(CROSS_COMPILE_ROOT)/usr/include/glib-2.0 \
					-I$(CROSS_COMPILE_ROOT)/usr/lib/glib-2.0/include \
					-I$(CROSS_COMPILE_ROOT)/usr/include/mjson \
					
ifeq ($(CS_TOOLCHAIN_ROOT),)				
	INCLUDES	=	$(MAIN_INCLUDES)
else
	INCLUDES	=	-L$(CS_TOOLCHAIN_ROOT)/arm-none-linux-gnueabi/libc/usr/lib \
					-Xlinker -rpath-link=$(CROSS_COMPILE_ROOT)/usr/lib \
					-L$(CROSS_COMPILE_ROOT)/usr/lib \
					$(MAIN_INCLUDES)
endif

ifeq ($(DEVICE),pre)
	MARCH_TUNE	=	-march=armv7-a -mtune=cortex-a8
else
ifeq ($(DEVICE),pixi)
	MARCH_TUNE	=	-march=armv6j -mtune=arm1136j-s
endif
endif

CFLAGS			=	-Os $(MARCH_TUNE)
					
LIBS			= 	-lglib-2.0

LIBRARY			= 	liblunaservice.so

OBJECTS			= 	liblunaservice.o

.PHONY			: 	clean-objects clean


all: $(LIBRARY)

fresh: clean all

$(LIBRARY): $(OBJECTS)
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(LIBRARY) $(OBJECTS) -o $(LIBRARY) $(INCLUDES) $(LIBS)

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $<  -o $@ -I. $(INCLUDES) $(LIBS)
	
clean-objects:
	rm -rf $(OBJECTS)
	
clean: clean-objects
	rm -rf $(LIBRARY)
