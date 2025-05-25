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

UIAlertController *UIAlertControllerCreate(CFStringRef,CFStringRef,UIAlertControllerStyle);
void UIAlertControllerAddAction(UIAlertController *,UIAlertAction *);

UIAlertAction *UIAlertActionCreate(CFStringRef,UIAlertActionStyle,id);