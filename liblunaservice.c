/*=============================================================================
 Copyright (C) 2009 WebOS Internals <http://www.webos-internals.org/>
 Copyright (C) 2009 Ryan Hope <rmh3093@gmail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 =============================================================================*/

#include "lunaservice.h"


/* LSError exception style functions */

bool LSErrorInit(LSError *error) {return 0;}
void LSErrorFree(LSError *error) {}

bool LSErrorIsSet(LSError *lserror) {return 0;}

void LSErrorPrint(LSError *lserror, FILE *out) {}


/* Luna Service general functions */

bool LSRegister(const char *name, LSHandle **sh,
                  LSError *lserror) {return 0;}

bool LSRegisterPubPriv(const char *name, LSHandle **sh,
                  bool public_bus,
                  LSError *lserror) {return 0;}

bool LSSetDisconnectHandler(LSHandle *sh, LSDisconnectHandler disconnect_handler,
                    void *user_data, LSError *lserror) {return 0;}

bool LSRegisterCategory(LSHandle *sh, const char *category,
                   LSMethod      *methods,
                   LSSignal      *signals,
                   LSProperty    *properties, LSError *lserror) {return 0;}

bool LSRegisterCategoryAppend(LSHandle *sh, const char *category,
                   LSMethod      *methods,
                   LSSignal      *signals,
                   LSError *lserror) {return 0;}

bool LSCategorySetData(LSHandle *sh, const char *category,
                       void *user_data, LSError *lserror) {return 0;}

bool LSUnregister(LSHandle *service, LSError *lserror) {return 0;}

const char * LSHandleGetName(LSHandle *sh) {return NULL;}


/* Palm Services */

bool LSRegisterPalmService(const char *name,
                  LSPalmService **ret_palm_service,
                  LSError *lserror) {return 0;}

bool LSUnregisterPalmService(LSPalmService *psh, LSError *lserror) {return 0;}

bool LSPalmServiceRegisterCategory(LSPalmService *psh,
    const char *category,
    LSMethod *methods_public, LSMethod *methods_private,
    LSSignal *signals, void *category_user_data, LSError *lserror) {return 0;}

LSHandle * LSPalmServiceGetPrivateConnection(LSPalmService *psh) {return NULL;}
LSHandle * LSPalmServiceGetPublicConnection(LSPalmService *psh) {return NULL;}


/* LSMessage (Luna Service Message) functions */

LSHandle * LSMessageGetConnection(LSMessage *message) {return NULL;}
bool LSMessageIsPublic(LSPalmService *psh, LSMessage *message) {return 0;}

void LSMessageRef(LSMessage *message) {}
void LSMessageUnref(LSMessage *message) {}

bool LSMessagePrint(LSMessage *lmsg, FILE *out) {return 0;}

const char * LSMessageGetUniqueToken(LSMessage *message) {return NULL;}
const char * LSMessageGetKind(LSMessage *message) {return NULL;}

const char * LSMessageGetApplicationID(LSMessage *message) {return NULL;}

const char * LSMessageGetSender(LSMessage *message) {return NULL;}
const char * LSMessageGetCategory(LSMessage *message) {return NULL;}
const char * LSMessageGetMethod(LSMessage *message) {return NULL;}

const char * LSMessageGetPayload(LSMessage *message) {return NULL;}

json_t * LSMessageGetPayloadJSON(LSMessage  *message) {return NULL;}

bool LSMessageIsSubscription(LSMessage *lsmgs) {return 0;}

LSMessageToken LSMessageGetToken(LSMessage *call) {return 0;}
LSMessageToken LSMessageGetResponseToken(LSMessage *reply) {return 0;}

bool LSMessageRespond(LSMessage *message, const char *reply_payload,
                LSError *lserror) {return 0;}

bool LSMessageReply(LSHandle *sh, LSMessage *lsmsg, const char *replyPayload,
                LSError *lserror) {return 0;}

