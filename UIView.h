#pragma once
#include "./cobjc.h"

UIView *UIViewInitWithFrame(UIView *view,CGRect frame);
void UIViewSetFrame(UIView *view,CGRect frame);
CGRect UIViewGetFrame(UIView *view);
BOOL UIViewIsHidden(UIView *view);
void UIViewSetHidden(UIView *view, BOOL hidden);
UIView *UIViewGetSuperview(UIView *view);
CFArrayRef UIViewGetSubviews(UIView *view);
void UIViewAddSubview(UIView *view, UIView *subview);
UIWindow *UIViewGetWindow(UIView *view);
void UIViewRemoveFromSuperview(UIView *view);