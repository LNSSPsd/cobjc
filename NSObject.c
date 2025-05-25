#include "./NSObject.h"

NSObject *_NSObjectAllocate(Class class) {
	return objc_alloc(class);
}
NSObject *_NSObjectNew(Class class) {
	return objc_alloc_init(class);
}

DefineObjcMethod0(NSObject *,NSObjectInit,init);

NSObject *NSObjectCopy(NSObject *obj) {
	return object_copy(obj,class_getInstanceSize(object_getClass(obj)));
}

NSObject *NSObjectRetain(NSObject *obj) {
	return objc_retain(obj);
}

void NSObjectRelease(NSObject *obj) {
	return objc_release(obj);
}

BOOL _NSObjectIsKindOfClass(NSObject *obj,Class class) {
	return objc_opt_isKindOfClass(obj,class);
}

DefineObjcMethod0(NSObject *,NSObjectAutorelease,autorelease);