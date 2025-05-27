#pragma once
#include "./cobjc.h"

static inline NSObject *_NSObjectAllocate(Class class) {
	return objc_alloc(class);
}

#define NSObjectAllocate(class) _NSObjectAllocate(oclass(class))

DefineObjcMethod(NSObject *,NSObjectInit,init);

static inline NSObject *_NSObjectNew(Class class) {
	return objc_alloc_init(class);
}

#define NSObjectNew(class) _NSObjectNew(oclass(class))

static inline NSObject *NSObjectCopy(NSObject *obj) {
	return object_copy(obj,class_getInstanceSize(object_getClass(obj)));
}

static inline BOOL _NSObjectIsKindOfClass(NSObject *obj,Class class) {
	return objc_opt_isKindOfClass(obj,class);
}

#define NSObjectIsKindOfClass(obj,cls) _NSObjectIsKindOfClass(obj,oclass(cls))

static inline NSObject *NSObjectRetain(NSObject *obj) {
	if(!obj)
		return NULL;
	return (NSObject *)CFRetain((CFTypeRef)obj);
}

static inline void NSObjectRelease(NSObject *obj) {
	if(obj)
		CFRelease((CFTypeRef)obj);
}

static inline NSObject *NSObjectAutorelease(NSObject *obj) {
	if(!obj)
		return NULL;
	return (NSObject *)CFAutorelease((CFTypeRef)obj);
}
