cmake_minimum_required (VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

INCLUDE_DIRECTORIES("../glm")
INCLUDE_DIRECTORIES("../Galaxy-Standard/include")

FIND_PACKAGE(CMakeHelper)

PROJECT(Control-System)

SET(libs
	${PROJECT_NAME}
	)

ADD_DEFINITIONS("-DGLM_FORCE_RADIANS")

cmh_static_library()

ADD_SUBDIRECTORY(test)

