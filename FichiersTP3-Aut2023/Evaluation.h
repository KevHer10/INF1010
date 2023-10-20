#pragma once
class Evaluation{
public:
    virtual float obtenirEvaluation() const = 0;
    virtual ~Evaluation() = default;
};