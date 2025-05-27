#pragma once
#include "./cobjc.h"

typedef enum {
	UIAlertActionStyleDefault = 0,
	UIAlertActionStyleCancel,
	UIAlertActionStyleDestructive
} UIAlertActionStyle;

typedef enum {
	UIAlertControllerStyleActionSheet = 0,
	UIAlertControllerStyleAlert
} UIAlertControllerStyle;

DefineClassMethod(UIAlertController,UIAlertController*,UIAlertControllerCreate,alertControllerWithTitle:message:preferredStyle:,CFStringRef,CFStringRef,UIAlertControllerStyle);
DefineObjcMethod(void,UIAlertControllerAddAction,addAction:,UIAlertAction*);

DefineClassMethod(UIAlertAction,UIAlertAction*,UIAlertActionCreate,actionWithTitle:style:handler:,CFStringRef,UIAlertActionStyle,id);