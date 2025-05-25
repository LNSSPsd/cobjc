#include "./UIAlertController.h"

DefineClassMethod3(UIAlertController,UIAlertController*,UIAlertControllerCreate,alertControllerWithTitle:message:preferredStyle:,CFStringRef,CFStringRef,UIAlertControllerStyle);
DefineObjcMethod1(void,UIAlertControllerAddAction,addAction:,UIAlertAction*);
DefineClassMethod3(UIAlertAction,UIAlertAction*,UIAlertActionCreate,actionWithTitle:style:handler:,CFStringRef,UIAlertActionStyle,id);