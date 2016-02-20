#ifndef _TYPETRAITS_H_
#define _TYPETRAITS_H_

namespace CuteSTL
{
	struct _true_type {};
	struct _false_type {};

	//萃取传入的T类型的类型特性
	template<class T>
	struct _type_traits
	{
		typedef _false_type has_trivial_default_constructor;
		typedef _false_type has_trivial_copy_constructor;
		typedef _false_type has_trivial_assignment_operator;
		typedef _false_type has_trivial_destructor;
		typedef _false_type is_POD_type;
	};

	template<>
	struct _type_traits<bool>
	{
		typedef _true_type has_trivial_default_constructor;
		typedef _true_type has_trivial_copy_constructor;
		typedef _true_type has_trivial_assignment_operator;
		typedef _true_type has_trivial_destructor;
		typedef _true_type is_POD_type;
	};

	template<>
	struct _type_traits<char>
	{
		typedef _true_type has_trivial_default_constructor;
		typedef _true_type has_trivial_copy_constructor;
		typedef _true_type has_trivial_assignment_operator;
		typedef _true_type has_trivial_destructor;
		typedef _true_type is_POD_type;
	};
}

#endif // !_TYPETRAITS_H_

