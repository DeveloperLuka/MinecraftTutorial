#pragma once

#include <jni.h>

class c_main
{
public:
	JNIEnv* env;
	JavaVM* vm;

	bool attach();
	void run();
} m;