INCLUDES	=	-I. -I$(ROOT)$(prefix)/lib/glib-2.0/include -I$(ROOT)$(prefix)/include/glib-2.0 -I$(ROOT)$(prefix)/include -I$(ROOT)$(prefix)/include/mjson
					
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
