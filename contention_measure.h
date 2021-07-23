#pragma once

namespace WaitFreeSimulation
{
    class ContentionMeasure
    {
        public:
            ContentionMeasure();
            void detected();
            bool use_slow_path() const;

        private:
            int countContention;
            const int THRESHOLD = 2;
    };
}