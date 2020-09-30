############################################################################
# Ekaitza Gazte Taldea                                                     #
# C\ Rentería Nº3 Bajo                                                     #
# 20110, Trintxerpe                                                        #
# SPAIN                                                                    #
############################################################################

cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 14)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Xml)
find_package(Qt5Svg)
find_package(Qt5PrintSupport REQUIRED)
FIND_PACKAGE(Qt5LinguistTools)

# Set the name of the program
set(PROGRAM_NAME QREkaitza_APP)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Define the header and source files of the library. Also for Qt based projects
# define the form and resource files of the project
set(MOC_HEADER_FILES 
	include/mainwindow.h
	)	

set(SOURCE_FILES 
	src/mainwindow.cpp
	src/main.cpp
	)

set(FORM_FILES ui/mainwindow.ui)
set(QTRESOURCE_FILES res/resources.qrc)

# Call Qt tools to wrap headers, forms and resources
qt5_wrap_cpp(HEADERS_MOC ${MOC_HEADER_FILES})
qt5_wrap_ui(FORM_HEADERS ${FORM_FILES})
qt5_add_resources(RESOURCES_RCC ${QTRESOURCE_FILES})

# Organize the source and header files into groups
source_group("Forms" FILES ${FORM_FILES})
source_group("Generated Files\\ui Files" FILES ${FORM_HEADERS})
source_group("Generated Files\\Moc Files" FILES ${HEADERS_MOC})
source_group("Generated Files\\Resource Files" FILES ${RESOURCES_RCC})
source_group("Qt Resource Files" FILES ${QTRESOURCE_FILES})
source_group("Resource Files" FILES ${RESOURCE_FILES})

# Add the executable to the project
add_executable(${PROGRAM_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${MOC_HEADER_FILES} ${FORM_HEADERS} ${HEADERS_MOC} ${RESOURCES_RCC} ${RESOURCE_FILES}) 

# Define the include directory search file for this project
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/include ${QRCODE_INCLUDE_DIR} )

# Define the Qt modules used in this project
target_link_libraries(${PROGRAM_NAME} Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Xml Qt5::Svg  QrCode)