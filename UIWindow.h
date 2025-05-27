#pragma once
#include "./cobjc.h"

typedef CGFloat UIWindowLevel;

extern const UIWindowLevel UIWindowLevelNormal;
extern const UIWindowLevel UIWindowLevelAlert;
extern const UIWindowLevel UIWindowLevelStatusBar;

DefineObjcMethod(UIWindow*,UIWindowInitWithWindowScene,initWithWindowScene:,UIWindowScene*);
DefineObjcMethod(UIViewController *,UIWindowGetRootViewController,rootViewController);
DefineObjcMethod(void,UIWindowSetRootViewController,setRootViewController:,UIViewController*);
DefineObjcMethod(UIWindowLevel,UIWindowGetWindowLevel,windowLevel);
DefineObjcMethod(void,UIWindowSetWindowLevel,setWindowLevel:,UIWindowLevel);
DefineObjcMethod(BOOL,UIWindowCanResizeToFitContent,canResizeToFitContent);
DefineObjcMethod(void,UIWindowSetCanResizeToFitContent,setCanResizeToFitContent:,BOOL);
DefineObjcMethod(BOOL,UIWindowIsKeyWindow,isKeyWindow);
DefineObjcMethod(BOOL,UIWindowCanBecomeKeyWindow,canBecomeKeyWindow);
DefineObjcMethod(void,UIWindowMakeKeyAndVisible,makeKeyAndVisible);
DefineObjcMethod(void,UIWindowMakeKeyWindow,makeKeyWindow);
DefineObjcMethod(void,UIWindowBecomeKeyWindow,becomeKeyWindow);
DefineObjcMethod(void,UIWindowResignKeyWindow,resignKeyWindow);
DefineObjcMethod(UIWindowScene*,UIWindowGetWindowScene,windowScene);
