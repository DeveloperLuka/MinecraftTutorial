#include "main.h"

#include <Windows.h>

bool c_main::attach()
{
	JavaVM* vm;
	JNIEnv* env;

	jsize count;
	if (JNI_GetCreatedJavaVMs(&vm, 1, &count) != JNI_OK || count == 0)
		return false;

	jint res = vm->GetEnv((void**)&env, JNI_VERSION_1_6);
	if (res == JNI_EDETACHED)
		res = vm->AttachCurrentThread((void**)&env, nullptr);

	if (res != JNI_OK)
		return false;

	m.env = env;
	m.vm = vm;

	return true;
}

void c_main::run()
{
	while (true)
	{
		jclass mainClass = m.env->FindClass("ave");

		jmethodID mid = m.env->GetStaticMethodID(mainClass, "A", "()Lave;");
		jobject getMinecraft = m.env->CallStaticObjectMethod(mainClass, mid);

		jfieldID rightClickDelayTimerFid = m.env->GetFieldID(m.env->GetObjectClass(getMinecraft), "ap", "I");
		m.env->SetIntField(getMinecraft, rightClickDelayTimerFid, 0);

		m.env->DeleteLocalRef(mainClass);
		m.env->DeleteLocalRef(getMinecraft);
		Sleep(20);
	}
}