INCLUDES	=	-I. -I${STAGING_DIR}usr/lib/glib-2.0/include -I${STAGING_DIR}usr/include/glib-2.0 -I${STAGING_DIR}usr/include
					
CFLAGS		=	-Os
				
LIBRARY		= 	liblunaservice.so

OBJECTS		= 	liblunaservice.o

.PHONY		: 	clean-objects clean


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
