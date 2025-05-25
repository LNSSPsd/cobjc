#pragma once
#include "./cobjc.h"

UIApplication *UIApplicationSharedApplication();
CFSetRef UIApplicationGetConnectedScenes(UIApplication*);
CFArrayRef UIApplicationGetWindows(UIApplication*);
void UIApplicationOpenURL(UIApplication *self, CFURLRef url, CFDictionaryRef options, id completionHandler);
UIWindow *UIApplicationGetKeyWindow(UIApplication*);