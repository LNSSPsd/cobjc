#pragma once

typedef struct objc_object NSObject;
typedef NSObject UIView;
typedef UIView UIWindow;
typedef NSObject UIViewController;
typedef NSObject UIScene;
typedef UIScene UIWindowScene;
typedef NSObject UIApplication;
typedef UIViewController UIAlertController;
typedef UIViewController UITableViewController;
typedef NSObject UIAlertAction;
typedef UIView UILabel;
typedef UIView UITableView;
typedef UIView UITableViewCell;
typedef NSObject NSIndexPath;
typedef NSObject UIColor;

typedef long NSInteger;

#define DefineMethod0(selftype,selfobj,ret_type,name,sel) ret_type name(selftype) { return ((ret_type(*)(id,SEL))objc_msgSend)(selfobj,oselector(sel)); }
#define DefineMethod1(selftype,selfobj,ret_type,name,sel,type1) ret_type name(selftype type1 a1) { return ((ret_type(*)(id,SEL,type1))objc_msgSend)(selfobj,oselector(sel),a1); }
#define DefineMethod2(selftype,selfobj,ret_type,name,sel,type1,type2) ret_type name(selftype type1 a1,type2 a2) { return ((ret_type(*)(id,SEL,type1,type2))objc_msgSend)(selfobj,oselector(sel),a1,a2); }
#define DefineMethod3(selftype,selfobj,ret_type,name,sel,type1,type2,type3) ret_type name(selftype type1 a1,type2 a2,type3 a3) { return ((ret_type(*)(id,SEL,type1,type2,type3))objc_msgSend)(selfobj,oselector(sel),a1,a2,a3); }
#define DefineMethod4(selftype,selfobj,ret_type,name,sel,type1,type2,type3,type4) ret_type name(selftype type1 a1,type2 a2,type3 a3,type4 a4) { return ((ret_type(*)(id,SEL,type1,type2,type3,type4))objc_msgSend)(selfobj,oselector(sel),a1,a2,a3,a4); }
#define MakeClassMethod(definer,class,...) definer(,(id)oclass(class),__VA_ARGS__)
#define MakeObjcMethod0(definer,...) definer(id self,self,__VA_ARGS__)
#define MakeObjcMethod_COMMA ,
#define MakeObjcMethod(definer,...) definer(id self MakeObjcMethod_COMMA,self,__VA_ARGS__)
#define DefineClassMethod0(cls,...) MakeClassMethod(DefineMethod0,cls,__VA_ARGS__)
#define DefineClassMethod1(cls,...) MakeClassMethod(DefineMethod1,cls,__VA_ARGS__)
#define DefineClassMethod2(cls,...) MakeClassMethod(DefineMethod2,cls,__VA_ARGS__)
#define DefineClassMethod3(cls,...) MakeClassMethod(DefineMethod3,cls,__VA_ARGS__)
#define DefineClassMethod4(cls,...) MakeClassMethod(DefineMethod4,cls,__VA_ARGS__)
#define DefineObjcMethod0(...) MakeObjcMethod0(DefineMethod0,__VA_ARGS__)
#define DefineObjcMethod1(...) MakeObjcMethod(DefineMethod1,__VA_ARGS__)
#define DefineObjcMethod2(...) MakeObjcMethod(DefineMethod2,__VA_ARGS__)
#define DefineObjcMethod3(...) MakeObjcMethod(DefineMethod3,__VA_ARGS__)
#define DefineObjcMethod4(...) MakeObjcMethod(DefineMethod4,__VA_ARGS__)

#include "./NSObject.h"
#include "./UIView.h"
#include "./UIWindow.h"
#include "./UIViewController.h"
#include "./UIApplication.h"
#include "./UIScene.h"
#include "./UIAlertController.h"
#include "./UITableViewController.h"
#include "./NSIndexPath.h"
#include "./UIColor.h"
#include "./UILabel.h"
#include "./UITableView.h"