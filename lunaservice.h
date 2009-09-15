/*
 * lunaservice.h
 */

/* The existence of this header file is disclosed at line 38 of
   LibpurpleAdapter.c, a file licensed under the LGPL 2.1, from
   http://palm.cdnetworks.net/opensource/1.1.0/libpurple-adapter-1.0.tgz */

/* *********************************************/
/* Types that must be defined in lunaservice.h */
/* *********************************************/

/* The existence of the LSHandle type is first disclosed at line 59 of
   LibpurpleAdapter.c */
/* The specific type of LSHandle is not completely known at this
   time. There are no references to fields of a structure in the code,
   and variables of type LSHandle* seem to be always used as opaque
   pointers, except for line 2600 where a reference to an LSHandle* is
   passed to the LSRegister function, leading us to believe that it is
   probably a typedef of a struct of some sort. */

typedef struct LSHandleStruct LSHandle;

/* The existence of the LSError type is first disclosed at line 685 of
   LibpurpleAdapter.c */
/* The specific type of LSError is not completely known at this
   time. There are no references to fields of a structure in the code,
   and variables of type LSError* seem to be always used as opaque
   pointers. Let's assume for the moment that it's a typedef of a
   struct just like LSHandle and see if the allows the code to
   compile. */

typedef struct LSErrorStruct LSError;

/* The existence of the LSMessage type is first disclosed at line 882
   of LibpurpleAdapter.c */
/* The specific type of LSMessage is not completely known at this
   time. There are no references to fields of a structure in the code,
   and variables of type LSMessage* seem to be always used as opaque
   pointers, but the LSMessageRef function on line 1583 leads us to
   believe that it is a typedef of a struct of some sort which
   contains a reference count. */

typedef struct LSMessageStruct LSMessage;


/* **************************************************/
/* Functions that must be declared in lunaservice.h */
/* **************************************************/

/* The existence of the LSErrorInit function is first disclosed at
   line 686 of LibpurpleAdapter.c */

extern void	LSErrorInit (LSError *);

/* The existence of the LSSubscriptionReply function is first
   disclosed at line 687 of LibpurpleAdapter.c */

extern bool	LSSubscriptionReply (LSHandle *, char *, char *, LSError *);

/* The existence of the LSErrorPrint function is first disclosed at
   line 690 of LibpurpleAdapter.c */

extern void	LSErrorPrint (LSError *, FILE *);

/* The existence of the LSMessageGetPayload function is first disclosed at
   line 884 of LibpurpleAdapter.c */

extern char *	LSMessageGetPayload (LSMessage *);

/* Up to line 992 */
