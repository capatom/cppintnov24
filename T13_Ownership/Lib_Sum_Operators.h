#pragma once

namespace sum_Operators {
	template<typename T>
	T operator +(T lhs, const T& rhs) { return lhs += rhs; }
	
	template<typename T>
	T operator -(T lhs, const T& rhs) { return lhs -= rhs; }

	template<typename T>
	T& operator ++(T& lhs) { return lhs += 1; }

	template<typename T>
	T operator ++(T& lhs, int) { const T copy{ lhs }; ++lhs; return copy; }

	template<typename T>
	T& operator --(T& lhs) { return lhs -= 1; }

	template<typename T>
	T operator --(T& lhs, int) { const T copy{ lhs }; --lhs; return copy; }

	template<typename T, typename N>
	T operator +(T lhs, N rhs) { return lhs += rhs; }

	template<typename T, typename N>
	T operator -(T lhs, N rhs) { return lhs -= rhs; }
}