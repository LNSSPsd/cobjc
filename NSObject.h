#pragma once
#include "./cobjc.h"

NSObject *_NSObjectAllocate(Class class);
#define NSObjectAllocate(class) _NSObjectAllocate(oclass(class))
NSObject *NSObjectInit(NSObject *obj);
NSObject *_NSObjectNew(Class class);
#define NSObjectNew(class) _NSObjectNew(oclass(class))
NSObject *NSObjectCopy(NSObject *obj);
NSObject *NSObjectRetain(NSObject *obj);
void NSObjectRelease(NSObject *obj);
BOOL _NSObjectIsKindOfClass(NSObject *obj,Class class);
#define NSObjectIsKindOfClass(obj,cls) _NSObjectIsKindOfClass(obj,oclass(cls))
NSObject *NSObjectAutorelease(NSObject *obj);