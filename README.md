# MIR

## Description  

Game Engine made to learn about as many things as possible about game engines.  

## Tasks

Todo before v0 :

[ ] Rework vec.h lib to avoid template specialisation (i could just specialize needed functions instead of the whole class to avoid boilerplate)
[ ] Remove platform specific code from application.cpp

Unsorted :  

[ ] Switch building pipeline (use SCons or CMake) (to be able to ditch VisualStudio)

[ ] Think about where to put the boundary between app and engine (should the job system, service init, and main render loop be in the engine or left as tools for the app to compose with ? Freedom / boilerplate)

