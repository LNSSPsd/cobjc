#pragma once
#include "./cobjc.h"

DefineObjcMethod(UIView *,UIViewInitWithFrame,initWithFrame:,CGRect);
DefineObjcMethod(void,UIViewSetFrame,setFrame:,CGRect);
DefineObjcMethod(CGRect,UIViewGetFrame,frame);
DefineObjcMethod(BOOL,UIViewIsHidden,isHidden);
DefineObjcMethod(void,UIViewSetHidden,setHidden:,BOOL);
DefineObjcMethod(UIView *,UIViewGetSuperview,superview);
DefineObjcMethod(CFArrayRef,UIViewGetSubviews,subviews);
DefineObjcMethod(void,UIViewAddSubview,addSubview:,UIView*);
DefineObjcMethod(UIWindow*,UIViewGetWindow,window);
DefineObjcMethod(void,UIViewRemoveFromSuperview,removeFromSuperview);
