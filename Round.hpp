#include "Round.h"

namespace cs225
{
	template <typename TResult, typename TParameter>
	constexpr TResult round(const TParameter& parameter)
	{
		if constexpr (
			(!std::is_arithmetic<TResult>::value) ||
			(!std::is_arithmetic<TParameter>::value) ||
			(!std::is_integral<TResult>::value)
		)
		{
			return static_cast<TResult>(parameter);
		}
		else
		{
			const long double offset = (parameter > 0)
				? 0.5L
				: -0.5L;
			const TResult resultOffset = static_cast<TResult>(offset);
			const long double value = static_cast<long double>(parameter);
			return static_cast<TResult>(
				static_cast<TResult>(value + offset) - resultOffset
			);
		}
	}
}
