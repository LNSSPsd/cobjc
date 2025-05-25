#pragma once

#include <objc/objc.h>
#include <objc/runtime.h>
#include <CoreGraphics/CoreGraphics.h>
#include <CoreFoundation/CoreFoundation.h>

#include "./cobjc_types.h"

#define oclass(cls) \
	({Class v;asm("adrp %0,_OBJC_CLASS_$_" #cls "@GOTPAGE \n" \
			"ldr %0,[%0,_OBJC_CLASS_$_" #cls "@GOTPAGEOFF]":"=r"(v));v;})

#define oselector(sel) \
	({SEL v;asm("adrp %0,\"oselector::" #sel "!%=\"@PAGE \n" \
		"ldr %0,[%0,\"oselector::" #sel "!%=\"@PAGEOFF] \n " \
		".section __TEXT,__objc_methname,cstring_literals \n" \
		"\"oselector~meth::" #sel "!%=\": .asciz \"" #sel "\" \n" \
		".section __DATA,__objc_selrefs,literal_pointers,no_dead_strip \n" \
		"\"oselector::" #sel "!%=\": .quad \"oselector~meth::" #sel "!%=\" \n" \
		".section __TEXT,__text,regular,pure_instructions":"=r"(v));v;})

void objc_release(id);
id objc_retain(id);
id objc_alloc(Class);
id objc_alloc_init(Class);
BOOL objc_opt_isKindOfClass(id,Class);
BOOL class_respondsToSelector(Class,SEL);

static const uint64_t _block_descriptor_1arg[2]={0,40};
#define objc_make_block(func,context) \
	({uint64_t blk_content[40]; \
		blk_content[0]=(uint64_t)&_NSConcreteStackBlock; \
		blk_content[1]=0x60000000; \
		blk_content[2]=(uint64_t)func; \
		blk_content[3]=(uint64_t)&_block_descriptor_1arg; \
		blk_content[4]=(uint64_t)context; \
		id blk=object_copy((id)&blk_content,40); \
		blk;})

extern void objc_msgSend();
extern void objc_msgSendSuper();

// Do not use if special types present (e.g. float)
#define _ocall6(send,obj,sel,a1,a2,a3,a4,a5,a6) ((void*(*)(id,SEL,void*,void*,void*,void*,void*,void*))send)((id)obj,oselector(sel),(void*)a1,(void*)a2,(void*)a3,(void*)a4,(void*)a5,(void*)a6)
#define _ocall5(send,obj,sel,a1,a2,a3,a4,a5) ((void*(*)(id,SEL,void*,void*,void*,void*,void*))send)((id)obj,oselector(sel),(void*)a1,(void*)a2,(void*)a3,(void*)a4,(void*)a5)
#define _ocall4(send,obj,sel,a1,a2,a3,a4) ((void*(*)(id,SEL,void*,void*,void*,void*))send)((id)obj,oselector(sel),(void*)a1,(void*)a2,(void*)a3,(void*)a4)
#define _ocall3(send,obj,sel,a1,a2,a3) ((void*(*)(id,SEL,void*,void*,void*))send)((id)obj,oselector(sel),(void*)a1,(void*)a2,(void*)a3)
#define _ocall2(send,obj,sel,a1,a2) ((void*(*)(id,SEL,void*,void*))send)((id)obj,oselector(sel),(void*)a1,(void*)a2)
#define _ocall1(send,obj,sel,a1) ((void*(*)(id,SEL,void*))send)((id)obj,oselector(sel),(void*)a1)
#define _ocall0(send,obj,sel) ((void*(*)(id,SEL))send)((id)obj,oselector(sel))

#define ocall(n,obj,...) _ocall##n(objc_msgSend,obj,__VA_ARGS__)
#define super_call(n,obj,...) \
	({uint64_t refs[2]={(uint64_t)obj,(uint64_t)class_getSuperclass(object_getClass(obj))}; \
		_ocall##n(objc_msgSendSuper,refs,__VA_ARGS__);})

#define DEFINE_CLASS(name, superclass) \
	asm(".section __DATA,__objc_data\n" \
		".globl _OBJC_CLASS_$_" #name "\n" \
		".p2align 3\n" \
		"_OBJC_CLASS_$_" #name ":\n" \
		".quad _OBJC_METACLASS_$_" #name "\n" \
		".quad _OBJC_CLASS_$_" #superclass "\n" \
		".quad __objc_empty_cache\n.quad 0\n" \
		".quad __OBJC_CLASS_RO_$_" #name "\n" \
		"_OBJC_METACLASS_$_" #name ":\n" \
		".quad _OBJC_METACLASS_$_NSObject\n" \
		".quad _OBJC_METACLASS_$_" #superclass "\n" \
		".quad __objc_empty_cache\n.quad 0\n" \
		".quad __OBJC_METACLASS_RO_$_" #name "\n" \
		".section __DATA,__objc_superrefs,regular,no_dead_strip\n" \
		".p2align 3\n" \
		"l_suprefs_" #name ": .quad _OBJC_CLASS_$_" #name "\n" \
		".section __DATA,__objc_classlist,regular,no_dead_strip\n" \
		".p2align 3\nl_objc_label_" #name ": .quad _OBJC_CLASS_$_" #name "\n" \
		".section __DATA,__objc_const\n" \
		"__OBJC_CLASS_RO_$_" #name ":\n" \
		".long 0\n.long 8\n.long 16\n.space 4\n.quad 0\n" \
		".quad l$$classname$$" #name "\n" \
		".quad _instance_methods." #name ".objc\n" \
		".quad 0\n.quad _instance_vars." #name ".objc\n" \
		".quad 0\n.quad 0\n" \
		"__OBJC_METACLASS_RO_$_" #name ":\n" \
		".long 1\n.long 40\n.long 40\n.space 4\n.quad 0\n" \
		".quad l$$classname$$" #name "\n" \
		".quad _class_methods." #name ".objc\n" \
		".quad 0\n.quad 0\n.quad 0\n.quad 0\n" \
		"_instance_vars." #name ".objc:\n" \
		".long 32\n.long 1\n.quad _OBJC_IVAR_$_" #name ".cobjc_struct\n" \
		".quad l_objc_ivar_name_" #name "\n.quad l_objc_ivar_type_" #name "\n.long 3\n.long 8\n" \
		".section __DATA,__objc_ivar\n.globl _OBJC_IVAR_$_" #name ".cobjc_struct\n" \
		".p2align 2\n_OBJC_IVAR_$_" #name ".cobjc_struct:\n.long 8\n" \
		".section __TEXT,__objc_methname,cstring_literals\n" \
		"l_objc_ivar_name_" #name ": .asciz \"cobjc_struct_" #name "\"\n" \
		"l_objc_ivar_type_" #name ": .asciz \"^v\"\n" \
		"l$$classname$$" #name ": .asciz \"" #name "\"\n")

#define DEFINE_CLASS_METHODS(class, count) \
	asm(".section __DATA,__objc_const\n" \
		".p2align 3\n_class_methods." #class ".objc:\n.long 24\n" \
		".long " #count "\n")
// type doesn't really matter I think
#define ADD_METHOD_WITH_TYPE(func,selector,type) \
	asm(".quad l_cls_method_name_" #func "_\n" \
		".quad l_cls_method_type_" #func "_\n"\
		".quad _" #func "\n" \
		".section __TEXT,__objc_methtype,cstring_literals\n"\
		"l_cls_method_type_" #func "_: .asciz \"" #type "\"\n"\
		"l_cls_method_name_" #func "_: .asciz \"" #selector "\"\n"\
		".section __DATA,__objc_const\n")
#define ADD_METHOD(func,selector) ADD_METHOD_WITH_TYPE(func,selector,@@:)
#define DEFINE_INSTANCE_METHODS(class, count) \
	asm(".section __DATA,__objc_const\n" \
		".p2align 3\n_instance_methods." #class ".objc:\n.long 24\n" \
		".long " #count "\n")