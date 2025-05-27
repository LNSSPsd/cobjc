#pragma once

#define DEFINE_CLASS(name, superclass, context_length) \
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
		".long 0\n.long 8\n.long " #context_length "\n.space 4\n.quad 0\n" \
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
		".quad l_objc_ivar_name_" #name "\n.quad l_objc_ivar_type_" #name "\n.long 3\n" \
		".long " #context_length "\n" \
		".section __DATA,__objc_ivar\n.globl _OBJC_IVAR_$_" #name ".cobjc_struct\n" \
		".p2align 2\n_OBJC_IVAR_$_" #name ".cobjc_struct:\n" \
		".long 8\n" \
		".section __TEXT,__objc_methname,cstring_literals\n" \
		"l_objc_ivar_name_" #name ": .asciz \"cobjc_struct_" #name "\"\n" \
		"l_objc_ivar_type_" #name ": .asciz \"{unk=?}\"\n" \
		"l$$classname$$" #name ": .asciz \"" #name "\"\n")

#define DEFINE_CLASS_METHODS(class, count) \
	asm(".section __DATA,__objc_const\n" \
		".p2align 3\n_class_methods." #class ".objc:\n.long 24\n" \
		".long " #count "\n")
// type doesn't really matter I think
// Selector is replaced by customized struct ptr
// Ivar is retrieved from class_rw_t dynamically
// bc I can't find a way to reference _OBJC_IVAR_$_classname
// without adding an extra argument to this macro..
// For class methods, x1 (arg2) is untouched and remains to be the selector.
#define ADD_METHOD_WITH_TYPE(func,selector,type) \
	asm(".quad l_cls_method_name_" #func "_\n" \
		".quad l_cls_method_type_" #func "_\n"\
		".quad \"cobjc**_" #func "**\"\n" \
		".section __TEXT,__objc_methtype,cstring_literals\n"\
		"l_cls_method_type_" #func "_: .asciz \"" #type "\"\n"\
		"l_cls_method_name_" #func "_: .asciz \"" #selector "\"\n"\
		".section __TEXT,__text,regular,pure_instructions\n" \
		"\"cobjc**_" #func "**\": \n" \
		"ldr x15,[x0]\n" \
		"add x15,x15,#0x1c\n" \
		"and x15,x15,#4\n" \
		"cbnz x15,Lcobjc_" #func "_j\n"\
		"ldr x1,[x0]\n" \
		"and x1,x1,#0xffffffff8\n" \
		"add x1,x1,#32\n" \
		"ldr x1,[x1]\n" \
		"and x1,x1,#0x7FFFFFFFFFF8\n" \
		"add x1,x1,#8\n" \
		"ldr x1,[x1]\n" \
		"and x1,x1,#0xFFFFFFFFFFFFFFFE\n" \
		"add x1,x1,#8\n" \
		"ldr w1,[x1]\n" \
		"add x1,x1,x0\n" \
		"Lcobjc_" #func "_j:\n" \
		"b _" #func "\n" \
		".section __DATA,__objc_const\n")
#define ADD_METHOD(func,selector) ADD_METHOD_WITH_TYPE(func,selector,@@:)
#define DEFINE_INSTANCE_METHODS(class, count) \
	asm(".section __DATA,__objc_const\n" \
		".p2align 3\n_instance_methods." #class ".objc:\n.long 24\n" \
		".long " #count "\n")

// To be called inside a function
#define COBJC_STRUCT(class,obj) \
	({void *val;asm("adrp x9,_OBJC_IVAR_$_" #class ".cobjc_struct@PAGE\n" \
		"ldrsw x9,[x9,_OBJC_IVAR_$_" #class ".cobjc_struct@PAGEOFF]\n" \
		"add %0,%1,x9":"=r"(val):"r"(obj):"x9");val;})
