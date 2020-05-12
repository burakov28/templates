cmake_minimum_required(VERSION 3.15)
project(templates)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES main.cpp)
set(HEADERS demangle.h
		simple-template-class.h
		template-specialization.h
		template-functions.h
		using-auto.h
		lambdas.h)

add_executable(templates ${SOURCES} ${HEADERS})
