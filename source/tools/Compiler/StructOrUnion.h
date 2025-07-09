#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <optional>

namespace WadeSpace {
	typedef enum {NONE5,STRUCT1,UNION1} StuctureType;

	class StructOrUnion
	{
	public:
		StructOrUnion(StuctureType type);
		StructOrUnion();
		~StructOrUnion();
	private:
		StuctureType type;
	};
}
