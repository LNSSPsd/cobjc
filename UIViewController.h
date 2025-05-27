#pragma once
#include "./cobjc.h"

DefineObjcMethod(void,UIViewControllerPresentViewController,presentViewController:animated:completion:,UIViewController*,BOOL,id);
DefineObjcMethod(UIViewController*,UIViewControllerGetPresentedViewController,presentedViewController);