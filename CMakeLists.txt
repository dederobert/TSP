cmake_minimum_required(VERSION 3.4)

#Configuration du projet
project(TSP)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

#Inclusion et appel de conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#Generation de la liste des fichiers sources
file(
	GLOB_RECURSE
	source_files
	src/*
)

#Declaration de l'executable
add_executable(
	TSP
	${source_files}
)

#Configuration de l'edition de liens
target_link_libraries(
	TSP
	${CONAN_LIBS}
)