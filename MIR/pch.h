#ifndef CORE_PCH_H_INCLUDED
#define CORE_PCH_H_INCLUDED

// GLFW Headers
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// GLM Headers
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

// STD lib headers
#include <ostream>
#include <iostream>
#include <sstream>

#include <string>
#include <string_view>
#include <stdexcept>

#include <vector>
#include <set>
#include <array>


// My headers
#include "Core/debug.h"

#endif // CORE_PCH_H_INCLUDED
