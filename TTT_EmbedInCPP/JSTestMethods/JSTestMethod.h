#pragma once

#include <duktape.h>
#include <iostream>
#include <string>

class JSTestMethod
{
	public:
		virtual void Run(duk_context* duk) = 0;
};

