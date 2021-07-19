#pragma once

namespace WaitFreeSimulation {
    class ContentionMeasure
    {
        public:
            ContentionMeasure();
            void detected();
        private:
            int countContention;
    };
}