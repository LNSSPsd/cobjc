#pragma once
#include "./cobjc.h"

typedef enum {
	UISceneActivationStateUnattached = -1,
	UISceneActivationStateForegroundActive,
	UISceneActivationStateForegroundInactive,
	UISceneActivationStateBackground
} UISceneActivationState;

UISceneActivationState UISceneGetActivationState(UIScene *);