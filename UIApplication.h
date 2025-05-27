#pragma once
#include "./cobjc.h"

DefineClassMethod(UIApplication,UIApplication*,UIApplicationSharedApplication,sharedApplication);

DefineObjcMethod(CFSetRef,UIApplicationGetConnectedScenes,connectedScenes);
DefineObjcMethod(CFArrayRef,UIApplicationGetWindows,windows);
DefineObjcMethod(void,UIApplicationOpenURL,openURL:options:completionHandler:,CFURLRef,CFDictionaryRef,id);
DefineObjcMethod(UIWindow*,UIApplicationGetKeyWindow,keyWindow);
