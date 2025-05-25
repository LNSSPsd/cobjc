#include "./UIView.h"

DefineObjcMethod1(UIView *,UIViewInitWithFrame,initWithFrame:,CGRect);
DefineObjcMethod1(void,UIViewSetFrame,setFrame:,CGRect);
DefineObjcMethod0(CGRect,UIViewGetFrame,frame);
DefineObjcMethod0(BOOL,UIViewIsHidden,isHidden);
DefineObjcMethod1(void,UIViewSetHidden,setHidden:,BOOL);
DefineObjcMethod0(UIView *,UIViewGetSuperview,superview);
DefineObjcMethod0(CFArrayRef,UIViewGetSubviews,subviews);
DefineObjcMethod1(void,UIViewAddSubview,addSubview:,UIView*);
DefineObjcMethod0(UIWindow*,UIViewGetWindow,window);
DefineObjcMethod0(void,UIViewRemoveFromSuperview,removeFromSuperview);
