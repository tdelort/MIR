#pragma once

namespace mir
{
	template<typename DERIVED>
	class singleton
	{
		singleton();
	public:
		singleton(const singleton&) = delete;
		singleton(singleton&&) = delete;
		singleton& operator=(const singleton&) = delete;
		singleton& operator=(singleton&&) = delete;

		static auto& instance()
		{
			static T instance;
			return instance;
		}
	};

}
