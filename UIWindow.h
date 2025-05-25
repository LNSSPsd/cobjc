#pragma once
#include "./cobjc.h"

typedef CGFloat UIWindowLevel;

extern const UIWindowLevel UIWindowLevelNormal;
extern const UIWindowLevel UIWindowLevelAlert;
extern const UIWindowLevel UIWindowLevelStatusBar;

UIWindow *UIWindowInitWithWindowScene(UIWindow *window, UIWindowScene *scene);
UIViewController *UIWindowGetRootViewController(UIWindow *window);
void UIWindowSetRootViewController(UIWindow *window,UIViewController *vc);
UIWindowLevel UIWindowGetWindowLevel(UIWindow *window);
void UIWindowSetWindowLevel(UIWindow *window, UIWindowLevel level);
BOOL UIWindowCanResizeToFitContent(UIWindow *window);
void UIWindowSetCanResizeToFitContent(UIWindow *window, BOOL val);
BOOL UIWindowIsKeyWindow(UIWindow *window);
BOOL UIWindowCanBecomeKeyWindow(UIWindow *window);
void UIWindowMakeKeyAndVisible(UIWindow *window);
void UIWindowMakeKeyWindow(UIWindow *window);
void UIWindowBecomeKeyWindow(UIWindow *window);
void UIWindowResignKeyWindow(UIWindow *window);
UIWindowScene *UIWindowGetWindowScene(UIWindow *window);
