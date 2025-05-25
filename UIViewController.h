#pragma once
#include "./cobjc.h"

void UIViewControllerPresentViewController(UIViewController *self, UIViewController *vc, BOOL animated, id completion);
UIViewController *UIViewControllerGetPresentedViewController(UIViewController *self);