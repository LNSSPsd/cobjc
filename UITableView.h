#pragma once
#include "./cobjc.h"

DefineObjcMethod(void,UITableViewDeselectRow,deselectRowAtIndexPath:animated:,NSIndexPath*,BOOL);
DefineObjcMethod(void,UITableViewReloadData,reloadData);

DefineObjcMethod(UILabel*,UITableViewCellGetTextLabel,textLabel);