#pragma once

namespace mir
{
	template<typename T>
	class basic_allocator
	{
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;


		// TODO implement Allocator concept
	};
}