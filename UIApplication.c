#include "./UIApplication.h"


DefineClassMethod0(UIApplication,UIApplication*,UIApplicationSharedApplication,sharedApplication);
DefineObjcMethod0(CFSetRef,UIApplicationGetConnectedScenes,connectedScenes);
DefineObjcMethod0(CFArrayRef,UIApplicationGetWindows,windows);
DefineObjcMethod3(void,UIApplicationOpenURL,openURL:options:completionHandler:,CFURLRef,CFDictionaryRef,id);
DefineObjcMethod0(UIWindow*,UIApplicationGetKeyWindow,keyWindow);