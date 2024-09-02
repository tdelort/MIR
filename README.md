# Veer Engine

Renaming in progress from MIR to Veer. Old name didn't have a meaning really close to what this project is apart from the "modular" part of a space station (and yet, this is not the main purpose of the project))

## Description  

Game Engine made to learn about as many things as possible about game engines.  

## Tasks

Todo before v0 :

[ ] Rename MIR/mir occurences to veer/vee
[ ] Rework vec.h lib to avoid template specialisation (i could just specialize needed functions instead of the whole class to avoid boilerplate)
[ ] Remove platform specific code from application.cpp

Todo in v0.1

[ ] Add GPU resources types
[ ] Draw triangle in GBuffer
[ ] Add parser to load GPU resources from files
[ ] Draw textured mesh in GBuffer

Todo in v0.2

[ ] Put gameplay code into app project
[ ] Add input system

Unsorted :  

[ ] Switch building pipeline to CMake (to be able to ditch VisualStudio)
[ ] Add Vulkan support
[ ] Think about where to put the boundary between app and engine (should the job system, service init, and main render loop be in the engine or left as tools for the app to compose with ? Freedom / boilerplate)

