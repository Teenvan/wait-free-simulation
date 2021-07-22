#pragma once

enum class OperationState
{
    PreCas, 
    ExecuteCas,
    PostCas,
    Completed
};