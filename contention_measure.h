#pragma once

#include <optional>
#include "contention.h"

namespace WaitFreeSimulation
{
    class ContentionMeasure
    {
        public:
            ContentionMeasure();
            std::optional<Contention> detected();
            bool use_slow_path() const;

        private:
            int countContention;
            const int THRESHOLD = 2;
    };
}