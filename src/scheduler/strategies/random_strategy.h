﻿// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#ifndef RANDOM_STRATEGY_H
#define RANDOM_STRATEGY_H

#include <vector>
#include "random.h"
#include "operations/operation.h"

namespace coyote
{
	class RandomStrategy
	{
	private:
		// The pseudo-random generator.
		Random generator;

		// The seed used by the current iteration.
		size_t iteration_seed;

	public:
		RandomStrategy(size_t seed) noexcept;
		RandomStrategy(RandomStrategy&& strategy) = delete;
		RandomStrategy(RandomStrategy const&) = delete;

		RandomStrategy& operator=(RandomStrategy&& strategy) = delete;
		RandomStrategy& operator=(RandomStrategy const&) = delete;

		// Returns the next operation.
		size_t next_operation(const std::vector<size_t>& operation_ids);

		// Returns the next boolean choice.
		bool next_boolean();

		// Returns the next integer choice.
		int next_integer(int max_value);

		// Returns the seed used in the current iteration.
		size_t seed();

		// Prepares the next iteration.
		void prepare_next_iteration();
	};
}

#endif // RANDOM_STRATEGY_H
