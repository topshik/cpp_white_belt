#include <algorithm>
#include <iostream>
#include <vector>

class FunctionPart {
public:
    FunctionPart(char new_operation, float new_value) {
        operation = new_operation;
        value = new_value;
    }

    float Apply(float operand) const {
        if (operation == '+') {
            return operand + value;
        } else {
            return operand - value;
        }
    }

    void Invert() {
        if (operation == '+') {
            operation = '-';
        } else {
            operation = '+';
        }
    }

private:
    char operation;
    float value;
};

class Function {
public:
    void AddPart(char new_operation, float new_value) {
        func_parts.push_back({new_operation, new_value});
    }

    float Apply(float operand) const {
        for (const FunctionPart& part : func_parts) {
            operand = part.Apply(operand);
        }
        return operand;
    }

    void Invert() {
        for (FunctionPart& part : func_parts) {
            part.Invert();
        }
        std::reverse(func_parts.begin(), func_parts.end());
    }
private:
    std::vector<FunctionPart> func_parts;
};