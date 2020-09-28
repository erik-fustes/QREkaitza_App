############################################################################
# Centro de Investigaciones Tecnicas de Gipuzkoa (CEIT)                    #
# Paseo de Manuel Lardizabal, N. 15                                        #
# 20018, Donostia - San Sebastian                                          #
# SPAIN                                                                    #
#                                                                          #
# Copyright (c) 2015 by CEIT.                                              #
# All rights reserved.                                                     #
# CEIT provides this product without warranty of any kind and shall        #
# not be liable for any damages caused by the use of this product.         #
############################################################################

cmake_minimum_required(VERSION 2.8.9)


project(QREkaitza_APP)

IF(${WIN32})
	#This is to tell the location of opengl32.lib, glu32.lib and other Windows SDK libraries
	set (CMAKE_LIBRARY_PATH "C:\\Program Files (x86)\\Windows Kits\\8.0\\Lib\\win8\\um\\x64") 
ENDIF()

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(QREkaitza_APP)


