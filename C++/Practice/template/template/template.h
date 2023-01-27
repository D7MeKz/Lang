#pragma once

#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include<string>

void print(double arg, const char* args);
template<typename T> void print(T arg);

#endif // !TEMPLATE_H

