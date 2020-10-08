#ifndef _ROUND_H_
#define _ROUND_H_

#include <type_traits>

namespace cs225
{
	template <typename TResult, typename TParameter>
	constexpr TResult round(const TParameter& parameter);
}

#include "Round.hpp"

#endif