bool LSMessageReturn(LSHandle *sh, LSMessage *message, const char *replyPayload,
                LSError *error) {return 0;}


/* Mainloop integration functions. */

bool LSGmainAttach(LSHandle *sh, GMainLoop *mainLoop, LSError *lserror) {return 0;}

bool LSGmainAttachPalmService(LSPalmService *psh,
                           GMainLoop *mainLoop, LSError *lserror) {return 0;}

bool LSGmainSetPriority(LSHandle *sh, int priority, LSError *lserror) {return 0;}

bool LSGmainSetPriorityPalmService(LSPalmService *psh, int priority, LSError *lserror) {return 0;}


/* Luna Service Subscription functions */

bool LSCall(LSHandle *sh, const char *uri, const char *payload,
       LSFilterFunc callback, void *user_data,
       LSMessageToken *ret_token, LSError *lserror) {return 0;}

bool LSCallOneReply(LSHandle *sh, const char *uri, const char *payload,
       LSFilterFunc callback, void *ctx,
       LSMessageToken *ret_token, LSError *lserror) {return 0;}

bool LSCallFromApplication(LSHandle *sh, const char *uri, const char *payload,
       const char *applicationID,
       LSFilterFunc callback, void *ctx,
       LSMessageToken *ret_token, LSError *lserror) {return 0;}

bool LSCallFromApplicationOneReply(
       LSHandle *sh, const char *uri, const char *payload,
       const char *applicationID,
       LSFilterFunc callback, void *ctx,
       LSMessageToken *ret_token, LSError *lserror) {return 0;}

bool LSCallCancel(LSHandle *sh, LSMessageToken token, LSError *lserror) {return 0;}


/* Luna Service Client functions */

bool LSSubscriptionProcess (LSHandle *sh, LSMessage *message, bool *subscribed,
                LSError *lserror) {return 0;}

bool LSSubscriptionSetCancelFunction(LSHandle *sh,
                                LSFilterFunc cancelFunction,
                                void *ctx, LSError *lserror) {return 0;}

bool LSSubscriptionAdd(LSHandle *sh, const char *key,
                  LSMessage *message, LSError *lserror) {return 0;}

bool LSSubscriptionAcquire(LSHandle *sh, const char *key,
                  LSSubscriptionIter **ret_iter, LSError *lserror) {return 0;}

void LSSubscriptionRelease(LSSubscriptionIter *iter) {}

bool LSSubscriptionHasNext(LSSubscriptionIter *iter) {return 0;}

LSMessage *LSSubscriptionNext(LSSubscriptionIter *iter) {return NULL;}

void LSSubscriptionRemove(LSSubscriptionIter *iter) {}

bool LSSubscriptionReply(LSHandle *sh, const char *key,
                    const char *payload, LSError *lserror) {return 0;}

bool LSSubscriptionRespond(LSPalmService *psh, const char *key,
                      const char *payload, LSError *lserror) {return 0;}

bool LSSubscriptionPost(LSHandle *sh, const char *category,
        const char *method,
        const char *payload, LSError *lserror) {return 0;}



/* Luna Service Signal functions */

bool LSSignalSend(LSHandle *sh, const char *uri, const char *payload,
             LSError *lserror) {return 0;}

bool LSSignalSendNoTypecheck(LSHandle *sh,
            const char *uri, const char *payload, LSError *lserror) {return 0;}

bool LSSignalCall(LSHandle *sh,
         const char *category, const char *methodName,
         LSFilterFunc filterFunc, void *ctx,
         LSMessageToken *ret_token,
         LSError *lserror) {return 0;}

bool LSSignalCallCancel(LSHandle *sh, LSMessageToken token, LSError *lserror) {return 0;}


bool LSRegisterServerStatus(LSHandle *sh, const char *serviceName,
              LSServerStatusFunc func, void *ctx, LSError *lserror) {return 0;}
